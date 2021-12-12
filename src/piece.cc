#include "../include/piece.h"
#include "../include/move.h"

void Piece::set_white(bool white) {
    this->white = white;
}

bool Piece::is_white() const {
    return white;
}

bool Piece::is_alive() {
    return alive;
}

bool Piece::is_pawn() const {
    return false;
}

bool Piece::is_king() const {
    return false;
}

char Piece::get_text() {
    return text_repr;
}

void Piece::set_killed() {
    alive = false;
}
