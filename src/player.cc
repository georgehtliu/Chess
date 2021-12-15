//
// Created by david on 12/10/21.
//
#include <sstream>
#include <iostream>
#include <vector>
#include <utility>

#include "player.h"
#include "king.h"
#include "queen.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "pawn.h"
#include "move.h"
#include "board.h"
#include "human.h"
#include "computer1.h"
#include "computer2.h"
#include "computer3.h"
#include "computer4.h"

Player::Player(bool white, PlayerType type) : white{white}, type{type} {}

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

Piece *Player::get_last_piece() {
    if (!pieces.empty()) {
        return pieces.back().get();
    }
    return nullptr;
}

Piece *Player::get_nth_piece(size_t n) {
    if (n >= pieces.size()) {
        return nullptr;
    }

    return pieces[n].get();
}

bool Player::is_white() const {
    return white;
}

void Player::set_type(PlayerType type) {
    this->type = type;
}

bool Player::has_valid_moves() {
    return false;
}

void Player::remove_last_piece() {
    pieces.pop_back();
}

std::vector<Move> Player::all_next_moves(Board *b) {
    std::vector<Move> all_moves;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            // if there is a piece at the spot and the piece is the player's color
            Piece *p = b->get_spot(i, j)->get_piece();
            if (p && p->is_white() == white) {
                std::vector<std::pair<int, int>> paths = p->generate_paths(std::make_pair(i, j));
                for (auto path: paths) {
                    Piece *killed = b->get_spot(path.first, path.second)->get_piece();
                    Move m{this, b->get_spot(i, j), b->get_spot(path.first, path.second), p, killed};

                    if (b->check_valid_move(m)) {
                        all_moves.push_back(m);
                    }
                }
            }
        }
    }
    return all_moves;
}

Move Player::get_next_move(Board *b) {
    switch (this->type) {
        case Human:
            return human_get_next_move(this, b);
        case AI1:
            return computer1_get_next_move(this, b);
        case AI2:
            return computer2_get_next_move(this, b);
        case AI3:
            return computer3_get_next_move(this, b);
        case AI4:
            return computer4_get_next_move(this, b);
    }
    return {this, nullptr, nullptr, nullptr};
}
