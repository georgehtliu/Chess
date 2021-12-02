#include "queen.h"

bool Queen::valid_move(Move mv)
{
    return (mv.isVertical() || mv.isHorizontal()) || mv.isDiagonal();
}