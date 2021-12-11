/*
    board.h
    David Gurevich
    CS 246
*/

#ifndef CHESS_INCLUDE_BOARD_H_
#define CHESS_INCLUDE_BOARD_H_

#include <vector>
#include <memory>

#include "observer.h"
#include "spot.h"
#include "player.h"
#include "move.h"

class Board
{
    // TODO:
    Player *white;
    Player *black;
    std::vector<Move> moves;

    std::vector<Observer *> observers;
    std::vector<std::vector<Spot> > positions;
    bool white_move;
    Spot *white_king_spot;
    Spot *black_king_spot;

    // Manage/execute moves
    bool check_valid_move(Move mv);
    void execute_move(Move mv);
    bool search_attacker(Spot *spot, int x_inc, int y_inc);
    bool under_attack_vertical(Spot *spot);
    bool under_attack_horizontal(Spot *spot);
    bool under_attack_diagonal(Spot *spot);
    bool under_attack_knight(Spot *spot);
    bool under_attack(Spot *spot);
    bool is_attacking_path(Spot *end, Spot *attack_candidate);
    bool valid_path(Spot *from, Spot *to);
    bool same_team(Spot *s1, Spot *s2);

public:
    // Constructor / Destructor
    Board();
    ~Board() = default; // FIXME

    // Observers
    void attach(Observer *o);
    void detach(Observer *o);
    void notify_observers();
    // void notify_observers(Move m); // TODO

    // Board info
    const static int ROWS = 8;
    const static int COLS = 8;

    // Manage spots
    std::shared_ptr<Spot> get_spot(int x, int y);
};

#endif // CHESS_INCLUDE_BOARD_H_