#include "queen.h"

Queen::Queen(bool white) {
    this->white = white;
    if (white) {
        this->text_repr = 'Q';
    } else {
        this->text_repr = 'q';
    }
}

bool Queen::valid_path(Move mv) {
    return (mv.is_vertical() || mv.is_horizontal()) || mv.is_diagonal();
}

