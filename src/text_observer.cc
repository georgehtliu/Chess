#include "text_observer.h"

#include <iostream>

TextObserver::TextObserver(Board *board) : subject{board} {
    subject->attach(this);
}

TextObserver::~TextObserver() {
    subject->detach(this);
}

void TextObserver::notify() {
    std::cout << "   A      B      C      D      E      F      G      H\n\n";
    for (int i = Board::ROWS - 1; i >= 0; i--) {
        for (int m = 0; m < 3; m++) {
            for (int j = 0; j < Board::COLS; j++) {
                Spot *s = subject->get_spot(j, i);

                if (s->is_white()) {
                    if (s->get_piece() && m == 1) {
                        for (int n = 0; n < 2; n++)
                            std::cout << "\u2588";
                        std::cout << " " << s->get_piece()->get_text() << " ";
                        for (int n = 0; n < 2; n++)
                            std::cout << "\u2588";
                    } else {
                        for (int n = 0; n < 7; n++)
                            std::cout << "\u2588";
                    }
                } else {
                    if (s->get_piece() && m == 1) {

                        for (int n = 0; n < 3; n++)
                            std::cout << " ";
                        std::cout << s->get_piece()->get_text();
                        for (int n = 0; n < 3; n++)
                            std::cout << " ";
                    } else {
                        for (int n = 0; n < 7; n++)
                            std::cout << " ";
                    }
                }
            }
            if (m == 1) {
                std::cout << "  " << i + 1;
            }
            std::cout << std::endl;
        }
    }
}

void TextObserver::notify(Spot *s) {
    (void) s;
    notify();
}

void TextObserver::notify(Move *m) {
    (void) m;
    notify();
}