#ifndef _MOVE_H_
#define _MOVE_H_

#include "math.h"

class Player;
class Spot;
class Piece;

class Move
{

public:
    const int FORWARD_UNIT = 1;
    const int DIAG_UNIT = sqrt(2);
    const Player *player;
    const Spot *startPos;
    const Spot *endPos;
    const Piece *piecedMoved;
    const Piece *pieceKilled;
    const bool isCastle;
    const bool isEnPassant;
    const bool isResign;
    bool isDiagonal();
    bool isHorizontal();
    bool isVertical();
    int euclidDist();
};

#endif