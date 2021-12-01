/*
    chess.cc
    November 29, 2021

    Authors:
    David Gurevich
*/

#include <iostream>
#include "board.h"
#include "graphics_observer.h"

int main() {
    Board b;
    std::vector<std::unique_ptr<Observer>> observers;

    observers.push_back(std::make_unique<GraphicsObserver>(&b));
    observers[0]->notify();

    char c;
    std::cin >> c;
}
