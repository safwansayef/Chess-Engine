#ifndef _COMPUTER3_H_
#define _COMPUTER3_H_
#include "computer.h"
class Computer3: public Computer{
public:
    Computer3(string colour,shared_ptr<Board> board);
    void move();
};
#endif
