#ifndef CHESS_INCLUDE_WINDOW_H_
#define CHESS_INCLUDE_WINDOW_H_
#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include <iostream>
#include <string>

class Xwindow {
    Display *d;
    Window w;
    Visual *v;
    int s;
    GC gc;
    unsigned long colours[10];

   public:
    Xwindow(int width = 500,
            int height = 500);  // Constructor; displays the window.
    ~Xwindow();                 // Destructor; destroys the window.
    Xwindow(const Xwindow &) = delete;
    Xwindow &operator=(const Xwindow &) = delete;

    // Available colours.
    enum {
        White = 0,
        Black,
        Red,
        Green,
        Blue,
        Cyan,
        Yellow,
        Magenta,
        Orange,
        Brown
    };

    Display* get_display();
    Window get_window();
    Visual* get_visual();

    // Draws a rectangle
    void fillRectangle(int x, int y, int width, int height, int colour = Black);

    // Draw an image
    void drawImage(int x, int y, XImage *img);


    // Draws a string
    void drawString(int x, int y, std::string msg);
};

#endif // CHESS_INCLUDE_WINDOW_H_
