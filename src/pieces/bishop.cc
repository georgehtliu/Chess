#include "bishop.h"
#include "move.h"

Bishop::Bishop(bool white) {
    this->white = white;
    this->value = (white ? 1 : -1) * 30;

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

std::vector<std::pair<int, int>> Bishop::generate_paths(std::pair<int, int> pos) {
    std::vector<std::pair<int, int>> paths;

    int x = pos.first;
    int y = pos.second;

    // diagonals
    this->increment(1, 1, x + 1, y + 1, &paths);
    this->increment(-1, 1, x - 1, y + 1, &paths);
    this->increment(-1, -1, x - 1, y - 1, &paths);
    this->increment(1, -1, x + 1, y - 1, &paths);

    return paths;
}
