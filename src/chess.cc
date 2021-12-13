/*
    chess.cc
    November 29, 2021

    Authors:
    David Gurevich
*/

#include <iostream>
#include <unordered_map>

#include "game.h"

int main() {
    // Welcome message
    std::ifstream welcome("assets/text/welcome.txt");
    if (welcome.is_open())
        std::cout << welcome.rdbuf();

    // Handle score
    double white_score = 0.0;
    double black_score = 0.0;

    // Hold list of games
    std::vector<Game> games;

    // Main menu command interpreter
    std::string cmd;

    // Convert player type command (string) to PlayerType
    std::unordered_map<std::string, PlayerType> player_str_to_type = {
        {"human", PlayerType::HumanType},
        {"computer1", PlayerType::AI1},
        {"computer2", PlayerType::AI2},
        {"computer3", PlayerType::AI3},
        {"computer4", PlayerType::AI4},
    };

    while (true) {
        std::cout << "Enter a command: ";
        std::cin >> cmd;
        if (cmd == "game") {
            std::string white_player;
            std::string black_player;

            std::cin >> white_player >> black_player;

            PlayerType white_player_type, black_player_type;

            try {
                white_player_type = player_str_to_type[white_player];
                black_player_type = player_str_to_type[black_player];
            } catch (const std::out_of_range& oor) {
                std::cout << "Invalid entry for player type. Try again"; 
            }

            if (games.empty() || games.back().get_game_mode() == Mode::Finished) {
                games.emplace_back(white_player_type, black_player_type);
            } else if (games.back().get_game_mode() == Mode::Setup) {
                games.back().set_white_type(white_player_type);
                games.back().set_black_type(black_player_type);
            }

            games.back().run_game();
            break;

        } else if (cmd == "setup") {
            if (games.empty() || games.back().get_game_mode() == Mode::Finished) {
                games.emplace_back();
                games.back().set_game_mode(Mode::Setup);
                games.back().get_board()->setup_mode();
            } else if (games.back().get_game_mode() == Mode::Setup || games.back().get_game_mode() == Mode::Ready) {
                games.back().set_game_mode(Mode::Setup);
                games.back().get_board()->setup_mode();
            }

        } else if (cmd == "quit") {
            break;
        } else {
            std::cout << "Invalid command. Try again." << std::endl;
        }
        std::cout << std::endl;
    }

    // Final Score output
    std::cout << "Final Score: " << std::endl;
    std::cout << "White: " << white_score << std::endl;
    std::cout << "Black: " << black_score << std::endl;
}