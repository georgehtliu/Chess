#include "knight.h"

Knight::Knight(bool white) {
    this->white = white;
    if (white) {
        text_repr = 'N';
        white_square = "assets/pieces/knight_w_bg_w.png";
        black_square = "assets/pieces/knight_w_bg_b.png";
    } else {
        text_repr = 'n';
        white_square = "assets/pieces/knight_b_bg_w.png";
        black_square = "assets/pieces/knight_b_bg_b.png";
    }
}

bool Knight::valid_path(Move mv) {
    return ((mv.x_dist() == mv.FORWARD_UNIT && mv.y_dist() == 2 * mv.FORWARD_UNIT) || (mv.x_dist() == 2 * mv.FORWARD_UNIT && mv.y_dist() == mv.FORWARD_UNIT));
}
