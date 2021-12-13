#ifndef _QUEEN_H_
#define _QUEEN_H_

#include <memory>
#include <utility>
#include "piece.h"
#include "move.h"

class Queen : public Piece {

public:
    Queen(bool white);
    bool valid_path(Move mv) override;
    std::vector<std::pair<int, int>> generate_paths(std::pair<int, int> pos) override;
};

#endif