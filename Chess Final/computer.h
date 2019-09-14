#ifndef _COMPUTER_H_
#define _COMPUTER_H_
#include <string>
#include <memory>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "board.h"
#include "tiles.h"
#include "piece.h"
using namespace std;
class Computer{
    protected:
        //colour of ai player
        string colour;
        //pointer to the board the computer is playing on
        shared_ptr<Board> theBoard;
    public:
        Computer(string colour,shared_ptr<Board> board);
        virtual ~Computer() = default;
        virtual void move() = 0;
        string getColour();
};
#endif

