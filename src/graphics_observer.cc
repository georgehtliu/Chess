/*
    graphics_observer.cc
    David Gurevich
    CS 246
*/

#include "graphics_observer.h"

GraphicsObserver::GraphicsObserver(Board *board) : subject{board} {

    subject->attach(this);
    w = std::make_unique<Xwindow>(GraphicsObserver::HEIGHT * Board::ROWS, GraphicsObserver::WIDTH * Board::COLS);
    printf("Default Depth: %d\n", DefaultDepth(w->get_display(), 0));
}

GraphicsObserver::~GraphicsObserver() {
    w.reset();
    subject->detach(this);
}

void GraphicsObserver::notify() {
    for (int i = 0; i < Board::ROWS; i++) {
        for (int j = 0; j < Board::COLS; j++) {
            Spot *s = subject->get_spot(i, j);
            notify(s);
        }
    }
}

void GraphicsObserver::notify(Spot *s) {
    int window_x = s->get_x() * GraphicsObserver::WIDTH;
    int window_y = s->get_y() * GraphicsObserver::HEIGHT;

    int colour = (s->is_white()) ? GraphicsObserver::WHITE_COL : GraphicsObserver::BLACK_COL;
    w->fillRectangle(window_x, window_y, GraphicsObserver::WIDTH, GraphicsObserver::HEIGHT, colour);


    if (s->get_piece()) {
        XImage *img;

        if (s->is_white()) {
            img = load_image(s->get_piece()->get_white_square_img(), w.get());
        } else {
            img = load_image(s->get_piece()->get_black_square_img(), w.get());
        }

        w->drawImage(window_x, window_y, img);
    }

}

void GraphicsObserver::notify(Move *m) {
    notify(m->start_pos);
    notify(m->end_pos);
}
