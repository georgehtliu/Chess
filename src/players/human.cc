//
// Created by david on 12/12/21.
//

#include "human.h"
#include "move.h"

Human::Human(bool white) {
    this->white = white;
}

Move Human::get_next_move(const Board *b) {
    (void)b;
    return Move(this, nullptr, nullptr, nullptr);
}
