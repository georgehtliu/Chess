//
// Created by david on 12/12/21.
//

#include "computer4.h"
#include "move.h"

Computer4::Computer4(bool white) {
    this->white = white;
}

Move Computer4::get_next_move(Board *b) {
    (void)b;
    return {this, nullptr, nullptr, nullptr};
}
