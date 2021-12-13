#include "move.h"
//#include "player.h"
#include "spot.h"
#include "piece.h"

Move::Move(Player *p, Spot *start_p, Spot *end_p, Piece *p_moved, Piece *p_killed, bool castle, bool ep, char p_promote, bool res) : player{p}, start_pos{start_p}, end_pos{end_p}, piece_moved{p_moved}, piece_killed{p_killed}, is_castle{castle}, is_en_passant{ep}, promotion_piece{p_promote}, is_resign{res} {}

bool Move::is_diagonal()
{
    return abs(start_pos->get_x() - end_pos->get_x()) == abs(start_pos->get_y() - end_pos->get_y());
}

bool Move::is_horizontal()
{
    return start_pos->get_x() == end_pos->get_x();
}

bool Move::is_vertical()
{
    return start_pos->get_y() == end_pos->get_y();
}

bool Move::is_forward()
{
    if (piece_moved->is_white())
    {
        return (start_pos->get_y() < end_pos->get_y());
    }
    else
    {
        return (start_pos->get_y() > end_pos->get_y());
    }
}

int Move::euclid_dist()
{
    int delta_x = start_pos->get_x() - end_pos->get_x();
    int delta_y = start_pos->get_y() - end_pos->get_y();
    return sqrt(delta_x * delta_x - delta_y * delta_y);
}

int Move::x_dist()
{
    return abs(start_pos->get_x() - end_pos->get_x());
}

int Move::y_dist()
{
    return abs(start_pos->get_y() - end_pos->get_y());
}

bool Move::is_promotion() {
    return promotion_piece != 'x';
}