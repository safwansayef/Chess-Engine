#include "computer.h"

Computer::Computer(string colour, shared_ptr<Board> board):colour{colour}, theBoard{board}{}

string Computer::getColour(){
    return colour;
}
