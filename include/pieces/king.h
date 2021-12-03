#ifndef _KING_H_
#define _KING_H_

#include "piece.h"
#include "move.h"

class King : public Piece
{

    bool white;
    bool has_moved;

public:
    King(bool white);
    ~King();
    bool get_has_moved();
    bool valid_move(Move mv) override;
    bool valid_castle(Move mv);

};

#endif