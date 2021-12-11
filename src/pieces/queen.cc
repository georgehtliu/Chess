#include "queen.h"

Queen::Queen(bool white) {
    this->white = white;
}

bool Queen::valid_move(Move mv) {
    return (mv.is_vertical() || mv.is_horizontal()) || mv.is_diagonal();
}

