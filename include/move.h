#ifndef _MOVE_H_
#define _MOVE_H_

#include "math.h"
#include "player.h"
#include "spot.h"
#include "piece.h"

class Move
{

public:
    int FORWARD_UNIT = 1;
    int DIAG_UNIT = sqrt(2);
    Player *player;
    Spot *start_pos;
    Spot *end_pos;
    Piece *piece_moved;
    Piece *piece_killed;
    Piece *promotion_piece;
    bool is_castle;
    bool is_en_passant;
    bool is_promotion;
    bool is_resign;
    bool is_diagonal();
    bool is_horizontal();
    bool is_vertical();
    bool is_forward();
    int euclid_dist();
    int x_dist();
    int y_dist();
    Move(Player *p, Spot *start_p, Spot *end_p, Piece *p_moved, Piece *p_killed = nullptr, bool castle = false, bool ep = false, bool prom = false, bool res = false);
};

#endif