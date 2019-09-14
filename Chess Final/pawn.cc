#include "board.h"
#include "pawn.h"
using namespace std;


Pawn::Pawn(string colour, int colpos, int rowpos, char type, Board &board) : Piece{colour,colpos,rowpos,type,board} {};

bool Pawn::checkValidMove(int curr_col, int curr_row, int new_col, int new_row) {
    // If statement to check if it a first move

    // CHeck staying in the same spot

    if ((curr_col == new_col) && (curr_row==new_row)) { return false;}
    // Check if valid row

    if ((new_row >7) || (new_row < 0)) {return false;}
    // Check if Valid Column

    if ((new_col>7) || (new_col<0)) {return false;}

    // Bottom Moving Up
    // Here we check for black pawn movements
    // Check if moving backwards or forwards by more than 1

    // Moving down board

    if (getColour()=="black") {

        if (getMadeMove()) {

            if ((new_row >= curr_row) || (new_row < curr_row-1)) {return false;}
        }
        else {


            if ((new_row >= curr_row) || (new_row < curr_row-2)) {

                return false;

            }

        }
        // CHeck if trying to move over by more than 1 column

        if ((new_col > curr_col +1) || (new_col < curr_col -1)) {return false;}
        // Cant move up 2 and diagonally
        if ((new_row == curr_row - 2) && (new_col != curr_col)) {return false;}

        if (new_col==curr_col) {
            if (board.board[new_col][new_row].getPiece() != nullptr) {return false;}
        }
        else {
            if (board.board[new_col][new_row].getPiece() == nullptr) {return false;}
        }
    }
    // Moving Up Board


    if (getColour() =="white") {

        if (getMadeMove()) {

            if ((new_row <= curr_row) || (new_row > curr_row+1)) {return false;}
        }
        else {

            if ((new_row <= curr_row) || (new_row > curr_row+2)) {return false;}
        }
        // CHeck if trying to move over by more than 1 column

        if ((new_col > curr_col +1) || (new_col < curr_col -1)) {return false;}
        // Cant move up 2 and diagonally

        if ((new_row == curr_row + 2) && (new_col != curr_col)) {return false;}



        if (new_col==curr_col) {
            if (board.board[new_col][new_row].getPiece() != nullptr) {return false;}
        }
        else {
            if (board.board[new_col][new_row].getPiece() == nullptr) {return false;}
        }
    }
    return true;
}
