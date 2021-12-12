#ifndef _BISHOP_H_
#define _BISHOP_H_

#include "piece.h"
#include "move.h"

class Bishop : public Piece {

public:
    Bishop(bool white);
    bool valid_path(Move mv) override;
};

#endif