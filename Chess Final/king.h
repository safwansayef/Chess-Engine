#ifndef _KING_H
#define _KING_H
#include "board.h"
#include "piece.h"
#include <string>

class King : public Piece {
public:
    King(std::string colour, int colpos, int rowpos, char type, Board &board);

    bool checkValidMove(int curr_col, int curr_row, int new_col, int new_row) override;


};


#endif
