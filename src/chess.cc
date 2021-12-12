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

int position_getX(std::string pos) {
    return pos.at(0) - 'a';
}

int position_getY(std::string pos) {
    return 8 - (pos.at(1) - '0');
}

void add_piece(char piece, std::string position, Board * b) {
    int x = position_getX(position);
    int y = position_getY(position);
    // advanced programming skills
    if (piece == 'p') {
        b->get_black()->add_piece(std::make_shared<Pawn>(false));
        b->get_spot(x, y)->set_piece(b->get_black()->get_last_piece());
    } else if (piece == 'P') {
        b->get_white()->add_piece(std::make_shared<Pawn>(true));
        b->get_spot(x, y)->set_piece(b->get_white()->get_last_piece());
    } else if (piece == 'n') {
        b->get_black()->add_piece(std::make_shared<Knight>(false));
        b->get_spot(x, y)->set_piece(b->get_black()->get_last_piece());
    } else if (piece == 'N') {
        b->get_white()->add_piece(std::make_shared<Knight>(true));
        b->get_spot(x, y)->set_piece(b->get_white()->get_last_piece());
    } else if (piece == 'b') {
        b->get_black()->add_piece(std::make_shared<Bishop>(false));
        b->get_spot(x, y)->set_piece(b->get_black()->get_last_piece());
    } else if (piece == 'B') {
        b->get_white()->add_piece(std::make_shared<Bishop>(true));
        b->get_spot(x, y)->set_piece(b->get_white()->get_last_piece());
    } else if (piece == 'k') {
        b->get_black()->add_piece(std::make_shared<King>(false));
        b->get_spot(x, y)->set_piece(b->get_black()->get_last_piece());
    } else if (piece == 'K') {
        b->get_white()->add_piece(std::make_shared<King>(true));
        b->get_spot(x, y)->set_piece(b->get_white()->get_last_piece());
    } else if (piece == 'q') {
        b->get_black()->add_piece(std::make_shared<Queen>(false));
        b->get_spot(x, y)->set_piece(b->get_black()->get_last_piece());
    } else if (piece == 'Q') {
        b->get_white()->add_piece(std::make_shared<Queen>(true));
        b->get_spot(x, y)->set_piece(b->get_white()->get_last_piece());
    } else if (piece == 'r') {
        b->get_black()->add_piece(std::make_shared<Rook>(false));
        b->get_spot(x, y)->set_piece(b->get_black()->get_last_piece());
    } else if (piece == 'R') {
        b->get_white()->add_piece(std::make_shared<Rook>(true));
        b->get_spot(x, y)->set_piece(b->get_white()->get_last_piece());
    }
}

void make_move(std::string start, std::string end, Board * b) {
    Spot * startp = b->get_spot(position_getX(start), position_getY(start));
    Spot * endp = b->get_spot(position_getX(end), position_getY(end));
    Move m{b->get_black(), startp, endp, startp->get_piece(), endp->get_piece(), false, false, false, false};
    b->execute_move(m);    
}

/*
int main() {
    Board b;
    std::vector<std::unique_ptr<Observer>> observers;

    observers.push_back(std::make_unique<TextObserver>(&b));

    bool done = false;
    while (!done) {
        std::string command;
        char piece;
        std::string position;
        std::cin >> command;

        if (std::cin.eof()) break;
        if (command == "done") {
            done = true;
        } else if (command == "+") {
            std::cin >> piece;
            std::cin >> position;
            add_piece(piece, position, &b);
        } else if (command == "-") {
            std::cin >> position;
            b.get_spot(position_getX(position), position_getY(position))->remove_piece();
        } else if (command == "move") {
            std::string start;
            std::string end;
            std::cin >> start;
            std::cin >> end;
            make_move(start, end, &b);
        }

        // } else if (command == "=") {

        // }
        observers[0]->notify();
        
        
    }
}
*/

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