#include "knight.h"

using namespace std;

Knight::Knight(string colour, int colpos, int rowpos, char type, Board &board) : Piece{colour,colpos,rowpos,type,board} {};


bool Knight::checkValidMove(int curr_col, int curr_row, int new_col, int new_row) {
    // Check if Valid Row
    if ((curr_col == new_col) || (curr_row==new_row)) { return false;}
    // Check if Valid Row
    if ((new_row >7) || (new_row < 0)) {return false;}
    // Check if Valid Column
    if ((new_col>7) || (new_col<0)) {return false;}

    if (board.board[new_col][new_row].getPiece() != nullptr) {
        if (board.board[new_col][new_row].getPiece()->getColour() == this->getColour()) { return false; }
    }

    // All movements Up the Board
    if ((curr_row-1 == new_row) && (curr_col -2 == new_col)) {return true;}
    if ((curr_row-2 == new_row) && (curr_col -1 == new_col)) {return true;}
    if ((curr_row-1 == new_row) && (curr_col +2 == new_col)) {return true;}
    if ((curr_row-2 == new_row) && (curr_col +1 == new_col)) {return true;}
    // All movement Up the board
    if ((curr_row+1 == new_row) && (curr_col -2 == new_col)) {return true;}
    if ((curr_row+2 == new_row) && (curr_col -1 == new_col)) {return true;}
    if ((curr_row+1 == new_row) && (curr_col +2 == new_col)) {return true;}
    if ((curr_row+2 == new_row) && (curr_col +1 == new_col)) {return true;}
    return false;
}

