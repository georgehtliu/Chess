#ifndef _QUEEN_H_
#define _QUEEN_H_
#include "../piece.h"
#include "../move.h"

class Queen : public Piece {

public:
    Queen(bool white);
    bool valid_path(Move mv) override;
};

#endif