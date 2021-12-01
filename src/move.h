#ifndef _MOVE_H_
#define _MOVE_H_

#include "math.h"

class Player;
class Spot;
class Piece;

class Move
{

public:
    const int ONE_STRAIGHT_DIST = 1;
    const int ONE_DIAG_DIST = sqrt(2);
    const Player *player;
    const Spot *startPos;
    const Spot *endPos;
    const Piece *piecedMoved;
    const Piece *pieceKilled;
    const bool isCastle;
    const bool isEnPassant;
    const bool isResign;
    bool isDiagonal();
    bool isStraight();
    bool isHorizontal();
    bool isVertical();
    int euclidDist();
};

#endif