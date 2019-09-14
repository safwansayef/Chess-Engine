#ifndef _COMPUTER2_H_
#define _COMPUTER2_H_
#include "computer.h"
class Computer2: public Computer{
public:
    Computer2(string colour,shared_ptr<Board> board);
    void move();
};
#endif
