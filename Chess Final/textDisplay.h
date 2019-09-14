#ifndef _TEXTDISPLAY_H
#define _TEXTDISPLAY_H
#include <iostream>
#include <vector>
#include <iostream>
#include <sstream>
#include "board.h"
#include "view.h"
using namespace std;
class Tile;
class Board;
class textDisplay:public View{
 public:
  textDisplay();
  ~textDisplay();
  void printBoard(ostream &out);
};
#endif

