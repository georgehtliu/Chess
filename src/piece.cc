#include "piece.h"
#include "move.h"

void Piece::set_white(bool white) {
    this->white = white;
}

bool Piece::is_white() const {
    return white;
}

int Piece::get_value() const {
    return value;
}

bool Piece::is_alive() {
    return alive;
}

bool Piece::is_pawn() const {
    return false;
}

bool Piece::is_king() const {
    return false;
}

bool Piece::is_rook() const {
    return false;
}

char Piece::get_text() {
    return text_repr;
}

void Piece::set_killed() {
    alive = false;
}

void Piece::set_alive() {
    alive = true;
}

bool Piece::in_board(int x, int y) {
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

void Piece::increment(int x_inc, int y_inc, int x_start, int y_start, std::vector<std::pair<int, int>> *paths) {
    while (x_start < 8 && y_start < 8 && x_start >= 0 && y_start >= 0) {
        paths->push_back(std::make_pair(x_start, y_start));
        x_start += x_inc;
        y_start += y_inc;
    }
}

bool Piece::has_moved() {
    return moved;
}

void Piece::set_has_moved(bool has_moved) {
    moved = has_moved;
}

std::string Piece::get_white_square_img() const {
    return white_square;
}

std::string Piece::get_black_square_img() const {
    return black_square;
}

std::vector<std::pair<int, int>> Piece::generate_paths(std::pair<int, int> pos) {
    (void)pos;
    return {};
}
