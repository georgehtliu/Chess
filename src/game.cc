/*
    game.cc
    David Gurevich
    CS 246
*/

#include "game.h"
#include "human.h"

#include "text_observer.h"
#include "graphics_observer.h"

// TEMP
#include <iostream>
#include <vector>

Game::Game(PlayerType white_lvl, PlayerType black_lvl): white_lvl{white_lvl}, black_lvl{black_lvl} {
    switch (white_lvl) {
        case PlayerType::HumanType: 
            white = std::make_shared<Human>(true);
            break;
        case AI1:
            white = std::make_shared<Computer1>(true);
            break;
        case AI2:
            white = std::make_shared<Computer2>(true);
            break;
        case AI3:
            white = std::make_shared<Computer3>(true);
            break;
        case AI4:
            white = std::make_shared<Computer4>(true);
            break;
    }

    switch (black_lvl) {
        case PlayerType::HumanType: 
            black = std::make_shared<Human>(false);
            break;
        case AI1:
            black = std::make_shared<Computer1>(false);
            break;
        case AI2:
            black = std::make_shared<Computer2>(false);
            break;
        case AI3:
            black = std::make_shared<Computer3>(false);
            break;
        case AI4:
            black = std::make_shared<Computer4>(false);
            break;
    }


    // Make new board
    board = std::make_shared<Board>(this->white.get(), this->black.get());    
    board->gen_standard_layout();

    // Initialize observers
    t = std::make_shared<TextObserver>(board.get());
    g = std::make_shared<GraphicsObserver>(board.get());

    mode = Mode::Ready;
}

Game::Game() {
    white = std::make_shared<Player>();
    black = std::make_shared<Player>();

    // Make new board
    board = std::make_shared<Board>(white.get(), black.get());

    // Initialize Observers
    t = std::make_shared<TextObserver>(board.get());
    // g = std::make_shared<GraphicsObserver>(board.get());

    mode = Mode::Setup;
}

void Game::run_game() {
    board->notify_observers();
    auto vec = white->all_next_moves(board.get());
    std::cout << "TEMPORARY" << std::endl;
    for (auto i : vec) {
        std::cout << i.end_pos->get_x() << i.end_pos->get_y() << i.piece_moved->get_text() << std::endl;
    }


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

void Game::set_game_mode(Mode m) {
    mode = m;
}

void Game::set_white_type(PlayerType type) {
    switch (type) {
        case HumanType:
            white = std::dynamic_pointer_cast<Human>(white);
            break;
        case AI1:
            white = std::dynamic_pointer_cast<Computer1>(white);
            break;
        case AI2:
            white = std::dynamic_pointer_cast<Computer2>(white);
            break;
        case AI3:
            white = std::dynamic_pointer_cast<Computer3>(white);
            break;
        case AI4:
            white = std::dynamic_pointer_cast<Computer4>(white);
            break;
    }
}

void Game::set_black_type(PlayerType type) {
    switch (type) {
        case HumanType:
            black = std::dynamic_pointer_cast<Human>(black);
            break;
        case AI1:
            black = std::dynamic_pointer_cast<Computer1>(black);
            break;
        case AI2:
            black = std::dynamic_pointer_cast<Computer2>(black);
            break;
        case AI3:
            black = std::dynamic_pointer_cast<Computer3>(black);
            break;
        case AI4:
            black = std::dynamic_pointer_cast<Computer4>(black);
            break;
    }

}
