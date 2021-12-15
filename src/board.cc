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
#include <iostream>

Board::Board(Player* white, Player* black): 
    white{white}, 
    black{black}
{
    // y=7 is the bottom of the board (d1)
    for (int i = 0; i < ROWS; i++)
    {
        positions.emplace_back();
        for (int j = 0; j < COLS; j++)
        {
            positions[i].push_back(Spot(i, j));
        }
    }
    white_move = true;
}

bool in_bounds(int x, int y) {
    return (x >= 0 && x < 8) && (y >= 0 && y < 8);
}

void Board::attach(Observer *o) {
    observers.push_back(o);
}

void Board::detach(Observer *o) {
    for (auto it = observers.begin(); it != observers.end();)
    {
        if (*it == o)
            it = observers.erase(it);
        else
            ++it;
    }
}

void Board::detach_all() {
    observers.clear();
}

void Board::notify_observers() {
    for (auto &ob : observers)
        ob->notify();
}

void Board::notify_observers(Spot *s) {
    for (auto &ob : observers)
        ob->notify(s);
}

int position_getX(std::string pos) {
    return pos.at(0) - 'a';
}

int position_getY(std::string pos) {
    return pos.at(1) - '0' - 1;
}

void Board::gen_standard_layout() {
    // White pieces
    white->gen_standard_pieces();
    get_spot(4, 0)->set_piece(white->get_nth_piece(0));
    get_spot(3, 0)->set_piece(white->get_nth_piece(1));
    get_spot(0, 0)->set_piece(white->get_nth_piece(2));
    get_spot(7, 0)->set_piece(white->get_nth_piece(3));
    get_spot(1, 0)->set_piece(white->get_nth_piece(4));
    get_spot(6, 0)->set_piece(white->get_nth_piece(5));
    get_spot(2, 0)->set_piece(white->get_nth_piece(6));
    get_spot(5, 0)->set_piece(white->get_nth_piece(7));
    for (int i = 0; i < 8; i++) {
        get_spot(i, 1)->set_piece(white->get_nth_piece(8 + i));
    }

    // Black pieces
    black->gen_standard_pieces();
    get_spot(4, 7)->set_piece(black->get_nth_piece(0));
    get_spot(3, 7)->set_piece(black->get_nth_piece(1));
    get_spot(0, 7)->set_piece(black->get_nth_piece(2));
    get_spot(7, 7)->set_piece(black->get_nth_piece(3));
    get_spot(1, 7)->set_piece(black->get_nth_piece(4));
    get_spot(6, 7)->set_piece(black->get_nth_piece(5));
    get_spot(2, 7)->set_piece(black->get_nth_piece(6));
    get_spot(5, 7)->set_piece(black->get_nth_piece(7));
    for (int i = 0; i < 8; i++) {
        get_spot(i, 6)->set_piece(black->get_nth_piece(8 + i));
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

    notify_observers(get_spot(x, y));
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
    int white_x = 0;
    int white_y = 0;
    int black_x = 0;
    int black_y = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (get_spot(i, j)->get_piece() && get_spot(i, j)->get_piece()->is_king() && get_spot(i, j)->get_piece()->is_white()) {
                white_king_count += 1;
                white_x = i;
                white_y = j;
            } else if (get_spot(i, j)->get_piece() && get_spot(i, j)->get_piece()->is_king()) {
                black_king_count += 1;
                black_x = i;
                black_y = j;
            }
        }
    }
    if (!(white_king_count == 1 && black_king_count == 1)) return false;

    // condition 3: neither king is in check -- TODO
    Spot *white_king = get_spot(white_x, white_y);
    Spot *black_king = get_spot(black_x, black_y);
    if (under_attack(white_king)) return false;
    if (under_attack(black_king)) return false;

    return true;
}

void Board::setup_mode() {
    std::ifstream f("assets/text/setup_mode.txt");
    if (f.is_open())
        std::cout << f.rdbuf();


    bool done = false;
    notify_observers();
    while (!done) {
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
            Spot *s = get_spot(position_getX(position), position_getY(position));
            s->remove_piece();
            notify_observers(s);
        }
    }
}

Spot * Board::get_spot(int x, int y) {
    return &positions[x][7 - y];
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
    return piece_from->valid_path(mv);
}

bool Board::is_attacking_path(Spot *end, Spot *attack_candidate_spot) // has a path attacking end
{
    if (attack_candidate_spot->is_blank()) return false;
    if (same_team(end, attack_candidate_spot))
        return false;

    // opposite team and valid path
    return valid_path(attack_candidate_spot, end);
}

