//
// Created by david on 12/12/21.
//

#include "computer1.h"
#include "move.h"

Computer1::Computer1(bool white) {
    this->white = white;
}

Move Computer1::get_next_move(const Board *b) {
    return Player::get_next_move(b);
}
