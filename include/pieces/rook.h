#ifndef _ROOK_H_
#define _ROOK_H_
#include "piece.h"
#include "move.h"

class Rook : public Piece {
    bool has_moved;

public:
    Rook(bool white);
    bool get_has_moved();
    bool valid_path(Move mv) override;
};

#endif