#include "move.h"
//#include "player.h"
#include "spot.h"
#include "piece.h"

Move::Move(Player *p, Spot *start_p, Spot *end_p, Piece *p_moved, Piece *p_killed, char p_promote, bool res) : player{
        p}, start_pos{start_p}, end_pos{end_p}, piece_moved{p_moved}, piece_killed{p_killed}, promotion_piece{
        p_promote}, is_resign{res} {}

bool Move::is_diagonal() const {
    return abs(start_pos->get_x() - end_pos->get_x()) == abs(start_pos->get_y() - end_pos->get_y());
}

bool Move::is_horizontal() const {
    return start_pos->get_y() == end_pos->get_y();
}

bool Move::is_vertical() const {
    return start_pos->get_x() == end_pos->get_x();
}

bool Move::is_forward() const {
    if (piece_moved->is_white()) {
        return (start_pos->get_y() < end_pos->get_y());
    } else {
        return (start_pos->get_y() > end_pos->get_y());
    }
}

int Move::euclid_dist() const {
    int delta_x = start_pos->get_x() - end_pos->get_x();
    int delta_y = start_pos->get_y() - end_pos->get_y();
    return sqrt(delta_x * delta_x + delta_y * delta_y);
}

int Move::x_dist() const {
    return abs(start_pos->get_x() - end_pos->get_x());
}

int Move::y_dist() const {
    return abs(start_pos->get_y() - end_pos->get_y());
}

bool Move::is_promotion() const {
    // pawn moving to last rank
    if (!piece_moved->is_pawn()) return false;
    int last_rank = 0;
    if (piece_moved->is_white()) {
        last_rank = 7;
    }
    return end_pos->get_y() == last_rank;
}

bool Move::is_castle() {
    return piece_moved->is_king() && euclid_dist() == 2 && is_horizontal();
}
