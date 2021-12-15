/*
 * player.h
 * David Gurevich
 * CS 246
 */

#ifndef _PLAYER_H
#define _PLAYER_H

#include "piece.h"

#include <vector>
#include <memory>
#include <random>

/* This is used a lot in the AI */
// Choose random element in vector
template<typename Iter, typename RandomGenerator>
Iter select_randomly(Iter start, Iter end, RandomGenerator& g) {
    std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
    std::advance(start, dis(g));
    return start;
}

template <typename Iter>
Iter select_randomly(Iter start, Iter end) {
    if (start == end) {
        return start;
    }
    static std::random_device rd;
    static std::mt19937 gen(rd());
    return select_randomly(start, end, gen);
}
/*********************************/

class Board;
class Move;

enum PlayerType{Human, AI1, AI2, AI3, AI4};

class Player {
public:
    std::vector<std::shared_ptr<Piece>> pieces;

    bool white;
    PlayerType type;

    Player(bool white, PlayerType type);
    ~Player() = default;

    bool is_white() const;

    void set_type(PlayerType type);
    bool has_valid_moves();
    void gen_standard_pieces();
    void add_piece(std::shared_ptr<Piece> p);
    void remove_last_piece();
    Piece* get_last_piece();
    Piece* get_nth_piece(size_t n);

    Move get_next_move(Board *b);
    std::vector<Move> all_next_moves(Board *b);

};

#endif