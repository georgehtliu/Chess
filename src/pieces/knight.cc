#include "knight.h"
#include <utility>
#include <memory>

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

    // 8 moves
    if (this->in_board(x - 2, y - 1)) paths.push_back(std::make_pair(x - 2, y - 1));
    if (this->in_board(x - 2, y + 1)) paths.push_back(std::make_pair(x - 2, y + 1));
    if (this->in_board(x + 2, y - 1)) paths.push_back(std::make_pair(x + 2, y - 1));
    if (this->in_board(x + 2, y + 1)) paths.push_back(std::make_pair(x + 2, y + 1));
    if (this->in_board(x - 1, y - 2)) paths.push_back(std::make_pair(x - 1, y - 2));
    if (this->in_board(x - 1, y + 2)) paths.push_back(std::make_pair(x - 1, y + 2));
    if (this->in_board(x + 1, y - 2)) paths.push_back(std::make_pair(x + 1, y - 2));
    if (this->in_board(x + 1, y + 2)) paths.push_back(std::make_pair(x + 1, y + 2));

    
    return paths;
}
