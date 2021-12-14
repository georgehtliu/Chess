//
// Created by david on 12/12/21.
//

#ifndef CS246_CHESS_COMPUTER3_H
#define CS246_CHESS_COMPUTER3_H

#include "player.h"

class Computer3 : public Player {
public:
    Computer3(bool white);

    Move get_next_move(Board *b) override;
};


#endif //CS246_CHESS_COMPUTER3_H
