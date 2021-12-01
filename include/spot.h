/*
    spot.h
    David Gurevich
    CS 246
*/

#ifndef CHESS_INCLUDE_SPOT_H_
#define CHESS_INCLUDE_SPOT_H_

class Spot {
    // Piece p;
    int x, y;
    bool white;

   public:
    Spot(int x, int y);
    ~Spot() = default;  // TEMP

    int get_x() const;
    int get_y() const;
    bool is_white() const;
};

#endif  // CHESS_INCLUDE_SPOT_H_