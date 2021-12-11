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
    if (piece == 'p') {
        auto p = std::make_shared<Pawn>(false);
        b->get_spot(x, y)->set_piece(p.get());
        b->addPieceBlack(p);
        b->addPiece(p.get());
    } else if (piece == 'P') {
        auto p = std::make_shared<Pawn>(true);
        b->get_spot(x, y)->set_piece(p.get());
        b->addPieceWhite(p);
        b->addPiece(p.get());
    } else if (piece == 'n') {
        auto p = std::make_shared<Knight>(false);
        b->get_spot(x, y)->set_piece(p.get());
        b->addPieceBlack(p);
        b->addPiece(p.get());
    } else if (piece == 'N') {
        auto p = std::make_shared<Knight>(true);
        b->get_spot(x, y)->set_piece(p.get());
        b->addPieceWhite(p);
        b->addPiece(p.get());
    } else if (piece == 'b') {
        auto p = std::make_shared<Bishop>(false);
        b->get_spot(x, y)->set_piece(p.get());
        b->addPieceBlack(p);
        b->addPiece(p.get());
    } else if (piece == 'B') {
        auto p = std::make_shared<Bishop>(true);
        b->get_spot(x, y)->set_piece(p.get());
        b->addPieceWhite(p);
        b->addPiece(p.get());
    } else if (piece == 'k') {
        auto p = std::make_shared<King>(false);
        b->get_spot(x, y)->set_piece(p.get());
        b->addPieceBlack(p);
        b->addPiece(p.get());
    } else if (piece == 'K') {
        auto p = std::make_shared<King>(true);
        b->get_spot(x, y)->set_piece(p.get());
        b->addPieceWhite(p);
        b->addPiece(p.get());
    } else if (piece == 'q') {
        auto p = std::make_shared<Queen>(false);
        b->get_spot(x, y)->set_piece(p.get());
        b->addPieceBlack(p);
        b->addPiece(p.get());
    } else if (piece == 'Q') {
        auto p = std::make_shared<Queen>(true);
        b->get_spot(x, y)->set_piece(p.get());
        b->addPieceWhite(p);
        b->addPiece(p.get());
    } else if (piece == 'r') {
        auto p = std::make_shared<Rook>(false);
        b->get_spot(x, y)->set_piece(p.get());
        b->addPieceBlack(p);
        b->addPiece(p.get());
    } else if (piece == 'R') {
        auto p = std::make_shared<Rook>(true);
        b->get_spot(x, y)->set_piece(p.get());
        b->addPieceWhite(p);
        b->addPiece(p.get());
    }
}

int main() {
    Board b;
    std::vector<std::unique_ptr<Observer>> observers;

    observers.push_back(std::make_unique<TextObserver>(&b));
    observers.push_back(std::make_unique<GraphicsObserver>(&b));

    bool done = false;
    while (!done) {
        std::string command;
        char piece;
        std::string position;
        std::cin >> command;

        observers[0]->notify();
        observers[1]->notify();

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
    }
}