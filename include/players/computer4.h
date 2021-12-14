//
// Created by david on 12/12/21.
//

#ifndef CS246_CHESS_COMPUTER4_H
#define CS246_CHESS_COMPUTER4_H

#include "player.h"

class Computer4 : public Player {
public:
    explicit Computer4(bool white);

    Move get_next_move(Board *b) override;
};


#endif //CS246_CHESS_COMPUTER4_H
