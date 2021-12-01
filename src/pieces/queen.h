#include "../piece.h"

class Queen : public Piece
{

public:
    bool validMove(Move mv) override;
};