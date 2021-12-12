/*
    chess.cc
    November 29, 2021

    Authors:
    David Gurevich
*/

#include <iostream>
#include <sstream>

#include "game.h"
#include "graphics_observer.h"
#include "text_observer.h"
#include "pieces/king.h"
#include "pieces/bishop.h"
#include "pieces/knight.h"
#include "pieces/pawn.h"
#include "pieces/queen.h"
#include "pieces/rook.h"

// void make_move(std::string start, std::string end, Board * b) {
//     Spot * startp = b->get_spot(position_getX(start), position_getY(start));
//     Spot * endp = b->get_spot(position_getX(end), position_getY(end));
//     Move m{b->get_black(), startp, endp, startp->get_piece(), endp->get_piece(), false, false, false, false};
//     b->execute_move(m);    
// }

int main() {
    // Welcome message
    std::ifstream welcome("assets/text/welcome.txt");
    if (welcome.is_open())
        std::cout << welcome.rdbuf();

    int in_lvl;
    bool done = false;
    // Choose White player type
    PlayerType white_lvl;
    while (!done) {
        std::cout << "Please choose white player type\n==> ";
        std::cin >> in_lvl;

        switch (in_lvl) {
            case 0: 
                white_lvl = PlayerType::Human;
                done = true;
                break;
            case 1: 
                white_lvl = PlayerType::AI1;
                done = true;
                break;
            case 2: 
                white_lvl = PlayerType::AI2;
                done = true;
                break;
            case 3: 
                white_lvl = PlayerType::AI3;
                done = true;
                break;
            case 4: 
                white_lvl = PlayerType::AI4;
                done = true;
                break;
            default: 
                std::cout << "Sorry, that was an invalid entry. Try again." << std::endl;
        }
    }

    done = false;
    // Choose Black player type
    PlayerType black_lvl;
    while (!done) {
        std::cout << "Please choose black player type\n==> ";
        std::cin >> in_lvl;

        switch (in_lvl) {
            case 0: 
                black_lvl = PlayerType::Human;
                done = true;
                break;
            case 1: 
                black_lvl = PlayerType::AI1;
                done = true;
                break;
            case 2: 
                black_lvl = PlayerType::AI2;
                done = true;
                break;
            case 3: 
                black_lvl = PlayerType::AI3;
                done = true;
                break;
            case 4: 
                black_lvl = PlayerType::AI4;
                done = true;
                break;
            default: 
                std::cout << "Sorry, that was an invalid entry. Try again." << std::endl;
        }
    }

    // Default game or setup mode?
    std::cout << "Do you want to set up a custom game?\n==> y[N] ";
    char c;
    std::cin >> c;

    bool custom_game = (c == 'y' || c == 'Y');

    Game g(white_lvl, black_lvl, !custom_game);

    // Text and Graphics
    GraphicsObserver graphics(g.get_board());
    TextObserver text(g.get_board());

    graphics.notify();
    text.notify();

    g.run_game();
}