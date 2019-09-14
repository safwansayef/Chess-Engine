#ifndef _KNIGHT_H
#define _KNIGHT_H

#include "board.h"
#include "piece.h"

class Board;
class Knight : public Piece {

public:

    Knight(std::string colour, int colpos, int rowpos, char type, Board &board);

    bool checkValidMove(int curr_col, int curr_row, int new_col, int new_row) override;

};


#endif //DOCUMENTS_KNIGHT_H
