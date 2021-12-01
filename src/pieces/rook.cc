#include "rook.h"

bool Rook::getHasMoved()
{
    return hasMoved;
}

bool Rook::validMove(Move mv)
{
    return mv.isVertical() || mv.isHorizontal();
}