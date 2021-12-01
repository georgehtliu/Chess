#ifndef _KING_H_
#define _KING_H_

#include "../piece.h"
#include "../move.h"

class King : public Piece
{

    bool hasMoved;

public:
    const int CASTLE_DISTANCE = 2;
    bool getHasMoved();
    bool validMove(Move mv) override;
    bool validCastle(Move mv);
};

#endif