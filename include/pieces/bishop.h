#ifndef BISHOP_H_
#define BISHOP_H_

#include "piece.h"
#include "move.h"

class Bishop : public Piece {

public:
    explicit Bishop(bool white);
    bool valid_path(Move mv) override;
    std::vector<std::pair<int, int>> generate_paths(std::pair<int, int> pos) override;
};

#endif