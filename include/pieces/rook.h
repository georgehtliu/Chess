#ifndef ROOK_H_
#define ROOK_H_

#include "piece.h"
#include "move.h"

class Rook : public Piece {
public:
    Rook(bool white);
    bool valid_path(Move mv) override;
    bool is_rook() const override;
    std::vector<std::pair<int, int>> generate_paths(std::pair<int, int> pos) override;
};

#endif