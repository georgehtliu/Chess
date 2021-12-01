#ifndef _PAWN_H_
#define _PAWN_H_

#include "../piece.h"

class Pawn : public Piece
{
    bool hasMoved;
    bool movedTwo;

public:
    bool validMove(Move mv) override;
    bool getHasMoved();
    bool getMovedTwo();
};

#endif