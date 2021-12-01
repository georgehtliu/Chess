#include "move.h"
#include "player.h"
#include "spot.h"
#include "piece.h"

bool Move::isDiagonal()
{
    return abs(startPos->get_x() - endPos->get_x()) == abs(startPos->get_y() - endPos->get_y());
}

bool Move::isHorizontal()
{
    return startPos->get_x() == endPos->get_x();
}

bool Move::isVertical()
{
    return startPos->get_y() == endPos->get_y();
}

bool Move::isStraight()
{
    return isVertical() || isHorizontal();
}

int Move::euclidDist()
{
    int deltaX = startPos->get_x() - endPos->get_x();
    int deltaY = startPos->get_y() - endPos->get_y();
    return sqrt(deltaX * deltaX - deltaY * deltaY);
}
