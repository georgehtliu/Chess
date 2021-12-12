/*
    game.h
    David Gurevich
    CS 246
*/

#ifndef CHESS_INCLUDE_GAME_H_
#define CHESS_INCLUDE_GAME_H_

#include "player.h"
#include "board.h"

#include <memory>

enum Mode{Setup, InGame, Finished};
enum PlayerType{Human, AI1, AI2, AI3, AI4};

class Game {
    std::shared_ptr<Player> white;
    std::shared_ptr<Player> black;

    PlayerType white_lvl;
    PlayerType black_lvl;
    
    std::shared_ptr<Board> board;

    Mode mode;

public:
    Game(PlayerType white_lvl, PlayerType black_lvl, bool normal_game=true);
    ~Game() = default;

    void run_game();

    int get_white_score();
    int get_black_score();

    PlayerType get_white_player_type();
    PlayerType get_black_player_type();

    Player* get_white_player();
    Player* get_black_player();

    Mode get_game_mode();
    Board* get_board();


};

#endif // CHESS_INCLUDE_GAME_H_