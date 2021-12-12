/*
    board.cc
    David Gurevich
    CS 246
*/

#include "board.h"
#include "pieces/king.h"
#include "pieces/bishop.h"
#include "pieces/knight.h"
#include "pieces/pawn.h"
#include "pieces/queen.h"
#include "pieces/rook.h"
#include "text_observer.h"

Board::Board(Player* white, Player* black): 
    white{white}, 
    black{black}, 
    white_king_spot{std::make_shared<Spot>(4, 7).get()}, 
    black_king_spot{std::make_shared<Spot>(0, 7).get()}
{
    // y=7 is the bottom of the board (d1)
    for (int i = 0; i < ROWS; i++)
    {
        positions.push_back(std::vector<Spot>());
        for (int j = 0; j < COLS; j++)
        {
            positions[i].push_back(Spot(i, j));
        }
    }
    white_move = true;
}

void Board::attach(Observer *o)
{
    observers.push_back(o);
}

void Board::detach(Observer *o)
{
    for (auto it = observers.begin(); it != observers.end();)
    {
        if (*it == o)
            it = observers.erase(it);
        else
            ++it;
    }
}

void Board::notify_observers()
{
    for (auto &ob : observers)
        ob->notify();
}

int position_getX(std::string pos) {
    return pos.at(0) - 'a';
}

int position_getY(std::string pos) {
    return 8 - (pos.at(1) - '0');
}

void Board::gen_standard_layout() {
    // White pieces
    white->gen_standard_pieces();
    get_spot(3, 7)->set_piece(white->get_nth_piece(0));
    get_spot(4, 7)->set_piece(white->get_nth_piece(1));
    get_spot(0, 7)->set_piece(white->get_nth_piece(2));
    get_spot(7, 7)->set_piece(white->get_nth_piece(3));
    get_spot(1, 7)->set_piece(white->get_nth_piece(4));
    get_spot(6, 7)->set_piece(white->get_nth_piece(5));
    get_spot(2, 7)->set_piece(white->get_nth_piece(6));
    get_spot(5, 7)->set_piece(white->get_nth_piece(7));
    for (int i = 0; i < 8; i++) {
        get_spot(i, 6)->set_piece(white->get_nth_piece(8 + i));
    }

    // Black pieces
    black->gen_standard_pieces();
    get_spot(3, 0)->set_piece(black->get_nth_piece(0));
    get_spot(4, 0)->set_piece(black->get_nth_piece(1));
    get_spot(0, 0)->set_piece(black->get_nth_piece(2));
    get_spot(7, 0)->set_piece(black->get_nth_piece(3));
    get_spot(1, 0)->set_piece(black->get_nth_piece(4));
    get_spot(6, 0)->set_piece(black->get_nth_piece(5));
    get_spot(2, 0)->set_piece(black->get_nth_piece(6));
    get_spot(5, 0)->set_piece(black->get_nth_piece(7));
    for (int i = 0; i < 8; i++) {
        get_spot(i, 1)->set_piece(black->get_nth_piece(8 + i));
    }
}

void Board::add_piece(char piece, std::string position) {
    int x = position_getX(position);
    int y = position_getY(position);
    // advanced programming skills
    if (piece == 'p') {
        black->add_piece(std::make_shared<Pawn>(false));
        get_spot(x, y)->set_piece(black->get_last_piece());
    } else if (piece == 'P') {
        white->add_piece(std::make_shared<Pawn>(true));
        get_spot(x, y)->set_piece(white->get_last_piece());
    } else if (piece == 'n') {
        black->add_piece(std::make_shared<Knight>(false));
        get_spot(x, y)->set_piece(black->get_last_piece());
    } else if (piece == 'N') {
        white->add_piece(std::make_shared<Knight>(true));
        get_spot(x, y)->set_piece(white->get_last_piece());
    } else if (piece == 'b') {
        black->add_piece(std::make_shared<Bishop>(false));
        get_spot(x, y)->set_piece(black->get_last_piece());
    } else if (piece == 'B') {
        white->add_piece(std::make_shared<Bishop>(true));
        get_spot(x, y)->set_piece(white->get_last_piece());
    } else if (piece == 'k') {
        black->add_piece(std::make_shared<King>(false));
        get_spot(x, y)->set_piece(black->get_last_piece());
    } else if (piece == 'K') {
        white->add_piece(std::make_shared<King>(true));
        get_spot(x, y)->set_piece(white->get_last_piece());
    } else if (piece == 'q') {
        black->add_piece(std::make_shared<Queen>(false));
        get_spot(x, y)->set_piece(black->get_last_piece());
    } else if (piece == 'Q') {
        white->add_piece(std::make_shared<Queen>(true));
        get_spot(x, y)->set_piece(white->get_last_piece());
    } else if (piece == 'r') {
        black->add_piece(std::make_shared<Rook>(false));
        get_spot(x, y)->set_piece(black->get_last_piece());
    } else if (piece == 'R') {
        white->add_piece(std::make_shared<Rook>(true));
        get_spot(x, y)->set_piece(white->get_last_piece());
    }
}

