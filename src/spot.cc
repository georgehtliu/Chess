/*
    spot.cc
    David Gurevich
    CS 246
*/

#include "../include/spot.h"

Spot::Spot(int x, int y) : x{x}, y{y}, white{(x + y) % 2 == 0} {}
Spot::Spot(int x, int y, Piece *p) : p{p}, x{x}, y{y}, white{(x + y) % 2 == 0} {}

int Spot::get_x() const
{
    return x;
}

int Spot::get_y() const
{
    return y;
}

bool Spot::is_white() const
{
    return white;
}

Piece *Spot::get_piece() const
{
    return p;
}

void Spot::set_piece(Piece *p)
{
    this->p = p;
}

void Spot::is_blank()
{
    return p == nullptr;
}

bool Spot::in_bounds() const
{
    return (x >= 0 && x < 8) && (y >= 0 && y < 8);
}