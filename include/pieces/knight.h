#ifndef KNIGHT_H_
#define KNIGHT_H_

#include "piece.h"
#include "move.h"

class Knight : public Piece {

public:
    explicit Knight(bool white);
    bool valid_path(Move mv) override;
    std::vector<std::pair<int, int>> generate_paths(std::pair<int, int> pos) override;
};

#endif