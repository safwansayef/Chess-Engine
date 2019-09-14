#include "queen.h"
#include "board.h"

using namespace std;

Queen::Queen(string colour, int colpos, int rowpos, char type, Board &board) : Piece{colour,colpos,rowpos,type,board} {};


bool Queen::checkValidMove(int curr_col, int curr_row, int new_col, int new_row) {
    // Check if same spot
    if ((curr_col == new_col) && (curr_row==new_row)) { return false;}
    // Check if valid row
    if ((new_row >7) || (new_row < 0)) {return false;}
    // Check if Valid Column
    if ((new_col>7) || (new_col<0)) {return false;}

    if (board.board[new_col][new_row].getPiece() != nullptr) {
        if (board.board[new_col][new_row].getPiece()->getColour() == this->getColour()) { return false; }
    }

    // Horizontal/Vertical Movements, follow rook movement pattern
    if ((curr_col==new_col) || (curr_row==new_row)) {
        if (curr_col == new_col) {
            if (new_row > curr_row) {
                for (int i = curr_row+1;i < new_row; ++i) {
                    if (board.board[curr_col][i].getPiece() != nullptr) {
                        return false;
                    }
                }
            }
            else {
                for (int i = new_row+1; i < curr_row; ++i) {
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
        // Diagonal movements, follow bishop movement pattern
    else {
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
                if (board.board[col][row].getPiece() != nullptr) {
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
}


