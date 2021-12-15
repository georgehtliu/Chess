#ifndef CHESS_INCLUDE_BOARD_H_
#define CHESS_INCLUDE_BOARD_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <utility>

#include "graphics_observer.h"
#include "text_observer.h"
#include "spot.h"
#include "player.h"
#include "move.h"
#include "piece.h"

class Board {
    Player* white;
    Player* black;

    std::vector<Move> moves;

    GraphicsObserver* g;
    TextObserver* t;

    std::vector<std::vector<Spot>> positions;
    bool white_move;

    // Manage/execute moves
    void execute_en_passant(Move &mv);
    void execute_castle(Move &mv);
    bool is_valid_king_castle_spots(Spot *start, Spot *end);
    std::pair<Spot*, Spot*> get_rook_castle_spots(Spot *king_end);
    void execute_promotion(Move &mv);
    bool is_en_passant(Move &mv);
    bool valid_castle(Move &mv);
    bool valid_promotion(Move &mv);
    bool valid_en_passant(Move &mv);
    bool search_attacker(Spot *spot, int x_inc, int y_inc);
    bool under_attack_vertical(Spot *spot);
    bool under_attack_horizontal(Spot *spot);
    bool under_attack_diagonal(Spot *spot);
    bool under_attack_knight(Spot *spot);
    bool move_blocked(Move &mv);
    bool under_attack(Spot *spot);
    bool is_attacking_path(Spot *end, Spot *attack_candidate);
    bool valid_path(Spot *from, Spot *to);
    bool same_team(Spot *s1, Spot *s2);
    bool same_spot(Spot *s1, Spot *s2);
    bool in_check();
    bool in_check_after_move(Move &mv);
    void add_piece(char piece, std::string position);
    Spot *get_king_spot(bool white);
    bool setup_complete();
    bool any_path_available();

public:
    // Constructor / Destructor
    Board(Player* white, Player* black);
    ~Board() = default; // FIXME

    // Observers
    void attach_graphics(GraphicsObserver *g);
    void attach_text(TextObserver *t);
    void detach(Observer *o);
    void detach_all();
    void notify_observers();
    void notify_observers(Spot *s);
    void notify_observers(Move &m); // TODO

    // Board info
    const static int ROWS = 8;
    const static int COLS = 8;

    // Board construction
    void gen_standard_layout();
    void setup_mode(); 

    // Manage spots
    Spot* get_spot(int x, int y);

    bool check_valid_move(Move &mv);
    int evaluate_move(Move &mv, bool defensive=false);
    void execute_move(Move &mv);
    void place_piece(Spot *start, Spot *end);

    // Manage game
    bool in_checkmate();
    bool in_stalemate();

    // Manage Players
    void set_white(Player* white);
    void set_black(Player* black);
    Player* get_black();
    Player* get_white();
    Player* get_current_player();
    bool white_to_move();
};

#endif // CHESS_INCLUDE_BOARD_H_