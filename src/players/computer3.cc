//
// Created by david on 12/12/21.
//

#include "computer3.h"
#include "move.h"

Computer3::Computer3(bool white) {
    this->white = white;
}

Move Computer3::get_next_move(const Board *b) {
    return Player::get_next_move(b);
}
