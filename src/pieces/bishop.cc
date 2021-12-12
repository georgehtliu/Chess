#include "bishop.h"
#include "move.h"

Bishop::Bishop(bool white) {
    this->white = white;
    if (white) {
        this->text_repr = 'B';
    } else {
        this->text_repr = 'b';
    }
}

bool Bishop::valid_path(Move mv) {
    return mv.is_diagonal();
}
