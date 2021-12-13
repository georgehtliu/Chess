#ifndef _KNIGHT_H_
#define _KNIGHT_H_

#include "../piece.h"
#include "../move.h"
#include <memory>
#include <utility>

class Knight : public Piece {

public:
    Knight(bool white);
    bool valid_path(Move mv) override;
    std::vector<std::pair<int, int>> generate_paths(std::pair<int, int> pos) override;
};

#endif