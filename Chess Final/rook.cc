#include "rook.h"

using namespace std;


Rook::Rook(std::string colour, int colpos, int rowpos, char type, Board &board) : Piece{colour,colpos,rowpos,type,board} {};
//Rook::~Rook(){}

bool Rook::checkValidMove(int curr_col, int curr_row, int new_col, int new_row)  {
    // Check if Valid Row
    if ((curr_col == new_col) && (curr_row==new_row)) { return false;}
    if ((new_row >7) || (new_row < 0)) {return false;}
    // Check if Valid Column
    if ((new_col>7) || (new_col<0)) {return false;}

    if (board.board[new_col][new_row].getPiece() != nullptr) {
        if (board.board[new_col][new_row].getPiece()->getColour() == this->getColour()) { return false; }
    }
    // Check if valid movement Pattern
    if ((curr_row != new_row) && (curr_col != new_col)) {return false;}
    // Check if there is a piece in the way
    if (curr_col == new_col) {
        if (new_row > curr_row) {
            for (int i = curr_row+1;i < new_row; ++i) {
                if (board.board[curr_col][i].getPiece() != nullptr) {
                    return false;
                }
            }
        }
        else {
            for (int i = new_row + 1; i < curr_row; ++i) {
                if (board.board[curr_col][i].getPiece() != nullptr) {
                    return false;
                }
            }
        }
    }
    if (curr_row == new_row) {
        if (new_col > curr_col) {
            for (int i = curr_col+1;i < new_col; ++i) {
                if (board.board[i][curr_row].getPiece() != nullptr) {
                    return false;
                }
            }
        }
        else {
            for (int i = new_col+1; i < curr_col; ++i) {
                if (board.board[i][curr_row].getPiece() != nullptr) {
                    return false;
                }
            }
        }
    }
    return true;
}
