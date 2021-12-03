#include "piece.h"
#include "move.h"

bool Piece::is_white()
{
    return white;
}

bool Piece::is_alive()
{
    return alive;
}

unsigned char* Piece::get_image() {
    return rgb_image;
}
