/*
    board.cc
    David Gurevich
    CS 246
*/

#include "board.h"

bool check_bounds(int move_x, int move_y, int board_len) {
    bool x_in_bounds = 0 <= move_x && move_x < board_len;
    bool y_in_bounds = 0 <= move_y && move_y < board_len;
    return x_in_bounds && y_in_bounds;
}

bool check_valid_move(Player player) {

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

bool Board::under_attack(Spot s) {

    // within each type except knight, check if there are pieces blocking it

    // check vertical
    // check horizontal
    // check diagonal
    // check Knight L
    
}

bool Board::checkValidMove(Move mv) {

    int end_x = (mv.end_pos)->get_x();
    int end_y = (mv.end_pos)->get_y();

    if (!(check_bounds(end_x, end_y, COLS)) return false;

}