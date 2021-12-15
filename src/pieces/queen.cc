#include "queen.h"

Queen::Queen(bool white) {
    this->white = white;
    this->value = (white ? 1 : -1) * 90;
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

std::vector<std::pair<int, int>> Queen::generate_paths(std::pair<int, int> pos) {
    std::vector<std::pair<int, int>> paths;

    int x = pos.first;
    int y = pos.second;

    // verticals
    this->increment(0, 1, x, y + 1, &paths);
    this->increment(0, -1, x, y - 1, &paths);

    // horizontals
    this->increment(1, 0, x + 1, y, &paths);
    this->increment(-1, 0, x - 1, y, &paths);

    // diagonals
    this->increment(1, 1, x + 1, y + 1, &paths);
    this->increment(-1, 1, x - 1, y + 1, &paths);
    this->increment(-1, -1, x - 1, y - 1, &paths);
    this->increment(1, -1, x + 1, y - 1, &paths);

    return paths;
}
