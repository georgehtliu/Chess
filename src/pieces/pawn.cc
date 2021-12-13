#include "pawn.h"

Pawn::Pawn(bool white) {
    this->white = white;
    if (white) {
        text_repr = 'P';
        white_square = "assets/pieces/pawn_w_bg_w.png";
        black_square = "assets/pieces/pawn_w_bg_b.png";
    } else {
        text_repr = 'p';
        white_square = "assets/pieces/pawn_b_bg_w.png";
        black_square = "assets/pieces/pawn_b_bg_b.png";
    }
}

bool Pawn::valid_path(Move mv) {
    if (!mv.is_forward())
        return false;
    if (!moved && mv.is_vertical() && mv.euclid_dist() == mv.FORWARD_UNIT * 2)
    {
        // 2 forward case
        return true;
    }
    else if (mv.is_vertical() && mv.euclid_dist() == mv.FORWARD_UNIT)
    {
        // 1 forward case
        return true;
    }
    else if (mv.piece_killed && mv.is_diagonal() && mv.euclid_dist() == mv.DIAG_UNIT)
    {
        // diagonal kill case (standard and en passant)
        return true;
    }
    return false;
}

bool Pawn::is_pawn() const {
    return true;
}

std::vector<std::pair<int, int>> Pawn::generate_paths(std::pair<int, int> pos) {
    std::vector<std::pair<int, int>> paths;
    
    int x = pos.first;
    int y = pos.second;

    int forward_dir;
    if (this->is_white()) {
        forward_dir = 1;
    } else {
        forward_dir = -1;
    }
    // there are up to 4 possible cases for pawns
    if (this->in_board(x, y + forward_dir)) paths.push_back(std::make_pair(x, y + forward_dir));
    if (!moved && this->in_board(x, y + 2 * forward_dir)) paths.push_back(std::make_pair(x, y + 2 * forward_dir));
    if (this->in_board(x + 1, y +  forward_dir)) paths.push_back(std::make_pair(x + 1, y + forward_dir));
    if (this->in_board(x - 1, y +  forward_dir)) paths.push_back(std::make_pair(x - 1, y + forward_dir));

    return paths;
}
