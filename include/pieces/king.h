#ifndef KING_H_
#define KING_H_

#include "piece.h"
#include "move.h"

class King : public Piece {
public:
    explicit King(bool white);
    bool valid_path(Move mv) override;
    bool is_king() const override;
    std::vector<std::pair<int, int>> generate_paths(std::pair<int, int> pos) override;
};
    

#endif