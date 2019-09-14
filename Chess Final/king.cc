#include "king.h"

using namespace std;

King::King(string colour, int colpos, int rowpos, char type, Board &board) : Piece{colour,colpos,rowpos,type,board} {};

bool King::checkValidMove(int curr_col, int curr_row, int new_col, int new_row) {
    // Check if staying in the same spot
    if ((curr_col == new_col) && (curr_row==new_row)) { return false;}
    // Check if valid row
    if ((new_row >7) || (new_row < 0)) {return false;}
    // Check if Valid Column
    if ((new_col>7) || (new_col<0)) {return false;}

    if (board.board[new_col][new_row].getPiece() != nullptr) {
        if (board.board[new_col][new_row].getPiece()->getColour() == this->getColour()) { return false; }
    }

    if ((abs(new_col - curr_col) == 2) && (new_row==curr_row)) {

        if (this->getMadeMove()) {return false;}
        else {
            // Check if its white's turn if they can castle
            if (getColour()=="white") {
                // check if they are trying to castle to the left
                if (new_col < curr_col) {

                    if (board.board[0][0].getPiece() == nullptr) {return false;}

                    if(board.board[0][0].getPiece()->mademove) {return false;}
                    if(board.isinCheck(false,0,0)) {return false;}
                    for (int i =curr_col-1; i > 0; --i) {

                        if (board.board[i][curr_row].getPiece()!= nullptr) {
                            return false;
                        }

                        if (board.isinCheck(false,curr_row,i)) {
                            return false;
                        }
                    }

                    return true;
                }
                // check if they are trying to castle to the right
                else {


                    if (board.board[7][0].getPiece() == nullptr) {return false;}


                    if(board.board[7][0].getPiece()->mademove) {return false;}
                    if(board.isinCheck(false,0,7)) {return false;}
                    for (int i =curr_col+1; i < 7; ++i) {


                        if (board.board[i][curr_row].getPiece()!= nullptr) {
                            return false;
                        }


                        if (board.isinCheck(false,curr_row,i)) {
                            return false;
                        }
                    }


                    return true;
                }
            }
            // Check if black is trying to castle
            else {
                // check if they are trying to castle to the left
                if (new_col < curr_col) {


                    if (board.board[0][7].getPiece() == nullptr) {return false;}


                    if(board.board[0][7].getPiece()->mademove) {return false;}
                    if(board.isinCheck(true,7,0)) { return false;}
                    for (int i =curr_col-1; i > 0; --i) {


                        if (board.board[i][curr_row].getPiece()!= nullptr) {
                            return false;
                        }


                        if (board.isinCheck(true,curr_row,i)) {
                            return false;
                        }
                    }


                    return true;
                }
                    // check if they are trying to castle to the right
                else {


                    if (board.board[7][7].getPiece() == nullptr) {return false;}


                    if(board.board[7][7].getPiece()->mademove) {return false;}
                    if(board.isinCheck(true,7,7)) {return false;}
                    for (int i =curr_col+1; i < 7; ++i) {


                        if (board.board[i][curr_row].getPiece()!= nullptr) {
                            return false;
                        }


                        if (board.isinCheck(true,curr_row,i)) {
                            return false;
                        }
                    }


                    return true;
                }
            }
        }
    }

    // Check if moving by more than 1 in any direction
    if ((new_col > curr_col +1) || (new_col < curr_col -1)) {return false;}
    if ((new_row > curr_row +1) || (new_row < curr_row -1)) {return false;}

    // Once we change everything to Pieces instead of chars on the board, here we would check for the colour of the piece
    // to see if it is white or black, if its the opposite colour of "this" we can eat, else it return false
    return true;
}
