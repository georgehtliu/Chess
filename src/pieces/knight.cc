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

std::vector<std::pair<int, int>> Knight::generate_paths(std::pair<int, int> pos) {
    std::vector<std::pair<int, int>> paths;

    int x = pos.first;
    int y = pos.second;

    for (int i = 1; i <= 2; i++) {
        for (int j = -2; j <= -1; j++) {
            if (this->in_board(x + i, y + j)) paths.push_back(std::make_pair(x + i, y + j));
            if (this->in_board(x + j, y + i)) paths.push_back(std::make_pair(x + j, y + i));
        }
    }
    
    return paths;
}
