#include "text_observer.h"

#include <iostream>

TextObserver::TextObserver(Board *board) : subject{board} {
    subject->attach(this);
}

TextObserver::~TextObserver() {
    subject->detach(this);
}

void TextObserver::notify() {
    for (int i = 0; i < Board::ROWS; i++) {
        std::cout << Board::ROWS - i << " ";
        for (int j = 0; j < Board::COLS; j++) {
            if (subject->get_spot(j, i)->get_piece()) {
                std::cout << subject->get_spot(j, i)->get_spot_text();
                continue;
            }
            if (subject->get_spot(j, i)->is_white()) {
               std::cout << " ";
            } else {
                std::cout << "-";
            }
        }
        std::endl (std::cout);
    }
    std::endl (std::cout);
    std::cout << "  abcdefgh" << std::endl;
}

void TextObserver::notify(__attribute__((unused)) Spot &s) {
    this->notify();
}
