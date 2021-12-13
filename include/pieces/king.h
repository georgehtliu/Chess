#ifndef _KING_H_
#define _KING_H_

#include "piece.h"
#include "move.h"
#include <memory>
#include <utility>

class King : public Piece {
    bool has_moved;
public:
    King(bool white);
    bool get_has_moved();
    bool valid_path(Move mv) override;
    bool valid_castle(Move mv);
    bool is_king() const override;
    std::vector<std::pair<int, int>> generate_paths(std::pair<int, int> pos) override;
};
    

#endif