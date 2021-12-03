#include "piece.h"
#include "move.h"

bool Piece::is_white() const
{
    return white;
}

bool Piece::is_alive()
{
    return alive;
}

Piece::~Piece()
{
}