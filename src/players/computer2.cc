//
// Created by david on 12/12/21.
//

#include "computer2.h"
#include "move.h"

Computer2::Computer2(bool white) {
    this->white = white;
}

Move Computer2::get_next_move(Board *b) {
    return Player::get_next_move(b);
}
