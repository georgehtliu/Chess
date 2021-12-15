/*
    game.cc
    David Gurevich
    CS 246
*/

#include "game.h"
#include "player.h"

#include "text_observer.h"
#include "graphics_observer.h"


Game::Game(PlayerType white_lvl, PlayerType black_lvl) {
    white = std::make_shared<Player>(true, white_lvl);
    black = std::make_shared<Player>(false, black_lvl);

    // Make new board
    board = std::make_shared<Board>(this->white.get(), this->black.get());
    board->gen_standard_layout();

    // Initialize observers
    t = std::make_unique<TextObserver>(board.get());
    g = std::make_unique<GraphicsObserver>(board.get());

    mode = Mode::Ready;
}

Game::Game() {
    white = std::make_shared<Player>(true, PlayerType::Human);
    black = std::make_shared<Player>(false, PlayerType::Human);

    // Make new board
    board = std::make_shared<Board>(white.get(), black.get());

    // Initialize Observers
    t = std::make_shared<TextObserver>(board.get());
    // g = std::make_shared<GraphicsObserver>(board.get());

    mode = Mode::Setup;
}

GameResult Game::run_game() {
    board->notify_observers();

    // Main Game loop
    while (true) {
        Move m = board->get_current_player()->get_next_move(board.get());

        if (m.is_resign) {
            if (board->white_to_move()) {
                return GameResult::BlackWin;
            } else {
                return GameResult::WhiteWin;
            }
        }

        board->execute_move(m);
        board->notify_observers(m);

        if (board->in_checkmate()) {
            if (board->white_to_move()) {
                return GameResult::BlackWin;
            } else {
                return GameResult::WhiteWin;
            }
        } else if (board->in_stalemate()) {
            return GameResult::Tie;
        }
    }
}

Player *Game::get_white_player() {
    return white.get();
}

Player *Game::get_black_player() {
    return black.get();
}

Mode Game::get_game_mode() {
    return mode;
}

Board *Game::get_board() {
    return board.get();
}

void Game::set_game_mode(Mode m) {
    mode = m;
}

void Game::set_white_type(PlayerType type) {
    white->set_type(type);
}

void Game::set_black_type(PlayerType type) {
    black->set_type(type);
}

void Game::destroy_observers() {
    t.reset();
    g.reset();
}