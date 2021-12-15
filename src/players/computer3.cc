#include <map>

#include "computer3.h"
#include "move.h"
#include "board.h"

Move computer3_get_next_move(Player *p, Board *b) {
    std::vector<Move> possible_moves = p->all_next_moves(b);

    std::map<int, std::vector<Move>> sorted_possible_moves;
    for (auto &m: possible_moves) {
        if (!(m.start_pos->get_piece())) {
            continue;
        }
        int eval = b->evaluate_move(m, true);
        auto it = sorted_possible_moves.find(eval);
        if (it == sorted_possible_moves.end()) {
            sorted_possible_moves[eval] = std::vector<Move>{m};
        } else {
            sorted_possible_moves[eval].push_back(m);
        }
    }

    if (p->white) {
        auto smallest_key = sorted_possible_moves.begin()->second;
        return *select_randomly(smallest_key.begin(), smallest_key.end());
    } else {
        auto largest_key = sorted_possible_moves.rbegin()->second;
        return *select_randomly(largest_key.begin(), largest_key.end());
    }
}
