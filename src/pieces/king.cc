#include "king.h"

King::King(bool white) {
    this->white = white;
    this->value = (white ? 1 : -1) * 900;

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

bool King::valid_path(Move mv) {
    int mvEuclidDist = mv.euclid_dist();
    if (mvEuclidDist == 2 && mv.is_horizontal()) return true;
    return (mv.is_diagonal() && mvEuclidDist == mv.DIAG_UNIT) ||
           ((mv.is_vertical() || mv.is_horizontal()) && mvEuclidDist == mv.FORWARD_UNIT);
}

bool King::is_king() const {
    return true;
}

std::vector<std::pair<int, int>> King::generate_paths(std::pair<int, int> pos) {
    std::vector<std::pair<int, int>> paths;

    int x = pos.first;
    int y = pos.second;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (this->in_board(x + i, y + j)) paths.emplace_back(x + i, y + j);
        }
    }

    return paths;
}
