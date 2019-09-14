//
// Created by Mihailo Becic on 2019-07-25.
//

#ifndef _ROOK_H_
#define _ROOK_H_
#include "board.h"
#include "piece.h"

class Rook : public Piece {

public:
    //~Rook() override;
    Rook(std::string colour, int colpos, int rowpos, char type, Board &board);
    bool checkValidMove(int curr_col, int curr_row, int new_col, int new_row) override;

};


#endif //DOCUMENTS_ROOK_H

