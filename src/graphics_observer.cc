/*
    graphics_observer.cc
    David Gurevich
    CS 246
*/

#include "graphics_observer.h"

GraphicsObserver::GraphicsObserver(Board *board) : subject{board} {
    subject->attach(this);
    w = std::make_unique<Xwindow>(GraphicsObserver::HEIGHT * Board::ROWS, GraphicsObserver::WIDTH * Board::COLS);
}

GraphicsObserver::~GraphicsObserver() {
    w.reset();
    subject->detach(this);
}

void GraphicsObserver::notify() {
    for (int i = 0; i < Board::ROWS; i++) {
        for (int j = 0; j < Board::COLS; j++) {
            int colour = (subject->get_spot(i, j)->is_white()) ? GraphicsObserver::WHITE_COL : GraphicsObserver::BLACK_COL;

            int window_x = GraphicsObserver::WIDTH * j;
            int window_y = GraphicsObserver::HEIGHT * i;

            w->fillRectangle(window_x, window_y, GraphicsObserver::WIDTH, GraphicsObserver::HEIGHT, colour);
        }
    }
}

void GraphicsObserver::notify(Spot &s) {
    int window_x = s.get_x() * GraphicsObserver::WIDTH;
    int window_y = s.get_y() * GraphicsObserver::HEIGHT;

    int colour = (s.is_white()) ? GraphicsObserver::WHITE_COL : GraphicsObserver::BLACK_COL;
    w->fillRectangle(window_x, window_y, GraphicsObserver::WIDTH, GraphicsObserver::HEIGHT, colour);

    /*
    if (s->get_piece()) {
        unsigned char* rgb_image = s->get_piece()->get_image();

        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                unsigned char grey = rgb_image[(100 * i) + j];

                if (grey != 0) {
                    w->fillRectangle(window_x + j, window_y + i, 1, 1, GraphicsObserver::BLACK_COL);
                }
            }
        }
    }
    */

}
