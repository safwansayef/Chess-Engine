#ifndef _VIEW_H_
#define _VIEW_H_
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
class View{
    protected:
    char board[8][8];
    public:
        //view ctor
        View();
        //dtor
        ~View();
        //prints out textDisplay
        virtual void printBoard(ostream &out) = 0;
        //notify board when a new piece has been added to it
        void notify(char piece, int x, int y);
        void notify(int startRow,int startCol,int endRow,int endCol);
        void update(char piece, int x, int y);
        void update(int startRow,int startCol,int endRow,int endCol);



};
#endif
