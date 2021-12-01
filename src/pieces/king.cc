#include "king.h"

bool King::getHasMoved()
{
    return hasMoved;
}

bool King::validCastle(Move mv)
{
    if (hasMoved)
        return false;
    return mv.isHorizontal() && mv.euclidDist() == mv.FORWARD_UNIT * 2;
}

bool King::validMove(Move mv)
{
    int mvEuclidDist = mv.euclidDist();

    if (!mv.isCastle)
    {
        return (mv.isDiagonal() && mvEuclidDist == mv.DIAG_UNIT) || ((mv.isVertical() || mv.isHorizontal()) && mvEuclidDist == mv.FORWARD_UNIT);
    }

    return validCastle(mv);
}