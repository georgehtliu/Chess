#include "../include/piece.h"
#include "../include/move.h"


bool Piece::is_white() const {
    return white;
}

bool Piece::is_alive() {
    return alive;
}

char Piece::get_text() {
    return text_repr;
}

void Piece::set_killed() {
    alive = false;
}