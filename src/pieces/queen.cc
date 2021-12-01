#include "queen.h"

bool Queen::validMove(Move mv)
{
    return mv.isStraight() || mv.isDiagonal();
}