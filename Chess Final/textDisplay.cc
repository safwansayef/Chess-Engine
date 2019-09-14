#include "textDisplay.h"

void textDisplay::printBoard(ostream &out){
    const int size = 8;
    int row = 7;
    while(row >= 0){
        int col = 0;
        out << row + 1 << " ";
        while(col < size){
            out << board[col][row];
            col++;
        }
        out << endl;
        row--;
    }
    out << endl;
    out << "  abcdefgh" << endl;
}
textDisplay::textDisplay(): View{} {}
textDisplay::~textDisplay(){}
