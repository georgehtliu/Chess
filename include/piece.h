#ifndef _PIECE_H_
#define _PIECE_H_

class Move;

class Piece {
protected:
    bool white;
    bool alive;
    char text_repr;
public:
    bool is_white() const;
    bool is_alive();
    char get_text();
    void set_killed();
    virtual bool valid_move(Move mv) = 0;

    virtual ~Piece() = default;
};

#endif