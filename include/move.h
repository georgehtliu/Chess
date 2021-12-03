#ifndef _MOVE_H_
#define _MOVE_H_

#include "math.h"

class Player;
class Spot;
class Piece;

class Move
{

public:
    const int FORWARD_UNIT = 1;
    const int DIAG_UNIT = sqrt(2);
    const Player *player;
    const Spot *start_pos;
    const Spot *end_pos;
    const Piece *piece_moved;
    const Piece *piece_killed;
    const bool is_castle;
    const bool is_en_passant;
    const bool is_resign;
    bool is_diagonal();
    bool is_horizontal();
    bool is_vertical();
    bool is_forward();
    int euclid_dist();
    int x_dist();
    int y_dist();
};

#endif