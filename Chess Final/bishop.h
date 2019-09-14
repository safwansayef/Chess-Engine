#ifndef _BISHOP_H
#define _BISHOP_H


#include "piece.h"
#include "board.h"


class Bishop : public Piece {
public:

    Bishop(std::string colour, int colpos, int rowpos, char type, Board &board);

    bool checkValidMove(int curr_col, int curr_row, int new_col, int new_row) override;

};

#endif //DOCUMENTS_BISHOP_H
