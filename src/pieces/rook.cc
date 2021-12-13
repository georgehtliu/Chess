#include "rook.h"

Rook::Rook(bool white) {
    this->white = white;
    if (white) {
        this->text_repr = 'R';
    } else {
        this->text_repr = 'r';
    }
}

bool Rook::get_has_moved() {
    return has_moved;
}

bool Rook::valid_path(Move mv) {
    return mv.is_vertical() || mv.is_horizontal();
}

std::vector<std::pair<int, int>> Rook::generate_paths(std::pair<int, int> pos) {
    std::vector<std::pair<int, int>> paths;
    
    int x = pos.first;
    int y = pos.second;

    // verticals
    this->increment(0, 1, x, y + 1, &paths);
    this->increment(0, -1, x, y - 1, &paths);    

    // horizontals
    this->increment(1, 0, x + 1, y, &paths);
    this->increment(-1, 0, x - 1, y, &paths);

    return paths;
}
