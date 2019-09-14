#include "piece.h"
#include <string>
#include "board.h"

using namespace std;

Piece::Piece(string colour, int colpos, int rowpos, char type, Board &board) : colour(colour), colpos(colpos), rowpos(rowpos), type(type), board(board), mademove{false} {};

int Piece::getRow() {
    return rowpos;
}

int Piece::getCol() {
    return colpos;
}

string Piece::getColour() {
    return colour;
}

char Piece::getType() {
    return type;
}

bool Piece::getMadeMove() {
    return mademove;
}

void Piece::setRow(int input) {
rowpos = input;
}
void Piece::setCol(int input) {
colpos = input;
}

