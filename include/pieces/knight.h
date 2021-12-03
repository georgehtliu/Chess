#ifndef _KNIGHT_H_
#define _KNIGHT_H_

#include "piece.h"
#include "move.h"

class Knight : public Piece
{

public:
    bool valid_move(Move mv) override;
};

#endif