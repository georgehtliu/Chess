/*
    chess.cc
    November 29, 2021

    Authors:
    David Gurevich
*/

#include <iostream>
#include "board.h"
#include "graphics_observer.h"
#include "pieces/king.h"

int main() {
    Board b;
    std::vector<std::unique_ptr<Observer>> observers;

    std::shared_ptr<King> k = std::make_shared<King>(true);

    b.add_piece(k.get(), b.get_spot(2, 2));

    observers.push_back(std::make_unique<GraphicsObserver>(&b));
    observers[0]->notify();
    observers[0]->notify(b.get_spot(2, 2));

    char c;
    std::cin >> c;

    return 0;
}
