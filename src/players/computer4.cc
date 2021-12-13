//
// Created by david on 12/12/21.
//

#include "computer4.h"
#include "move.h"

Computer4::Computer4(bool white) {
    this->white = white;
}

Move Computer4::get_next_move(const Board *b) {
    return Player::get_next_move(b);
}
