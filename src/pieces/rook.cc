#include "rook.h"

Rook::Rook(bool white) {
    this->white = white;
    if (white) {
        this->text_repr = 'R';
    } else {
        this->text_repr = 'r';
    }
}

bool Rook::get_has_moved() {
    return has_moved;
}

bool Rook::valid_path(Move mv) {
    return mv.is_vertical() || mv.is_horizontal();
}