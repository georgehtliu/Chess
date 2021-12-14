/*
    game.h
    David Gurevich
    CS 246
*/

#ifndef CHESS_INCLUDE_GAME_H_
#define CHESS_INCLUDE_GAME_H_

#include "player.h"
#include "human.h"
#include "computer1.h"
#include "computer2.h"
#include "computer3.h"
#include "computer4.h"

#include "board.h"
#include "text_observer.h"
#include "graphics_observer.h"

#include <memory>

enum Mode{Setup, Ready, InGame, Finished};
enum PlayerType{HumanType, AI1, AI2, AI3, AI4};
enum GameResult{WhiteWin, BlackWin, Tie};

class Game {
    std::shared_ptr<Player> white;
    std::shared_ptr<Player> black;

    PlayerType white_lvl;
    PlayerType black_lvl;

    std::shared_ptr<TextObserver> t;
    std::shared_ptr<GraphicsObserver> g;
    
    std::shared_ptr<Board> board;

    Mode mode;

public: 
    // Default game
    Game(PlayerType white_lvl, PlayerType black_lvl);

    // Setup game
    Game();

    ~Game() = default;

    GameResult run_game();

    int get_white_score();
    int get_black_score();

    PlayerType get_white_player_type();
    PlayerType get_black_player_type();

    Player* get_white_player();
    Player* get_black_player();

    Mode get_game_mode();
    Board* get_board();

    void set_game_mode(Mode m);
    void set_white_type(PlayerType type);
    void set_black_type(PlayerType type);

    void destroy_observers();
};

#endif // CHESS_INCLUDE_GAME_H_