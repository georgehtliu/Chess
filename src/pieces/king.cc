#include "king.h"

#define STB_IMAGE_IMPLEMENTATION
#define STBI_ONLY_PNG
#include "stb_image.h"

King::King(bool white): white{white}, has_moved{false} {
    int _width = 0, _height = 0, _bpp = 0;
    if (white) {
        rgb_image = stbi_load("assets/png/king_w.png", &_width, &_height, &_bpp, 1);
    } else {
        rgb_image = stbi_load("assets/png/king_b.png", &_width, &_height, &_bpp, 1);
    }
}

King::~King() {
    stbi_image_free(rgb_image);
}

bool King::get_has_moved()
{
    return has_moved;
}

bool King::valid_castle(Move mv)
{
    if (has_moved)
        return false;
    return mv.is_horizontal() && mv.euclid_dist() == mv.FORWARD_UNIT * 2;
}

bool King::valid_move(Move mv)
{
    int mvEuclidDist = mv.euclid_dist();

    if (!mv.is_castle)
    {
        return (mv.is_diagonal() && mvEuclidDist == mv.DIAG_UNIT) || ((mv.is_vertical() || mv.is_horizontal()) && mvEuclidDist == mv.FORWARD_UNIT);
    }

    return valid_castle(mv);
}