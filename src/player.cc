//
// Created by david on 12/10/21.
//
#include <iostream>

#include "player.h"
#include "king.h"
#include "queen.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "pawn.h"


void Player::gen_standard_pieces() {
    pieces.push_back(std::make_shared<King>(white));
    pieces.push_back(std::make_shared<Queen>(white));
    pieces.push_back(std::make_shared<Rook>(white));
    pieces.push_back(std::make_shared<Rook>(white));
    pieces.push_back(std::make_shared<Knight>(white));
    pieces.push_back(std::make_shared<Knight>(white));
    pieces.push_back(std::make_shared<Bishop>(white));
    pieces.push_back(std::make_shared<Bishop>(white));

    for (int i = 0; i < 8; i++) {
        pieces.push_back(std::make_shared<Pawn>(white));
    }
}

void Player::add_piece(std::shared_ptr<Piece> p) {
    pieces.push_back(p);
}

int Player::get_score() {
    return score;
}

Piece* Player::get_last_piece() {
    if (!pieces.empty()) {
        return pieces.back().get();
    }
    return nullptr;
}

Piece* Player::get_nth_piece(size_t n) {
    if (n >= pieces.size()) {
        return nullptr;
    }

    return pieces[n].get();
}

bool Player::is_white() const {
    return white;
}

int Player::incr_score() {
    return ++score;
}

bool Player::has_valid_moves() {
    return false;
}

Move Player::get_next_move(const Board *b) {
    (void)b;
    return Move(nullptr, nullptr, nullptr, nullptr);
}

void Player::remove_last_piece() {
    pieces.pop_back();
}
