//
// Created by david on 12/12/21.
//

#include "computer1.h"

#include <vector>

Move computer1_get_next_move(Player *p, Board *b) {
    std::vector<Move> possible_moves = p->all_next_moves(b);
    return *select_randomly(possible_moves.begin(), possible_moves.end());
}
