#include "../piece.h"

class King : public Piece
{

    bool hasMoved;

public:
    bool getHasMoved();
    bool validMove(Move mv) override;
};