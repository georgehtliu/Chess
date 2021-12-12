/*
    game.cc
    David Gurevich
    CS 246
*/

#include "game.h"

// TEMP
#include <iostream>

Game::Game(PlayerType white_lvl, PlayerType black_lvl, bool normal_game): white_lvl{white_lvl}, black_lvl{black_lvl} {
    switch (white_lvl) {
        case PlayerType::Human: 
            white = std::make_shared<Player>(false);
            break;
        // Add cases for AI
        default: 
            std::cout << "UNIMPLEMENTED" << std::endl; 
            white = std::make_shared<Player>(false);
    }

    switch (black_lvl) {
        case PlayerType::Human: 
            black = std::make_shared<Player>(true);
            break;
        // Add cases for AI
        default: 
            std::cout << "UNIMPLEMENTED" << std::endl;
            black = std::make_shared<Player>(true);
    }

    // Make new board
    board = std::make_shared<Board>(this->white.get(), this->black.get());    

    if (normal_game) {
        board->gen_standard_layout();
    } else {
        board->setup_mode();
    }
    mode = Mode::Setup;
}

void Game::run_game() {
    char c;
    std::cin >> c;
}

int Game::get_white_score() {
    return white->get_score();
}

int Game::get_black_score() {
    return black->get_score();
}

PlayerType Game::get_white_player_type() {
    return white_lvl; 
}

PlayerType Game::get_black_player_type() {
    return black_lvl;
}

Player* Game::get_white_player() {
    return white.get();
}

Player* Game::get_black_player() {
    return black.get();
}

Mode Game::get_game_mode() {
    return mode;
}

Board* Game::get_board() {
    return board.get();
}