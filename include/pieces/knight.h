#ifndef _KNIGHT_H_
#define _KNIGHT_H_

#include "piece.h"
#include "move.h"

class Knight : public Piece {

public:
    Knight(bool white);
    bool valid_path(Move mv) override;
};

#endif