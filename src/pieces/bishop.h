#ifndef _BISHOP_H_
#define _BISHOP_H_

#include "../piece.h"

class Bishop : public Piece
{

public:
    bool validMove(Move mv) override;
};

#endif