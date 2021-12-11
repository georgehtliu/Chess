#include "rook.h"

Rook::Rook(bool white) {
    this->white = white;
}

bool Rook::get_has_moved() {
    return has_moved;
}

bool Rook::valid_move(Move mv) {
    return mv.is_vertical() || mv.is_horizontal();
}