#include "king.h"

King::King(bool white) {
    this->white = white;
    if (white) {
        text_repr = 'K';
        white_square = "assets/pieces/king_w_bg_w.png";
        black_square = "assets/pieces/king_w_bg_b.png";
    } else {
        text_repr = 'k';
        white_square = "assets/pieces/king_b_bg_w.png";
        black_square = "assets/pieces/king_b_bg_b.png";
    }
}

bool King::get_has_moved() {
    return has_moved;
}

bool King::valid_castle(Move mv) {
    if (has_moved)
        return false;
    return mv.is_horizontal() && mv.euclid_dist() == mv.FORWARD_UNIT * 2;
}

bool King::valid_path(Move mv) {
    int mvEuclidDist = mv.euclid_dist();

    if (!mv.is_castle)
    {
        return (mv.is_diagonal() && mvEuclidDist == mv.DIAG_UNIT) || ((mv.is_vertical() || mv.is_horizontal()) && mvEuclidDist == mv.FORWARD_UNIT);
    }

    return valid_castle(mv);
}

bool King::is_king() const {
    return true;
}