#ifndef _PAWN_H_
#define _PAWN_H_

#include <memory>
#include <utility>
#include "piece.h"
#include "move.h"

class Pawn : public Piece
{

public:
    Pawn(bool white);
    bool valid_path(Move mv) override;
    bool is_pawn() const override;
    bool get_moved_two();
    std::vector<std::pair<int, int>> generate_paths(std::pair<int, int> pos) override;
};

#endif