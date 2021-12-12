/*
 * player.h
 * David Gurevich
 * CS 246
 */

#ifndef _PLAYER_H
#define _PLAYER_H

// #include "move.h"
#include "piece.h"
#include <vector>
#include <memory>

class Board;
class Move;

class Player {
    int score;
    bool white;
    std::vector<std::shared_ptr<Piece>> pieces;

public:
    Player(bool white);
    ~Player() = default;

    bool is_white();
    int get_score();
    int incr_score();

    bool has_valid_moves();
    void gen_standard_pieces();
    Move get_next_move(const Board *b);
    void add_piece(std::shared_ptr<Piece> p);
    Piece* get_last_piece();
    Piece* get_nth_piece(size_t n);
};

#endif