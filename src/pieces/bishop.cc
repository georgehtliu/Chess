#include "bishop.h"
#include "move.h"

Bishop::Bishop(bool white) {
    this->white = white;
    if (white) {
        this->text_repr = 'B';
    } else {
        this->text_repr = 'b';
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
