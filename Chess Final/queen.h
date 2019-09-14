#ifndef _QUEEN_H
#define _QUEEN_H

#include "piece.h"
#include "board.h"

class Queen : public Piece {

public:

    Queen(std::string colour, int colpos, int rowpos, char type, Board &board);

    bool checkValidMove(int curr_col, int curr_row, int new_col, int new_row) override;

};


#endif //DOCUMENTS_QUEEN_H
