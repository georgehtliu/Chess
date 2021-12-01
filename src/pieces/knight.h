#include "../piece.h"

class Knight : public Piece
{

public:
    bool validMove(Move mv) override;
};