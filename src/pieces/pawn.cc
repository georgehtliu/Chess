//
// Created by david on 12/10/21.
//

#include "pawn.h"

Pawn::Pawn(bool white) {
    this->white = white;
}

bool Pawn::valid_move(Move mv) {
    // FIXME
    return mv.is_vertical();
}

