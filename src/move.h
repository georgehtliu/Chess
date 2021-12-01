#ifndef _MOVE_H_
#define _MOVE_H_

class Player;
class Spot;
class Piece;

class Move
{

    const Player *player;
    const Spot *startPos;
    const Spot *endPos;
    const Piece *piecedMoved;
    const Piece *pieceKilled;
    const bool isCastle;
    const bool isEnPassant;
    const bool isResign;

public:
    bool isDiagonal();
    bool isStraight();
};

#endif