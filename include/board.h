/*
    board.h
    David Gurevich
    CS 246
*/

#ifndef CHESS_INCLUDE_BOARD_H_
#define CHESS_INCLUDE_BOARD_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <memory>

#include "observer.h"
#include "spot.h"
#include "player.h"
#include "move.h"
#include "piece.h"

class Board
{
    Player* white;
    Player* black;

    std::vector<Move> moves;

    std::vector<std::vector<Spot>> positions;
    bool white_move;
    Spot *white_king_spot;
    Spot *black_king_spot;

    // Manage/execute moves
    bool check_valid_move(Move &mv);
    void execute_en_passant(Move &mv);
    void execute_castle(Move &mv);
    Spot *get_rook_end_spot_castle(Spot *king_end);
    void execute_promotion(Move &mv);
    bool has_moved(Piece *p);
    bool valid_castle(Move &mv);
    bool valid_promotion(Move &mv);
    bool valid_en_passant(Move &mv);
    bool search_attacker(Spot *spot, int x_inc, int y_inc);
    bool under_attack_vertical(Spot *spot);
    bool under_attack_horizontal(Spot *spot);
    bool under_attack_diagonal(Spot *spot);
    bool under_attack_knight(Spot *spot);
    bool move_blocked(Move &mv);
    bool under_attack(Spot *spot);
    bool is_attacking_path(Spot *end, Spot *attack_candidate);
    bool valid_path(Spot *from, Spot *to);
    bool same_team(Spot *s1, Spot *s2);
    bool same_spot(Spot *s1, Spot *s2);
    bool in_check();
    bool in_check_after_move(Move &mv);
    void add_piece(char piece, std::string position);
    bool setup_complete();

public:
    // Constructor / Destructor
    Board(Player* white, Player* black);
    ~Board() = default; // FIXME

    // Observers
    void attach(Observer *o);
    void detach(Observer *o);
    void notify_observers();
    // void notify_observers(Move m); // TODO

    // Board info
    const static int ROWS = 8;
    const static int COLS = 8;

    // Board construction
    void gen_standard_layout();
    void setup_mode(); 

    // Manage spots
    Spot* get_spot(int x, int y);

    void execute_move(Move &mv);
    void place_piece(Spot *start, Spot *end);

    void set_white(Player* white);
    void set_black(Player* black);
    Player* get_black();
    Player* get_white();

    std::vector<Observer *> observers;
};

#endif // CHESS_INCLUDE_BOARD_H_