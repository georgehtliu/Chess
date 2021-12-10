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

class Board {
    // TODO:
    // Player* white;
    // Player* black;
    // std::vector<Move> moves;


    std::vector<Observer*> observers;
    std::vector<std::vector<Spot>> positions;
    bool white_move;

   public:
    // Constructor / Destructor
    Board();
    ~Board() = default;  // FIXME

    // Observers
    void attach(Observer *o);
    void detach(Observer *o);
    void notify_observers();
    // void notify_observers(Move m); // TODO

    // Board info
    const static int ROWS = 8;
    const static int COLS = 8;

    // Manage spots
    Spot * get_spot(int x, int y);
};

#endif  // CHESS_INCLUDE_BOARD_H_