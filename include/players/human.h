//
// Created by david on 12/12/21.
//

#ifndef CS246_CHESS_HUMAN_H
#define CS246_CHESS_HUMAN_H

#include "player.h"

class Human : public Player {

public:
    Human(bool white);

    Move get_next_move(const Board *b) override;
};


#endif //CS246_CHESS_HUMAN_H