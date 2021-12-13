#ifndef _BISHOP_H_
#define _BISHOP_H_

#include "piece.h"
#include "move.h"
#include <memory>
#include <utility>

class Bishop : public Piece {

public:
    Bishop(bool white);
    bool valid_path(Move mv) override;
    std::vector<std::pair<int, int>> generate_paths(std::pair<int, int> pos) override;
};

#endif