#include "king.h"

bool King::getHasMoved()
{
    return hasMoved;
}

bool King::validCastle(Move mv)
{
    if (hasMoved)
        return false;
    return mv.isHorizontal() && mv.euclidDist() == CASTLE_DISTANCE;
}

bool King::validMove(Move mv)
{
    int mvEuclidDist = mv.euclidDist();

    if (!mv.isCastle)
    {
        return (mv.isDiagonal() && mvEuclidDist == mv.ONE_DIAG_DIST) || (mv.isStraight() && mvEuclidDist == mv.ONE_STRAIGHT_DIST);
    }

    return validCastle(mv);
}