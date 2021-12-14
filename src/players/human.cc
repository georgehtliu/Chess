//
// Created by david on 12/12/21.
//

#include <sstream>
#include "human.h"
#include "move.h"
#include "board.h"


Human::Human(bool white) {
    this->white = white;
}

Move Human::get_next_move(Board *b) {
    while (true) {
        if (white) {
            std::cout << "Enter (WHITE) move: ";
        } else {
            std::cout << "Enter (BLACK) move: ";
        }

        std::string input;
        std::getline(std::cin, input);

        std::istringstream ss(input);

        std::string cmd, pos1, pos2;
        ss >> cmd;

        // Check for resign
        if (cmd == "resign") {
            Move m = Move(this, nullptr, nullptr, nullptr, nullptr, 'x', true);
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

                Move m = Move(this,
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
