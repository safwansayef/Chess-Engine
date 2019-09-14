#ifndef _GRAPHICSDISPLAY_H
#define _GRAPHICSDISPLAY_H
#include <iostream>
#include <vector>
#include "view.h"
#include "window.h"
//#include "textDisplay.h"
#include <string>
using namespace std;
class Tile;

class graphicsDisplay: public View {
//default fields
Xwindow graphicsWindow;

public:
//constructor for graphics display
graphicsDisplay();
void update(char piece, int x, int y);
void update(int startRow,int startCol,int endRow,int endCol);
~graphicsDisplay();
void printBoard(ostream &out);
};
#endif






