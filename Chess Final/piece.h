#ifndef _PIECE_
#define _PIECE_

#include <string>
#include <vector>
//#include "board.h"

class Board;
class Piece {
protected:
    std::string colour;
    int colpos;
    int rowpos;
    char type;

    Board &board;

//    vector<Tile *> validmoves;
 //   vector<Tile *> cancapture;

public:

    bool mademove;

    Piece(std::string colour, int colpos, int rowpos, char type, Board &board);
void setRow(int input);
void setCol(int input);
    int getRow() ;
    int getCol();
    std::string getColour();

    char getType();

    bool getMadeMove();

    //   void setpiece(Cell cell,piece *piece);

    //char getpiece(Tile tile);

    //void UpdateHistory();

    //virtual void setValidMoves(Piece *piece)=0;

    virtual bool checkValidMove(int curr_col, int curr_row, int new_col, int new_row)=0;
    //virtual ~Piece() = 0;


};

#endif
