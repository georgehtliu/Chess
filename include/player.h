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

class Board;
class Move;

class Player {
protected:
    int score;
    bool white;
    std::vector<std::shared_ptr<Piece>> pieces;

public:
    virtual ~Player() = default;

    bool is_white() const;
    int get_score();
    int incr_score();

    bool has_valid_moves();
    void gen_standard_pieces();
    void add_piece(std::shared_ptr<Piece> p);
    void remove_last_piece();
    Piece* get_last_piece();
    Piece* get_nth_piece(size_t n);

    virtual Move get_next_move(Board *b);
    std::vector<Move> all_next_moves(Board *b);

};

#endif