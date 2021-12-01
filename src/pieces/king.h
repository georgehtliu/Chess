#ifndef _KING_H_
#define _KING_H_

#include "../piece.h"

class King : public Piece
{

    bool hasMoved;

public:
    bool getHasMoved();
    bool validMove(Move mv) override;
};

#endif