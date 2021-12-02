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

int main() {
    Board b;
    std::vector<std::unique_ptr<Observer>> observers;
    
    std::cout << "Would you like to play terminal or graphical chess? (t/g)" << std::endl;
    char c;
    std::cin >> c;
    if (c == 't') {
        observers.push_back(std::make_unique<TextObserver>(&b));
    } else {
        observers.push_back(std::make_unique<GraphicsObserver>(&b));
    } 
    observers[0]->notify();
    std::cin >> c;
}
