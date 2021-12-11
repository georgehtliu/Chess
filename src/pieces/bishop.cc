#include "bishop.h"
#include "move.h"

Bishop::Bishop(bool white) {
    this->white = white;
}

bool Bishop::valid_move(Move mv) {
    return mv.is_diagonal();
}
