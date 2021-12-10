#include "knight.h"

Knight::Knight(bool white) {
    this->white = white;
    if (white) {
        this->text_repr = 'N';
    } else {
        this->text_repr = 'n';
    }
}

bool Knight::valid_move(Move mv) 
{
    return ((mv.x_dist() == mv.FORWARD_UNIT && mv.y_dist() == 2 * mv.FORWARD_UNIT) || (mv.x_dist() == 2 * mv.FORWARD_UNIT && mv.y_dist() == mv.FORWARD_UNIT));
}