bool Board::search_attacker(Spot *spot, int x_inc, int y_inc) {

    Spot *runner = spot;

    while (true)
    {
        bool out_of_bounds = !in_bounds(runner->get_x() + x_inc, runner->get_y() + y_inc);
        if (out_of_bounds) break;
        
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

    // should be 8 positions
    if (in_bounds(spot->get_x() - 2, spot->get_y() - 1)) {
        Spot *spot1 = get_spot(spot->get_x() - 2, spot->get_y() - 1);
        if (is_attacking_path(spot, spot1)) return true;
    }
    if (in_bounds(spot->get_x() - 2, spot->get_y() + 1)) {
        Spot *spot2 = get_spot(spot->get_x() - 2, spot->get_y() + 1);
        if (is_attacking_path(spot, spot2)) return true;
    }
    if (in_bounds(spot->get_x() + 2, spot->get_y() - 1)) {
        Spot *spot2 = get_spot(spot->get_x() + 2, spot->get_y() - 1);
        if (is_attacking_path(spot, spot2)) return true;
    }
    if (in_bounds(spot->get_x() + 2, spot->get_y() + 1)) {
        Spot *spot2 = get_spot(spot->get_x() + 2, spot->get_y() + 1);
        if (is_attacking_path(spot, spot2)) return true;
    }
    if (in_bounds(spot->get_x() - 1, spot->get_y() - 2)) {
        Spot *spot2 = get_spot(spot->get_x() - 1, spot->get_y() - 2);
        if (is_attacking_path(spot, spot2)) return true;
    }
    if (in_bounds(spot->get_x() - 1, spot->get_y() + 2)) {
        Spot *spot2 = get_spot(spot->get_x() - 1, spot->get_y() + 2);
        if (is_attacking_path(spot, spot2)) return true;
    }
    if (in_bounds(spot->get_x() + 1, spot->get_y() - 2)) {
        Spot *spot2 = get_spot(spot->get_x() + 1, spot->get_y() - 2);
        if (is_attacking_path(spot, spot2)) return true;
    }
    if (in_bounds(spot->get_x() + 1, spot->get_y() + 2)) {
        Spot *spot2 = get_spot(spot->get_x() + 1, spot->get_y() + 2);
        if (is_attacking_path(spot, spot2)) return true;
    }
    return false;
}

bool Board::under_attack(Spot *spot)
{
    return (under_attack_vertical(spot) || under_attack_horizontal(spot) || under_attack_diagonal(spot) || under_attack_knight(spot));
}

bool Board::is_en_passant(Move &mv) {
    return mv.piece_moved && (mv.piece_moved)->is_pawn() && mv.is_diagonal() && mv.end_pos->is_blank() && mv.euclid_dist() == mv.DIAG_UNIT;
}

bool Board::valid_castle(Move &mv) {

    Piece *king = mv.piece_moved;
    Spot *king_start = mv.start_pos;
    Spot *king_end = mv.end_pos;
    std::pair<Spot*, Spot*> rook_spots = get_rook_castle_spots(king_end);
    Spot *rook_start = rook_spots.first;
    Spot *rook_end = rook_spots.second;

    // if rook does not exist
    if (rook_start->is_blank()) {
        std::cout << "rook starting spot is blank" << std::endl;
        return false;
    }

    // if start and end spots are invalid
    if(!is_valid_king_castle_spots(king_start, king_end)) {
        std::cout << "start and end spots are not valid" << std::endl;
        return false;
    }

    // if king does not exist on starting spot or another piece is on it
    if (king_start->is_blank() || !(king_start->get_piece())->is_king()) {
        std::cout << "king does not exist on starting spot or another piece is on it" << std::endl;
        return false;
    } 

    // if king is not in a position for castle
    if (!rook_start || !rook_end) {
        std::cout << "king is not in a position for castle" << std::endl;
        return false;
    }
    
    if (!(rook_start->get_piece())->is_rook()) {
        std::cout << "rook starting spot piece is not a rook" << std::endl;
        return false;
    }

    Piece *rook = rook_start->get_piece();

    // if in check
    if (in_check()) {
        std::cout << "you are in check so you cannot castle" << std::endl;
        return false;
    } 

    if (!mv.is_castle()) {
        std::cout << "not a castling move" << std::endl;
        return false;
    }

    // if king or rook has moved
    if (rook->has_moved() || king->has_moved()) {
        std::cout << "king or rook has moved" << std::endl;
        return false;
    }

    // check if there are pieces between king and rook and spot under attack
    int inc_x = (king_start->get_x() < rook_start->get_x()) ? 1 : -1;
    for (int x = king_start->get_x(); x != king_start->get_x(); x += inc_x) {
        Spot *between_spot = get_spot(x, king_start->get_y());
        if (!between_spot->is_blank()) {
            std::cout << "piece on between spot" << std::endl;
            return false;
        }
        if (under_attack(between_spot)) {
            std::cout << "between spot under attack" << std::endl;
            return false;
        }
    }

    return true;
}
bool Board::valid_promotion(Move &mv) {

    if (!mv.is_promotion()) return false;
    int second_last_rank_white = 6;
    int second_last_rank_black = 1;

    Piece *pawn = mv.start_pos->get_piece();

    // starting piece must be pawn
    if ((mv.start_pos)->is_blank() || !(pawn->is_pawn())) return false;

    // move must be forward and one unit
    if (!mv.is_forward() || mv.euclid_dist() != 1) return false;

    // check pawn must be on second last rank
    if (white_move) {
        if ((mv.start_pos)->get_y() != second_last_rank_white) return false;
    } else {
        if ((mv.start_pos)->get_y() != second_last_rank_black) return false;
    }

    if (!mv.end_pos->is_blank()) return false; 

    // pawn must be able to move in front
    if (!pawn->valid_path(mv)) return false;

    return true;
}

bool Board::valid_en_passant(Move &mv) {

    Spot *start = mv.start_pos;
    Spot *end = mv.end_pos;
    int fifth_rank_white = 4;
    int fifth_rank_black = 3;

    if (!is_en_passant(mv)) return false;

    // must be on fifth rank
    if (white_move) {
        if (start->get_y() != fifth_rank_white) return false;
    } else {
        if (start->get_y() != fifth_rank_black) return false;
    }

    // to be taken pawn must exist
    Spot *taken_pawn_spot = nullptr;

    if (white_move) {
        taken_pawn_spot = get_spot(end->get_x(), end->get_y() - 1);
    } else {
        taken_pawn_spot = get_spot(end->get_x(), end->get_y() + 1);
    }

    if (taken_pawn_spot->is_blank()) return false;
    if (!((taken_pawn_spot->get_piece())->is_pawn())) return false;

    // last move must be the double up pawn about to be taken
    Move &last_move = moves.back();
    if (!same_spot(last_move.end_pos, taken_pawn_spot)) {
        return false;
    }
    if (last_move.y_dist() != 2) return false;

    return true;
}

bool Board::move_blocked(Move &mv) {

    int inc_x = 0;
    int inc_y = 0;

    if (!(mv.is_diagonal() || mv.is_horizontal() || mv.is_vertical())) return false;

    Spot *end = mv.end_pos;
    Spot *start = mv.start_pos;
    int dx = end->get_x() - start->get_x();
    int dy = end->get_y() - start->get_y();

    Spot *runner = start; // only checks for vertical, horizontal and diagonal

    if (dx > 0) {
        inc_x = 1;
    } else if (dx < 0) {
        inc_x = -1;
    }

    if (dy > 0) {
        inc_y = 1;
    } else if (dy < 0) {
        inc_y = -1;
    }

    while (true) {
        if (!in_bounds(runner->get_x() + inc_x, runner->get_y() + inc_y)) break;
        runner = get_spot(runner->get_x() + inc_x, runner->get_y() + inc_y);
        if (same_spot(runner, end)) return false;
        if (!runner->is_blank()) return true;
    }

    return true; // if input is valid then should never land here
}

// TODO
bool Board::check_valid_move(Move &mv) {
    std::cout << "check_valid_move" << std::endl;

    // check that the start spot actually has a piece
    if (!((mv.start_pos)->get_piece())) {
        std::cout << "start move doesnt have piece" << std::endl;
        return false;
    }

    // can only move if it's your turn
    bool piece_is_white = ((mv.start_pos)->get_piece())->is_white();
    if ((piece_is_white && !white_move) || (!piece_is_white && white_move)) {
        std::cout << "not your turn" << std::endl;
        return false;
    }

    // have to move somewhere, not stay in one place
    if (same_spot(mv.start_pos, mv.end_pos)) {
        std::cout << "cannot move to the same starting spot" << std::endl;
        return false;
    }
    
    // start and end cannot be out of bounds
    if (!(mv.end_pos)->in_bounds() || !(mv.start_pos)->in_bounds()) {
        std::cout << "start or end out of bounds" << std::endl;
        return false;
    }

    // cannot move into own pieces
    if (same_team(mv.start_pos, mv.end_pos)) {
        std::cout << "cannot attack same team" << std::endl;
        return false;
    }

    // castle, promotion, en passant
    if (mv.is_castle() && !valid_castle(mv)) {
        std::cout << "invalid castle" << std::endl;
        return false;
    } else if (mv.is_promotion() && !valid_promotion(mv)) {
        std::cout << "invalid promotion" << std::endl;
        return false;
    } else if (is_en_passant(mv) && !valid_en_passant(mv)) {
        std::cout << "invalid en passant" << std::endl;
        return false;
    } else {
        // check if piece can move path
        if (!valid_path(mv.start_pos, mv.end_pos)) {
            std::cout << "invalid path" << std::endl;
            return false;
        }

        if (move_blocked(mv)) {
            std::cout << "path blocked" << std::endl;
            return false;
        }
    }

    // cannot be in check after move ** should be done last **
    if (in_check_after_move(mv)) {
        std::cout << "in check after move" << std::endl;
        return false;
    }

    return true;
}


bool Board::same_spot(Spot *s1, Spot *s2) {
    return s1->get_x() == s2->get_x() && s1->get_y() == s2->get_y();
}

void Board::place_piece(Spot *start, Spot *end) {

    // capture piece
    if (!end->is_blank() && !same_team(start, end)) {
       (end->get_piece())->set_killed();
       std::cout << "piece captured!" << std::endl;
    }
    

    (start->get_piece())->set_has_moved(true);

    // end spot now has start's piece
    end->set_piece(start->get_piece());
    start->set_piece(nullptr);
}

bool Board::in_check() {

    if (under_attack(get_king_spot(white_move))) {
        std::cout << "in check" << std::endl;
        return true;
    }

    return false;
}

bool Board::in_check_after_move(Move &mv) {

    Spot *starting_spot = mv.start_pos;
    Spot *ending_spot = mv.end_pos;

    bool will_be_in_check = false;

    // get en passant information in case of en passant
    Spot *taken_pawn_spot_ep = nullptr;
    Piece *killed_pawn_ep = nullptr;

    // set initial has_moved for piece
    bool has_moved = (starting_spot->get_piece())->has_moved();

    if (valid_en_passant(mv)) {
        if (white_move) {
            taken_pawn_spot_ep = get_spot((mv.end_pos)->get_x(), (mv.end_pos)->get_y() - 1);
        } else {
            taken_pawn_spot_ep = get_spot((mv.end_pos)->get_x(), (mv.end_pos)->get_y() + 1);
        }

        killed_pawn_ep = taken_pawn_spot_ep->get_piece();
    }

    // perform the move
    execute_move(mv);

    // readjust move order
    white_move = !white_move; 
    if (in_check()) will_be_in_check = true;

    // undo execute move side effects
    moves.pop_back();

    // move piece back to original position
    starting_spot->set_piece(mv.piece_moved);

    // reset has_moved
    (starting_spot->get_piece())->set_has_moved(has_moved);

    // adjust end position
    if (mv.piece_killed) {
        (mv.piece_killed)->set_alive();
        ending_spot->set_piece(mv.piece_killed);
    } else {
        // blank spot
        ending_spot->set_piece(nullptr);
    }

    // if castle, move rook back to original square
    if (mv.is_castle() && valid_castle(mv)) {
        std::pair<Spot*, Spot*> rook_spots = get_rook_castle_spots(ending_spot);
        Spot *rook_start_spot = rook_spots.first;
        Spot *rook_end_spot = rook_spots.second;
        rook_start_spot->set_piece(rook_end_spot->get_piece());
        (rook_start_spot->get_piece())->set_has_moved(false);
        rook_end_spot->set_piece(nullptr);
    }

    // if en passant, set taken pawn back to alive and reattach piece to initial spot
    if (is_en_passant(mv) && valid_en_passant(mv)) {
        taken_pawn_spot_ep->set_piece(killed_pawn_ep);
        (taken_pawn_spot_ep->get_piece())->set_alive();
    }

    // if promotion, delete new piece and set original pawn to be alive
    if (mv.is_promotion() && valid_promotion(mv)) {
        if (white_move) {
            white->remove_last_piece();
        } else {
            black->remove_last_piece();
        }

        starting_spot->set_piece(mv.piece_moved);
        (starting_spot->get_piece())->set_alive();
    }

    return will_be_in_check;
}

std::pair<Spot*, Spot*> Board::get_rook_castle_spots(Spot *king_end) {

    // <start, end>
    Spot *start = nullptr;
    Spot *end = nullptr;

    if (same_spot(king_end, get_spot(6, 0))) {
        start = get_spot(7, 0);
        end = get_spot(5, 0);
    } else if (same_spot(king_end, get_spot(2, 0))) {
        start = get_spot(0, 0);
        end = get_spot(3, 0);
    } else if (same_spot(king_end, get_spot(2, 7))) {
        start = get_spot(0, 7);
        end = get_spot(3, 7);
    } else if (same_spot(king_end, get_spot(6, 7))) {
        start = get_spot(7, 7);
        end = get_spot(5, 7);
    }

    return std::make_pair(start, end);
}

bool Board::is_valid_king_castle_spots(Spot *start, Spot *end) {

    if (white_move) {
        if (same_spot(start, get_spot(4, 0)) && same_spot(end, get_spot(2, 0))) return true;
        if (same_spot(start, get_spot(4, 0)) && same_spot(end, get_spot(6, 0))) return true;
    } else {
        if (same_spot(start, get_spot(4, 7)) && same_spot(end, get_spot(2, 7))) return true;
        if (same_spot(start, get_spot(4, 7)) && same_spot(end, get_spot(6, 7))) return true;
    }
    
    return false;
}

void Board::execute_castle(Move &mv) {

    Spot *start = mv.start_pos;
    Spot *end = mv.end_pos;

    // place king
    place_piece(start, end);

    std::pair<Spot*, Spot*> rook_spots = get_rook_castle_spots(end);

    // place rook
    Spot *start_rook_spot = rook_spots.first;
    Spot *end_rook_spot = rook_spots.second;

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

void Board::execute_promotion(Move &mv) {

    Spot *start = mv.start_pos;
    Spot *end = mv.end_pos;

    (start->get_piece())->set_killed();

    bool init_pawn_white = (start->get_piece())->is_white();
    place_piece(start, end);

    Player *player = init_pawn_white ? white : black;

    if (mv.promotion_piece == 'n') {
        player->add_piece(std::make_shared<Knight>(init_pawn_white)); 
    } else if (mv.promotion_piece == 'r') {
        player->add_piece(std::make_shared<Rook>(init_pawn_white)); 
    } else if (mv.promotion_piece == 'b') {
        player->add_piece(std::make_shared<Bishop>(init_pawn_white));
    } else {
        player->add_piece(std::make_shared<Queen>(init_pawn_white));
    }

    end->set_piece(player->get_last_piece());
}

Spot* Board::get_king_spot(bool white) {

    Spot *king_spot = nullptr;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Spot *candidate = get_spot(i, j);
            if (!candidate->get_piece()) continue;
            if (white && candidate->get_piece()->is_king() && candidate->get_piece()->is_white()) {
                king_spot = candidate;
                break;
            }
            if (!white && candidate->get_piece()->is_king() && !candidate->get_piece()->is_white()) {
                king_spot = candidate;
                break;
            }
        }
    }
    return king_spot;
}

