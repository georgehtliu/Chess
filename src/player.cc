//
// Created by david on 12/10/21.
//

#include "player.h"
#include "king.h"
#include "queen.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "pawn.h"

Player::Player(bool white, bool empty): score{0}, white{white} {
    if (!empty) {
        gen_standard_pieces();
    }
}

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

Piece* Player::get_last_piece() {
    if (pieces.size() != 0) {
        return pieces.back().get();
    }
    return nullptr;
}