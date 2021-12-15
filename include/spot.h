#ifndef CHESS_INCLUDE_SPOT_H_
#define CHESS_INCLUDE_SPOT_H_

#include "piece.h"

class Spot {
    Piece *p;
    int x, y;
    bool white;

public:
    Spot(int x, int y);
    Spot(int x, int y, Piece *p);
    ~Spot() = default;

    int get_x() const;
    int get_y() const;
    bool is_white() const;
    Piece *get_piece() const;
    void set_piece(Piece *p);
    bool is_blank();
    bool in_bounds() const;
    void remove_piece();
};

#endif // CHESS_INCLUDE_SPOT_H_