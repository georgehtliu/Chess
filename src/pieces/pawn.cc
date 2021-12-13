#include "pawn.h"

Pawn::Pawn(bool white) {
    this->white = white;
    if (white) {
        text_repr = 'P';
        white_square = "assets/pieces/pawn_w_bg_w.png";
        black_square = "assets/pieces/pawn_w_bg_b.png";
    } else {
        text_repr = 'p';
        white_square = "assets/pieces/pawn_b_bg_w.png";
        black_square = "assets/pieces/pawn_b_bg_b.png";
    }
}

bool Pawn::valid_path(Move mv) {
    if (!mv.is_forward())
        return false;
    if (!has_moved && mv.is_vertical() && mv.euclid_dist() == mv.FORWARD_UNIT * 2)
    {
        // 2 forward case
        return true;
    }
    else if (mv.is_vertical() && mv.euclid_dist() == mv.FORWARD_UNIT)
    {
        // 1 forward case
        return true;
    }
    else if (mv.piece_killed && mv.is_diagonal() && mv.euclid_dist() == mv.DIAG_UNIT)
    {
        // diagonal kill case (standard and en passant)
        return true;
    }
    return false;
}

bool Pawn::get_has_moved() {
    return has_moved;
}

bool Pawn::get_moved_two() {
    return moved_two;
}

bool Pawn::is_pawn() const {
    return true;
}