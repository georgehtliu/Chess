#include "queen.h"

bool Queen::valid_move(Move mv)
{
    return (mv.is_vertical() || mv.is_horizontal()) || mv.is_diagonal();
}