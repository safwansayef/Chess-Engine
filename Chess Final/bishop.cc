#include "bishop.h"
using namespace std;

Bishop::Bishop(std::string colour, int colpos, int rowpos, char type, Board &board) : Piece{colour,colpos,rowpos,type,board} {};


bool Bishop::checkValidMove(int curr_col, int curr_row, int new_col, int new_row) {
    // Check not moving horizontally
    if ((curr_col == new_col) || (curr_row==new_row)) { return false;}
    // Check if Valid Row
    if ((new_row >7) || (new_row < 0)) {return false;}
    // Check if Valid Column
    if ((new_col>7) || (new_col<0)) {return false;}
    // Check if your piece is ony the board your moving to

    if (board.board[new_col][new_row].getPiece() != nullptr) {
        if (board.board[new_col][new_row].getPiece()->getColour() == this->getColour()) { return false; }
    }

    // Check if move is to upper left of the current position
    if ((new_col < curr_col) && (new_row < curr_row)) {
        for (int col= curr_col-1, row=curr_row-1; col >= 0 && row >= 0; --col, --row) {
            if ((col==new_col) && (row==new_row)) {
                return true;
            }
            if (board.board[col][row].getPiece() != nullptr) {
                return false;
            }
        }
    }

        // Check if move is valid to the upper right
    else if ((new_col > curr_col) && (new_row < curr_row)) {
        for (int col= curr_col+1, row=curr_row-1; col < 8 && row >= 0; ++col, --row) {
            if ((col==new_col) && (row==new_row)) {
                return true;
            }
            if (board.board[col][row].getPiece() != nullptr) {
                return false;
            }
        }
    }
        // Check if move is valid to the bottom right
    else if ((new_col > curr_col) && (new_row > curr_row)) {
        for (int col= curr_col+1, row=curr_row+1; col < 8 && row < 8; ++col, ++row) {
            if ((col==new_col) && (row==new_row)) {
                return true;
            }
            if (board.board[col][row].getPiece()!= nullptr) {
                return false;
            }
        }
    }
        // Check if move is valid to the bottom left
    else {
        for (int col= curr_col-1, row=curr_row+1; col >= 0 && row < 8; --col, ++row) {
            if ((col==new_col) && (row==new_row)) {
                return true;
            }
            if (board.board[col][row].getPiece() != nullptr) {
                return false;
            }
        }
    }
    return false;
}

