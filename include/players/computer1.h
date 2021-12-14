//
// Created by david on 12/12/21.
//

#ifndef CS246_CHESS_COMPUTER1_H
#define CS246_CHESS_COMPUTER1_H

#include "player.h"

class Computer1 : public Player {
public:
    Computer1(bool white);

    Move get_next_move(Board *b) override;
};

#endif //CS246_CHESS_COMPUTER1_H
