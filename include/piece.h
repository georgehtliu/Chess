#ifndef _PIECE_H_
#define _PIECE_H_

class Move;

class Piece
{

    bool white;
    bool alive;

public:
    bool is_white() const;
    bool is_alive();
    virtual bool valid_move(Move mv) = 0;
    virtual ~Piece();
};

#endif