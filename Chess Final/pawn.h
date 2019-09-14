#ifndef _PAWN_H_
#define _PAWN_H_


#include "piece.h"

class Board;
class Pawn: public Piece{

public:

    Pawn(std::string colour, int colpos, int rowpos, char type, Board &board);
    //~Pawn() override;

    bool checkValidMove(int curr_col, int curr_row, int new_col, int new_row) override;


};



#endif //DOCUMENTS_PAWN_H
