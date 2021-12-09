/*
    board.cc
    David Gurevich
    CS 246
*/

#include "board.h"

bool checkBounds(int move_x, int move_y, int board_rows, int board_cols) {
    return 
}

Board::Board() {
    for (int i = 0; i < ROWS; i++) {
        positions.push_back(std::vector<Spot>());
        for (int j = 0; j < COLS; j++) {
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

std::shared_ptr<Spot> Board::get_spot(int x, int y) {
    return std::make_shared<Spot>(positions[x][y]);
}

bool Board::checkValidMove(Move mv) {
    if ((mv.end_pos)->)
}