#ifndef _PIECE_H_
#define _PIECE_H_


class Move;

class Piece {

    bool alive;

protected:
    unsigned char* rgb_image;
    bool white;
public:

    bool is_white();
    bool is_alive();
    virtual unsigned char* get_image();
    virtual bool valid_move(Move mv) = 0;
    virtual ~Piece() = default;
};

#endif