#include "pawn.h"

Pawn::Pawn(bool white) {
    this->white = white;
    this->value = (white ? 1 : -1) * 10;
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
    if (!moved && mv.is_vertical() && mv.euclid_dist() == mv.FORWARD_UNIT * 2) {
        // 2 forward case
        if (mv.end_pos->get_piece()) {
            return false;
        }
        return true;
    } else if (mv.is_vertical() && mv.euclid_dist() == mv.FORWARD_UNIT) {
        // 1 forward case
        if (mv.end_pos->get_piece()) {
            return false;
        }
        return true;
    } else if (mv.is_diagonal() && mv.euclid_dist() == mv.DIAG_UNIT) {
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
    if (this->in_board(x, y + forward_dir)) paths.emplace_back(x, y + forward_dir);
    if (!moved && this->in_board(x, y + 2 * forward_dir)) paths.emplace_back(x, y + 2 * forward_dir);
    if (this->in_board(x + 1, y + forward_dir)) paths.emplace_back(x + 1, y + forward_dir);
    if (this->in_board(x - 1, y + forward_dir)) paths.emplace_back(x - 1, y + forward_dir);

    return paths;
}
