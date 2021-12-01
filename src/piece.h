class Move;

class Piece
{

    bool white;
    bool alive;

public:
    bool isWhite();
    bool isAlive();
    virtual bool validMove(Move mv) = 0;
    virtual ~Piece();
};