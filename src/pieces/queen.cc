#include "queen.h"

bool Queen::validMove(Move mv)
{
    return (mv.isVertical() || mv.isHorizontal()) || mv.isDiagonal();
}