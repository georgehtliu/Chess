#ifndef _ROOK_H_
#define _ROOK_H_
#include "../piece.h"
#include "../move.h"

class Rook : public Piece
{

    bool hasMoved;

public:
    bool getHasMoved();
    bool validMove(Move mv) override;
};

#endif