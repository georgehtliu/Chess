#ifndef _QUEEN_H_
#define _QUEEN_H_
#include "../piece.h"
#include "../move.h"
#include <memory>
#include <utility>

class Queen : public Piece {

public:
    Queen(bool white);
    bool valid_path(Move mv) override;
    std::vector<std::pair<int, int>> generate_paths(std::pair<int, int> pos) override;
};

#endif