/*
    spot.cc
    David Gurevich
    CS 246
*/

#include "spot.h"

Spot::Spot(int x, int y) : x{x}, y{y}, white{(x + y) % 2 == 0} {}

int Spot::get_x() const {
    return x;
}

int Spot::get_y() const {
    return y;
}

bool Spot::is_white() const {
    return white;
}