bool Board::setup_complete() {
    // condition 1: no pawns in row 1 or 8
    for (int i = 0; i < 8; i++) {
        if (get_spot(i, 7)->get_piece() && get_spot(i, 7)->get_piece()->is_pawn()) return false;
        if (get_spot(i, 0)->get_piece() && get_spot(i, 0)->get_piece()->is_pawn()) return false;
    }

    // condition 2: 2 kings on the board
    int white_king_count = 0;
    int black_king_count = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (get_spot(i, j)->get_piece() && get_spot(i, j)->get_piece()->is_king() && get_spot(i, j)->get_piece()->is_white()) {
                white_king_count += 1;
            } else if (get_spot(i, j)->get_piece() && get_spot(i, j)->get_piece()->is_king()) {
                black_king_count += 1;
            }
        }
    }
    if (!(white_king_count == 1 && black_king_count == 1)) return false;

    // condition 3: neither king is in check -- TODO

    return true;
}

void Board::setup_mode() {
    std::ifstream f("assets/text/setup_mode.txt");
    if (f.is_open())
        std::cout << f.rdbuf();

    bool done = false;
    std::vector<std::unique_ptr<Observer>> observers;
    observers.push_back(std::make_unique<TextObserver>(this));
    while (!done) {
        observers[0]->notify();
        std::string command;
        char piece;
        std::string position;
        std::cin >> command;

        if (std::cin.eof()) break;
        if (command == "done") {
            if (setup_complete()) {
                done = true;
            } else {
                std::cout << "Ensure that all requirements for setup are met!" << std::endl;
            }
            
        } else if (command == "+") {
            std::cin >> piece;
            std::cin >> position;
            add_piece(piece, position);
        } else if (command == "-") {
            std::cin >> position;
            get_spot(position_getX(position), position_getY(position))->remove_piece();
        }
    }
}

Spot * Board::get_spot(int x, int y) {
    return &positions[x][y];
}

bool Board::same_team(Spot *s1, Spot *s2) {
    if (s1->is_blank() || s2->is_blank()) return false;
    Piece *p1 = s1->get_piece();
    Piece *p2 = s2->get_piece();
    return p1->is_white() == p2->is_white();
}

bool Board::valid_path(Spot *from, Spot *to)
{
    if (from->is_blank()) return false;
    Player *p;
    Piece *piece_from = from->get_piece();
    Piece *piece_to = to->get_piece();

    if (white_move) {
        p = white;
    }
    else {
        p = black;
    }

    Move mv = Move{p, from, to, piece_from, piece_to};
    return piece_from->valid_move(mv);
}

bool Board::is_attacking_path(Spot *end, Spot *attack_candidate_spot) // has a path attacking end
{
    if (attack_candidate_spot->is_blank()) return false;
    if (same_team(end, attack_candidate_spot))
        return false;

    // (opposite team or blank) and valid path
    return valid_path(attack_candidate_spot, end);
}

bool Board::search_attacker(Spot *spot, int x_inc, int y_inc) {

    Spot *runner = spot;

    while (runner->in_bounds())
    {
        runner = get_spot(runner->get_x() + x_inc, runner->get_y() + y_inc);
        if (is_attacking_path(spot, runner))
        {
            return true;
        }
        else if (runner->is_blank())
        {
            continue;
        }
        else
        {
            return false;
        }
    }

    return false;

}

bool Board::under_attack_vertical(Spot *spot)
{
    return search_attacker(spot, 0, 1) || search_attacker(spot, 0, -1);
}

bool Board::under_attack_horizontal(Spot *spot)
{

    return search_attacker(spot, 1, 0) || search_attacker(spot, -1, 0);
}

bool Board::under_attack_diagonal(Spot *spot)
{
    return search_attacker(spot, 1, 1) || search_attacker(spot, -1, 1) || search_attacker(spot, -1, -1) || search_attacker(spot, 1, -1);
}

bool Board::under_attack_knight(Spot *spot) {
    std::vector<Spot *> knight_threat_spots;

    // should be 8 positions
    for (int i = 1; i <= 2; i++) {
        for (int j = -2; j <= -1; j++) {
            Spot *spot1 = get_spot(spot->get_x() + i, spot->get_y() + j);
            Spot *spot2 = get_spot(spot->get_x() + j, spot->get_y() + i);
            if (spot1->in_bounds()) {
                knight_threat_spots.push_back(spot1);
            }
            if (spot2->in_bounds()) {
                knight_threat_spots.push_back(spot2);
            }
        }
    }

    for (Spot *attacker_candidate : knight_threat_spots) {
        if (is_attacking_path(spot, attacker_candidate)) return true;
    }
    
    return false;
}

