#include "window.h"

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <unistd.h>

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

Xwindow::Xwindow(int width, int height) {
    d = XOpenDisplay(NULL);
    if (d == NULL) {
        cerr << "Cannot open display" << endl;
        exit(1);
    }
    s = DefaultScreen(d);
    w = XCreateSimpleWindow(d, RootWindow(d, s), 10, 10, width, height, 1,
                            BlackPixel(d, s), WhitePixel(d, s));
    v = DefaultVisual(d, s);
    XSelectInput(d, w, ExposureMask | KeyPressMask);
    XMapRaised(d, w);

    Pixmap pix =
            XCreatePixmap(d, w, width, height, DefaultDepth(d, DefaultScreen(d)));
    gc = XCreateGC(d, pix, 0, (XGCValues *) 0);

    XFlush(d);
    XFlush(d);

    // Set up class name. I need this because I use i3wm, which stretches
    // windows at it's own will. If I want to open this window as a floating
    // window every time, I need to set its class name, and then address that
    // class in my i3wm config file.
    XClassHint hint;
    hint.res_class = (char *) "cs246";
    hint.res_name = (char *) "cs246";
    XSetClassHint(d, w, &hint);

    // Set up colours.
    XColor xcolour;
    Colormap cmap;
    char color_vals[10][20] = {"white", "black", "red", "papaya whip", "blue",
                               "cyan", "yellow", "seashell", "orange", "olive"};

    cmap = DefaultColormap(d, DefaultScreen(d));
    for (int i = 0; i < 10; ++i) {
        XParseColor(d, cmap, color_vals[i], &xcolour);
        XAllocColor(d, cmap, &xcolour);
        colours[i] = xcolour.pixel;
    }

    XSetForeground(d, gc, colours[Black]);

    // Make window non-resizeable.
    XSizeHints hints;
    hints.flags = (USPosition | PSize | PMinSize | PMaxSize);
    hints.height = hints.base_height = hints.min_height = hints.max_height =
            height;
    hints.width = hints.base_width = hints.min_width = hints.max_width = width;
    XSetNormalHints(d, w, &hints);

    XSynchronize(d, True);

    usleep(1000);
}

Xwindow::~Xwindow() {
    XFreeGC(d, gc);
    XCloseDisplay(d);
}

Display *Xwindow::get_display() {
    return d;
}

Window Xwindow::get_window() {
    return w;
}

Visual *Xwindow::get_visual() {
    return v;
}

void Xwindow::fillRectangle(int x, int y, int width, int height, int colour) {
    XSetForeground(d, gc, colours[colour]);
    XFillRectangle(d, w, gc, x, y, width, height);
    XSetForeground(d, gc, colours[Black]);
}

void Xwindow::drawImage(int x, int y, XImage *img) {
    XPutImage(d, w, gc, img, 0, 0, x, y, img->width, img->height);
}

void Xwindow::drawString(int x, int y, string msg) {
    XSetForeground(d, gc, colours[White]);
    XDrawString(d, w, DefaultGC(d, s), x, y, msg.c_str(), msg.length());
    XSetForeground(d, gc, colours[Black]);
}



