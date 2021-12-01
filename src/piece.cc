#include "piece.h"
#include "move.h"

bool Piece::isWhite()
{
    return white;
}

bool Piece::isAlive()
{
    return alive;
}

Piece::~Piece()
{
}