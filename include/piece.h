#ifndef _PIECE_H_
#define _PIECE_H_

#include <memory>
#include <utility>
#include "image_loader.h"

class Move;

class Piece {
protected:
    bool white;
    bool alive;
    char text_repr;

    // File paths for PNGs to load
    std::string white_square;
    std::string black_square;
public:
    bool is_white() const;
    bool is_alive();
    virtual bool is_pawn() const;
    virtual bool is_king() const;
    char get_text();
    void set_killed();
    void set_alive();
    void set_white(bool white);
    virtual bool valid_path(Move mv) = 0;
    virtual std::vector<std::pair<int, int>> generate_paths(std::pair<int, int> pos) = 0;
    virtual ~Piece() = default;
    bool in_board(int x, int y);
    void increment(int x_inc, int y_inc, int x_start, int y_start, std::vector<std::pair<int, int>> * paths);

    std::string get_white_square_img() const;
    std::string get_black_square_img() const;

};

#endif