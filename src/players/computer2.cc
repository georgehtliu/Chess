#include <map>
#include "computer2.h"
#include "move.h"
#include "board.h"

Move computer2_get_next_move(Player *p, Board *b) {
    std::vector<Move> possible_moves = p->all_next_moves(b);

    std::map<int, std::vector<Move>> sorted_possible_moves;
    for (auto &m: possible_moves) {
        int eval = b->evaluate_move(m);
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