bool Board::under_attack(Spot *spot)
{
    return ((under_attack_vertical(spot) || under_attack_horizontal(spot)) || under_attack_diagonal(spot)) || under_attack_knight(spot);
}


// TODO
bool Board::check_valid_move(Move &mv) {

    // can only move if it's your turn
    bool piece_is_white = ((mv.start_pos)->get_piece())->is_white();
    if ((piece_is_white && !white_move) || (!piece_is_white && white_move)) return false;
    
    // end move cannot be out of bounds
    if (!(mv.end_pos)->in_bounds()) return false;

    // cannot move into own pieces
    if (same_team(mv.start_pos, mv.end_pos)) return false;

    // cannot be in check after move ** HARD **

    // check if piece can move path and check for anything blocking it

    // cannot move other pieces if in check and can only
    // get king to safety/block/capture attack - should be covered by in check after move

    // cannot take king - should already be covered since you must be in check beforehand

    // cannot move somewhere if blocked 

    // castle

    // promotion

    // en passant

    return true;
}


bool Board::same_spot(Spot *s1, Spot *s2) {
    return s1->get_x() == s2->get_x() && s1->get_y() == s2->get_y();
}

void Board::place_piece(Spot *start, Spot *end) {

    // capture piece
    if (!end->is_blank() && !same_team(start, end)) {
       (end->get_piece())->set_killed();
    }

    // end spot now has start's piece
    end->set_piece(start->get_piece());
    start->set_piece(nullptr);

    // if king moves, update king spot
    if (white_move && same_spot(white_king_spot, start)) {
        white_king_spot = end;
    } else if (same_spot(black_king_spot, start)) {
        black_king_spot = end;
    }
}

bool Board::in_check() {

    if (white_move) return under_attack(white_king_spot);

    return under_attack(black_king_spot);
}

void Board::execute_castle(Move &mv) {

    Spot *start = mv.start_pos;
    Spot *end = mv.end_pos;

    // starting rook positions
    Spot *start_queenside_rook_white = get_spot(0, 0);
    Spot *start_kingside_rook_white = get_spot(7, 0);
    Spot *start_kingside_rook_black = get_spot(7, 7);
    Spot *start_queenside_rook_black = get_spot(0, 7);
    
    // end rook positions
    Spot *end_queenside_rook_white = get_spot(3, 0);
    Spot *end_kingside_rook_white = get_spot(5, 0);
    Spot *end_kingside_rook_black = get_spot(5, 7);
    Spot *end_queenside_rook_black = get_spot(3, 7);

    // end king positions
    Spot *queenside_white_end = get_spot(6, 0);
    Spot *queenside_black_end = get_spot(2, 7);

    // place king
    place_piece(start, end);

    // place rook
    Spot *start_rook_spot = nullptr;
    Spot *end_rook_spot = nullptr;

    if (white_move && same_spot(end, queenside_white_end)) { // white queen side

        start_rook_spot = start_queenside_rook_white;
        end_rook_spot = end_queenside_rook_white;

    } else if (white_move) { // white king side

        start_rook_spot = start_kingside_rook_white;
        end_rook_spot = end_kingside_rook_white;

    } else if (!white_move && same_spot(start, queenside_black_end)) { // black queenside

        start_rook_spot = start_queenside_rook_black;
        end_rook_spot = end_queenside_rook_black;

    } else { // black kingside

        start_rook_spot = start_kingside_rook_black;
        end_rook_spot = end_kingside_rook_black;

    }

    place_piece(start_rook_spot, end_rook_spot);
}

void Board::execute_en_passant(Move &mv) {

    Spot *start = mv.start_pos;
    Spot *end = mv.end_pos;

    place_piece(start, end);
    Spot *taken_pawn_spot = nullptr;
    if (white_move) {
        taken_pawn_spot = get_spot(end->get_x(), end->get_y() - 1);
    } else {
        taken_pawn_spot = get_spot(end->get_x(), end->get_y() + 1);
    }

    (taken_pawn_spot->get_piece())->set_killed();
    taken_pawn_spot->set_piece(nullptr);
}

void Board::execute_move(Move &mv) {

    Spot *start = mv.start_pos;
    Spot *end = mv.end_pos;

    // place piece for generic move
    if (!(mv.is_castle || mv.is_en_passant || mv.is_promotion)) {
        place_piece(start, end);
    }

    // perform castle
    if (mv.is_castle) {
        execute_castle(mv);
    }

    // perform en passant
    if (mv.is_en_passant) {
        execute_en_passant(mv);
    }
    
    // promotion TODO: !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // generate function in Piece.h which takes in a bool is_white

    // add move to array
    moves.push_back(mv);

    // change turns
    white_move = !white_move;
}

void Board::set_white(Player* white) {
    this->white = white;
}

void Board::set_black(Player* black) {
    this->black = black;
}

Player* Board::get_black() {
    return black;
}

Player* Board::get_white() {
    return white;
}