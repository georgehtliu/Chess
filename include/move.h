#ifndef _MOVE_H_
#define _MOVE_H_

#include "math.h"
#include "player.h"
#include "spot.h"
#include "piece.h"

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
    Move(Player *p, Spot *start_p, Spot *end_p, Piece *p_moved, Piece *p_killed = nullptr, bool castle = false, bool ep = false, bool res = false);
};

#endif