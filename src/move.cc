#include "move.h"
#include "player.h"
#include "spot.h"
#include "piece.h"

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

int Move::euclid_dist()
{
    int delta_x = start_pos->get_x() - end_pos->get_x();
    int delta_y = start_pos->get_y() - end_pos->get_y();
    return sqrt(delta_x * delta_x - delta_y * delta_y);
}
