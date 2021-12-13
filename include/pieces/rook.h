#ifndef _ROOK_H_
#define _ROOK_H_

#include <memory>
#include <utility>
#include "piece.h"
#include "move.h"

class Rook : public Piece {
    bool has_moved;

public:
    Rook(bool white);
    bool get_has_moved();
    bool valid_path(Move mv) override;
    std::vector<std::pair<int, int>> generate_paths(std::pair<int, int> pos) override;
};

#endif