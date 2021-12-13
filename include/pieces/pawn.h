#ifndef _PAWN_H_
#define _PAWN_H_

#include "../piece.h"
#include "../move.h"
#include <memory>
#include <utility>

class Pawn : public Piece
{
    bool has_moved;
    bool moved_two;

public:
    Pawn(bool white);
    bool valid_path(Move mv) override;
    bool is_pawn() const override;
    bool get_has_moved();
    bool get_moved_two();
    std::vector<std::pair<int, int>> generate_paths(std::pair<int, int> pos) override;
};

#endif