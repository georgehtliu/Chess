//
// Created by david on 12/12/21.
//

#include <algorithm>
#include "computer2.h"
#include "move.h"
#include "board.h"

Move computer2_get_next_move(Player *p, Board *b) {
    std::vector<Move> possible_moves = p->all_next_moves(b);

    std::sort(possible_moves.begin(), possible_moves.end(),
              [p,b](Move &m, Move &n) -> bool {
        if (p->is_white()) {
            return b->evaluate_move(m) > b->evaluate_move(n);
        } else {
            return b->evaluate_move(m) < b->evaluate_move(n);
        }
    });

    return possible_moves[0];
}
