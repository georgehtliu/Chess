#ifndef _QUEEN_H_
#define _QUEEN_H_
#include "piece.h"
#include "move.h"

class Queen : public Piece
{

public:
    bool valid_move(Move mv) override;
};

#endif