//
// Created by david on 12/12/21.
//

#ifndef CS246_CHESS_COMPUTER2_H
#define CS246_CHESS_COMPUTER2_H

#include "player.h"

class Computer2 : public Player {
public:
    explicit Computer2(bool white);

    Move get_next_move(Board *b) override;
};


#endif //CS246_CHESS_COMPUTER2_H
