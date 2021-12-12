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
    virtual bool is_pawn() const;
    virtual bool is_king() const;
    char get_text();
    void set_killed();
    void set_alive();
    void set_white(bool white);
    virtual bool valid_path(Move mv) = 0;
    virtual ~Piece() = default;
};

#endif