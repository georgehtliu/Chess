//
// Created by david on 12/12/21.
//

#include "computer1.h"

#include <vector>
#include <random>

// Choose random element in vector
template<typename Iter, typename RandomGenerator>
Iter select_randomly(Iter start, Iter end, RandomGenerator& g) {
    std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
    std::advance(start, dis(g));
    return start;
}

template <typename Iter>
Iter select_randomly(Iter start, Iter end) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    return select_randomly(start, end, gen);
}

Move computer1_get_next_move(Player *p, Board *b) {
    std::vector<Move> possible_moves = p->all_next_moves(b);
    return *select_randomly(possible_moves.begin(), possible_moves.end());
}
