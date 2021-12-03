/*
    board.cc
    David Gurevich
    CS 246
*/

#include "board.h"

Board::Board() {
    for (int i = 0; i < 8; i++) {
        positions.push_back(std::vector<Spot>());
        for (int j = 0; j < 8; j++) {
            positions[i].push_back(Spot(i, j));
        }
    }

    white_move = true;
}

void Board::attach(Observer *o) {
    observers.emplace_back(o);
}

void Board::detach(Observer *o) {
    for (auto it = observers.begin(); it != observers.end();) {
        if (*it == o) it = observers.erase(it);
        else ++it;
    }
}

void Board::notify_observers() {
    for (auto &ob : observers) ob->notify();
}

Spot* Board::get_spot(int x, int y) {
    return &positions[x][y];
}

void Board::add_piece(Piece *p, Spot *s) {
    s->set_piece(p);
}
