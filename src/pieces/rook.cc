#include "rook.h"

Rook::Rook(bool white) {
    this->white = white;
    if (white) {
        text_repr = 'R';
        white_square = "assets/pieces/rook_w_bg_w.png";
        black_square = "assets/pieces/rook_w_bg_b.png";
    } else {
        text_repr = 'r';
        white_square = "assets/pieces/rook_b_bg_w.png";
        black_square = "assets/pieces/rook_b_bg_b.png";
    }
}

bool Rook::get_has_moved() {
    return has_moved;
}

bool Rook::valid_path(Move mv) {
    return mv.is_vertical() || mv.is_horizontal();
}