#include "../piece.h"

class Rook : public Piece
{

    bool hasMoved;

public:
    bool getHasMoved();
    bool validMove(Move mv) override;
};