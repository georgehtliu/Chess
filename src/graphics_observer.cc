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
            int colour = Xwindow::Black;
            if (subject->get_spot(i, j)->is_white()) {
               colour = Xwindow::Red; 
            }

            int window_x = GraphicsObserver::WIDTH * j;
            int window_y = GraphicsObserver::HEIGHT * i;

            w->fillRectangle(window_x, window_y, GraphicsObserver::WIDTH, GraphicsObserver::HEIGHT, colour);
        }
    }
}