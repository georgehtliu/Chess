#include <sstream>
#include "human.h"
#include "board.h"

Move human_get_next_move(Player *p, Board *b) {
    bool first = true;
    while (true) {
        if (p->white && first) {
            std::cout << "Enter (WHITE) move: " << std::endl;
        } else if (!p->white && first) {
            std::cout << "Enter (BLACK) move: " << std::endl;
        }
        
        first = false;

        std::string input;

        if (std::cin.eof()) {
            return {p, nullptr, nullptr, nullptr, nullptr, 'x', true};
        }

        std::getline(std::cin, input);
        
        if (input.empty()) {
            continue;
        }

        std::istringstream ss(input);

        std::string cmd, pos1, pos2;
        ss >> cmd;

        // Check for resign
        if (cmd == "resign") {
            Move m = Move(p, nullptr, nullptr, nullptr, nullptr, 'x', true);
            return m;
        } else if (cmd == "move") {
            int x1, y1, x2, y2;
            char promotion = 'x';

            try {
                ss >> pos1 >> pos2;
                if (!ss.eof()) {
                    ss >> promotion;
                }

                x1 = pos1.at(0) - 'a';
                y1 = pos1.at(1) - '0' - 1;

                x2 = pos2.at(0) - 'a';
                y2 = pos2.at(1) - '0' - 1;

                Move m = Move(p,
                              b->get_spot(x1, y1),
                              b->get_spot(x2, y2),
                              b->get_spot(x1, y1)->get_piece(),
                              b->get_spot(x2, y2)->get_piece(),
                              promotion);

                if (b->check_valid_move(m)) {
                    return m;
                } else {
                    std::cout << "That is not a valid move! Try again." << std::endl;
                }
            } catch (...) {
                std::cout << "Invalid input. Try again." << std::endl;
            }
        } else {
            std::cout << "Invalid input. Try again." << std::endl;
        }
    }
}