#include "piece.h"
#include "move.h"

bool Piece::is_white() {
    return white;
}

bool Piece::is_alive() {
    return alive;
}

char Piece::get_text() {
    return text_repr;
}
