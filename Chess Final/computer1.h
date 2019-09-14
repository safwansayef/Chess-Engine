#ifndef _COMPUTER1_H_
#define _COMPUTER1_H_
#include "computer.h"
class Computer1: public Computer{
    public:
    Computer1(string colour,shared_ptr<Board> board);
    void move();
};
#endif
