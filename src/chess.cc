/*
    chess.cc
    November 29, 2021

    Authors:
    David Gurevich
*/

#include <iostream>
#include "board.h"
#include "graphics_observer.h"
#include "text_observer.h"

// FIXME: THIS IS SUPER SUPER SUPER TEMPORARY
#include "pieces/king.h"
// We need to build constructors for all of these pieces:
#include "pieces/bishop.h"
#include "pieces/knight.h"
#include "pieces/pawn.h"
#include "pieces/queen.h"
#include "pieces/rook.h"

int main() {
    Board b;
    std::vector<std::unique_ptr<Observer>> observers;

    observers.push_back(std::make_unique<GraphicsObserver>(&b));
    observers[0]->notify();

    // Eventually, we'll want Board->Player to own all the pieces
    std::shared_ptr<Piece> king = std::make_shared<King>(true);

    b.get_spot(2, 2)->set_piece(king.get());
    std::cout << "Contents of (2, 2): " << b.get_spot(2, 2)->get_spot_text() << std::endl;
    b.get_spot(2, 2)->remove_piece();
    std::cout << "Contents of (2, 2): " << b.get_spot(2, 2)->get_spot_text() << std::endl;
    
    char c;
    std::cin >> c;
}