/*
    spot.cc
    David Gurevich
    CS 246
*/

#include "spot.h"

Spot::Spot(int x, int y) : p{nullptr}, x{x}, y{y}, white{(x + y) % 2 == 0} {}

int Spot::get_x() const {
    return x;
}

int Spot::get_y() const {
    return y;
}

bool Spot::is_white() const {
    return white;
}

char Spot::get_spot_text() const {
    if (this->p) {
        return p->get_text();
    }

    return ' ';
}

void Spot::set_piece(Piece *p) {
    this->p = p;
}

void Spot::remove_piece() {
    this->p = nullptr;
}

Piece *Spot::get_piece() {
    return this->p;
}