void Board::execute_move(Move &mv) {

    Spot *start = mv.start_pos;
    Spot *end = mv.end_pos;

    // perform castle
    if (mv.is_castle()) {
        execute_castle(mv);
    }

    // perform en passant
    if (is_en_passant(mv)) {
        execute_en_passant(mv);
    }
    
    // promotion
    if (mv.is_promotion()) {
        execute_promotion(mv);
    }

    // place piece for generic move
    if (!(mv.is_castle() || is_en_passant(mv) || mv.is_promotion())) {
        place_piece(start, end);
    }

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

Player *Board::get_current_player() {
    if (white_move) {
        return white;
    } else {
        return black;
    }
}

bool Board::white_to_move() {
    return white_move;
}

bool Board::any_path_available() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Piece * p = get_spot(i, j)->get_piece();
            if (p && ((p->is_white() && white_move) || (!p->is_white() && !white_move))) {
                std::vector<std::pair<int, int>> paths = p->generate_paths(std::make_pair(i, j));
                for (auto path : paths) {
                    if (white_move) {
                        Move m{white, get_spot(i, j), get_spot(path.first, path.second), p};
                        if (check_valid_move(m)) {
                            return false;
                        }
                    } else {
                        Move m{black, get_spot(i, j), get_spot(path.first, path.second), p};
                        if (check_valid_move(m)) {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}

bool Board::in_stalemate() {

    if (in_check()) return false;
    
    // TODO: check if only 2 pieces left on board
    int count = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Piece * p = get_spot(i, j)->get_piece();
            if (p) {
                count++;
            }
            if (count > 2) return false;
        }
    }

    if (count == 2) return true;
    
    return any_path_available();
}

bool Board::in_checkmate() {
    if (!in_check()) return false;
    return any_path_available();
}


void Board::notify_observers(Move &m) {
    notify_observers(m.start_pos);
    notify_observers(m.end_pos);
}

