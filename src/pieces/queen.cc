#include "queen.h"

Queen::Queen(bool white) {
    this->white = white;
    if (white) {
        text_repr = 'Q';
        white_square = "assets/pieces/queen_w_bg_w.png";
        black_square = "assets/pieces/queen_w_bg_b.png";
    } else {
        text_repr = 'q';
        white_square = "assets/pieces/queen_b_bg_w.png";
        black_square = "assets/pieces/queen_b_bg_b.png";
    }
}

bool Queen::valid_path(Move mv) {
    return (mv.is_vertical() || mv.is_horizontal()) || mv.is_diagonal();
}

