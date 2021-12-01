#include "move.h"
#include "player.h"
#include "spot.h"
#include "piece.h"
#include "math.h"

bool Move::isDiagonal()
{
    return abs(startPos->get_x() - endPos->get_x()) == abs(startPos->get_y() - endPos->get_y());
}

bool Move::isStraight()
{
    return (startPos->get_x() == endPos->get_x()) || (startPos->get_y() == endPos->get_y());
}
