//
// Created by david on 12/12/21.
//

#include "computer1.h"
#include "move.h"
#include <vector>
#include <cstdlib>

Computer1::Computer1(bool white) {
    this->white = white;
}

Move Computer1::get_next_move(Board *b) {
    std::vector<Move> possible_moves = Player::all_next_moves(b);
    int number_of_moves = possible_moves.size();
    int index = rand() % number_of_moves;
    return possible_moves[index];
}
