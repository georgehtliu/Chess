#include "../piece.h"

class Bishop : public Piece
{

public:
    bool validMove(Move mv) override;
};