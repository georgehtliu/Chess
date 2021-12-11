//
// Created by david on 12/10/21.
//



#include "knight.h"

Knight::Knight(bool white) {
    this->white = white;
}

bool Knight::valid_move(Move mv) {
    // FIXME
    return mv.is_diagonal();
}

