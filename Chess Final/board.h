#ifndef _BOARD_H_
#define _BOARD_H_
#include <vector>
using namespace std;
#include "tiles.h"
#include "view.h"
#include "textDisplay.h"
#include "pawn.h"
#include "piece.h"
#include "king.h"
#include "bishop.h"
#include "queen.h"
#include "knight.h"
#include "rook.h"
class textDisplay;
class Board{
//implement levels here
//connect to controller here

//implement function to clear the board and start a new game

//implement function to check validity of moves

//implement these when the abstract piece class is ready
//    vector<Piece *> whitePieces;
//    vector<Piece *> blackPieces;

    public:
    shared_ptr<textDisplay>td;
    int numberofrows;
    int numberofcoloumns;
    //constructor for board
    Board();
    //destructor for board
    ~Board();
    //Chess board is implemented as a 2D arrays of tiles
    Tile board[8][8];
    //initializes board with chess pieces in the standard starting position,
    //and - for the tiles with no occupying pieces
    void boardInit(bool custom);
    //loops through each tile in the board, and sets the current board as for board for each cell
    void setupBoard();
    //validate custom board to ensure that there are no pawns on the first/last row and
    //there is exactly 1 White King and 1 Black King
    bool validateCustomBoard();

    //move(startRow, startCol,endRow,  endCol) moves the piece in startPos to endPos, current implementation will be barebones, until
    // we have a piece class
    void move(int startRow,int startCol,int endRow,int endCol);

    //customInit(char piece) uses the user provided char piece to determine the type of chess piece to be
    //constructed
    void customInit(char piece, int col, int row);

    //printBoard() prints out current state of the board
    void printBoard(ostream &out);

    bool isinCheck(bool turn, int kingRow, int kingCol);

    bool isCheckMate(bool turn);

    bool stalemate(bool turn);

};
#endif

