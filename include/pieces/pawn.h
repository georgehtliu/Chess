#ifndef PAWN_H_
#define PAWN_H_

#include "piece.h"
#include "move.h"

class Pawn : public Piece {

public:
    explicit Pawn(bool white);
    bool valid_path(Move mv) override;
    bool is_pawn() const override;
    std::vector<std::pair<int, int>> generate_paths(std::pair<int, int> pos) override;
};

#endif