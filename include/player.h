/*
 * player.h
 * David Gurevich
 * CS 246
 */

#ifndef _PLAYER_H
#define _PLAYER_H

#include "move.h"
#include <vector>
#include <memory>

class Board;

class Player {
    int score;
    bool white;
    std::vector<std::shared_ptr<Piece>> pieces;

    void gen_standard_pieces();

public:
    Player(bool white, bool empty=false);
    ~Player() = default;

    bool is_white();
    int get_score();
    int incr_score();

    bool has_valid_moves();
    Move get_next_move(const Board *b);
};

#endif