#include "bishop.h"

bool Bishop::valid_move(Move mv) 
{
    return mv.is_diagonal();
}
