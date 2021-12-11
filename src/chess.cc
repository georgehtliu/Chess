/*
    chess.cc
    November 29, 2021

    Authors:
    David Gurevich
*/

#include <iostream>
#include <sstream>
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

int position_getX(std::string pos) {
    return pos.at(0) - 'a';
}

int position_getY(std::string pos) {
    return 8 - (pos.at(1) - '0');
}

void addPiece(char piece, std::string position, Board * b) {
    int x = position_getX(position);
    int y = position_getY(position);
    // advanced programming skills
    switch (piece) {
        case 'p':
            b->get_spot(x, y)->set_piece(std::make_shared<Pawn>(false).get());
            break;
        case 'P':
            b->get_spot(x, y)->set_piece(std::make_shared<Pawn>(true).get());
            break;
        case 'n':
            b->get_spot(x, y)->set_piece(std::make_shared<Knight>(false).get());
            break;
        case 'N':
            b->get_spot(x, y)->set_piece(std::make_shared<Knight>(true).get());
            break;
        case 'b':
            b->get_spot(x, y)->set_piece(std::make_shared<Bishop>(false).get());
            break;
        case 'B':
            b->get_spot(x, y)->set_piece(std::make_shared<Bishop>(true).get());
            break;
        case 'k':
            b->get_spot(x, y)->set_piece(std::make_shared<King>(false).get());
            break;
        case 'K':
            b->get_spot(x, y)->set_piece(std::make_shared<King>(true).get());
            break;
        case 'q':
            b->get_spot(x, y)->set_piece(std::make_shared<Queen>(false).get());
            break;
        case 'Q':
            b->get_spot(x, y)->set_piece(std::make_shared<Queen>(true).get());
            break;
        case 'r':
            b->get_spot(x, y)->set_piece(std::make_shared<Rook>(false).get());
            break;  
        case 'R':
            b->get_spot(x, y)->set_piece(std::make_shared<Rook>(true).get());
            break; 
    }
}

int main() {
    Board b;
    std::vector<std::unique_ptr<Observer>> observers;

    observers.push_back(std::make_unique<TextObserver>(&b));

    // setup mode
    bool done = false;
    while (!done) {
        std::string command;
        char piece;
        std::string position;
        std::cin >> command;

        if (std::cin.eof()) break;
        if (command == "done") {
            done = true;
        } else if (command == "+") {
            std::cin >> piece;
            std::cin >> position;
            addPiece(piece, position, &b);
        } else if (command == "-") {
            std::cin >> position;
            b.get_spot(position_getX(position), position_getY(position))->remove_piece();
        }

        // } else if (command == "=") {

        // }
        observers[0]->notify();
        
    }

}