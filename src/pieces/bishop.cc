#include "bishop.h"
#include "move.h"

Bishop::Bishop(bool white) {
    this->white = white;

    if (white) {
        text_repr = 'B';
        white_square = "assets/pieces/bishop_w_bg_w.png";
        black_square = "assets/pieces/bishop_w_bg_b.png";
    } else {
        text_repr = 'b';
        white_square = "assets/pieces/bishop_b_bg_w.png";
        black_square = "assets/pieces/bishop_b_bg_b.png";
    }
}

bool Bishop::valid_path(Move mv) {
    return mv.is_diagonal();
}
