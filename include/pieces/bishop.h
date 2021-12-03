#ifndef _BISHOP_H_
#define _BISHOP_H_

#include "piece.h"
#include "move.h"

class Bishop : public Piece
{

public:
    bool valid_move(Move mv) override;
};

#endif