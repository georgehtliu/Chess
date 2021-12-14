/*
    graphics_observer.cc
    David Gurevich
    CS 246
*/

#include "graphics_observer.h"

GraphicsObserver::GraphicsObserver(Board *board) : subject{board} {
    subject->attach(this);

    int width = GraphicsObserver::WIDTH * Board::COLS + GraphicsObserver::BOARD_OFFSET * 2;
    int height = GraphicsObserver::HEIGHT * Board::ROWS + GraphicsObserver::BOARD_OFFSET * 2;
    w = std::make_unique<Xwindow>(width, height);
    w->fillRectangle(0, 0, width, height, 7);
    w->fillRectangle((0.9 * BOARD_OFFSET), (0.9 * BOARD_OFFSET), width - (1.8 * BOARD_OFFSET), height - (1.8 * BOARD_OFFSET));
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

    for (int j = 0; j < Board::COLS; j++) {
        w->drawString(((j + 0.45) * WIDTH) + BOARD_OFFSET,
                      HEIGHT * Board::ROWS + (1.55 * BOARD_OFFSET),
                      std::string(1, (char)('a' + j)));
    }

    for (int i = 0; i < Board::ROWS; i++) {
        w->drawString(WIDTH * Board::COLS + (1.5 * BOARD_OFFSET),
                      ((i + 0.5) * HEIGHT) + BOARD_OFFSET,
                      std::to_string( 8 - i));
    }
}

void GraphicsObserver::notify(Spot *s) {
    int window_x = s->get_x() * GraphicsObserver::WIDTH + GraphicsObserver::BOARD_OFFSET;
    int window_y = (7 - s->get_y()) * GraphicsObserver::HEIGHT + GraphicsObserver::BOARD_OFFSET;

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
