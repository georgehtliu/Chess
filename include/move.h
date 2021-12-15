#ifndef MOVE_H_
#define MOVE_H_

#include "math.h"
#include "player.h"
#include "spot.h"
#include "piece.h"

class Move {
public:
    int FORWARD_UNIT = 1;
    int DIAG_UNIT = sqrt(2);
    Player *player;
    Spot *start_pos;
    Spot *end_pos;
    Piece *piece_moved;
    Piece *piece_killed;
    char promotion_piece;
    bool is_resign;
    
    bool is_promotion() const;
    bool is_castle();
    bool is_diagonal() const;
    bool is_horizontal() const;
    bool is_vertical() const;
    bool is_forward() const;
    int euclid_dist() const;
    int x_dist() const;
    int y_dist() const;
    Move(Player *p, Spot *start_p, Spot *end_p, Piece *p_moved, Piece *p_killed = nullptr, char p_promote = 'x', bool res = false);
};

#endif