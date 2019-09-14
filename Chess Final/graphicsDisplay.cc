#include "graphicsDisplay.h"

graphicsDisplay::graphicsDisplay(): View{}{
     //create empty chessboard
     graphicsWindow.fillRectangle(0,0, 500, 500, Xwindow::Blue);
     for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
	    if((i+j)%2 == 0){
                graphicsWindow.fillRectangle(50*(j + 1), 50*(8-i),50,50,Xwindow::Black);
            }else{
                graphicsWindow.fillRectangle(50*(j + 1), 50*(8-i),50,50,Xwindow::White);
            }
        }
     }
     //add row and column indexes
     int i = 0;
     while(i < 1){
	  graphicsWindow.drawBigString(75, 475, "A", Xwindow::White);
          graphicsWindow.drawBigString(125, 475, "B", Xwindow::White);
          graphicsWindow.drawBigString(175, 475, "C", Xwindow::White);
          graphicsWindow.drawBigString(225, 475, "D", Xwindow::White);
          graphicsWindow.drawBigString(275, 475, "E", Xwindow::White);
          graphicsWindow.drawBigString(325, 475, "F", Xwindow::White);
          graphicsWindow.drawBigString(375, 475, "G", Xwindow::White);
          graphicsWindow.drawBigString(425, 475, "H", Xwindow::White);

          graphicsWindow.drawBigString(25 + (450 * i), 425, "1", Xwindow::White);
          graphicsWindow.drawBigString(25 + (450 * i), 375, "2", Xwindow::White);
          graphicsWindow.drawBigString(25 + (450 * i), 325, "3", Xwindow::White);
          graphicsWindow.drawBigString(25 + (450 * i), 275, "4", Xwindow::White);
          graphicsWindow.drawBigString(25 + (450 * i), 225, "5", Xwindow::White);
          graphicsWindow.drawBigString(25 + (450 * i), 175, "6", Xwindow::White);
          graphicsWindow.drawBigString(25 + (450 * i), 125, "7", Xwindow::White);
          graphicsWindow.drawBigString(25 + (450 * i), 75, "8", Xwindow::White);
        ++i;
     }
     //place pieces in correct positions
     for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            char  piece = board[i][j];
	    if(piece == '-' || piece == ' '){
                continue;
            }else{
		stringstream ss;
        	string p;
       	 	ss << piece;
        	ss >> p;
            	graphicsWindow.drawBigString(50*(i + 1) + 25, 50*(9-j) - 25, p, Xwindow::Red);
	    }

        }
     }
};
void graphicsDisplay::update(char piece, int x, int y){
	if(piece == '-'){
	    this->board[y][x] = piece;
	    if((x+y)%2 == 0){
                graphicsWindow.fillRectangle(50*(y + 1), 50*(8-x),50,50,Xwindow::Black);
            }else{
                graphicsWindow.fillRectangle(50*(y + 1), 50*(8-x),50,50,Xwindow::White);
            }

        }else{
	     this->board[y][x] = piece;
             stringstream ss;
             string p;
             ss << piece;
             ss >> p;
             graphicsWindow.drawBigString(50*(y + 1) + 25, 50*(9-x) - 25, p, Xwindow::Red);

        }
}
void graphicsDisplay::update(int startRow,int startCol,int endRow,int endCol){
   char piece = this->board[startRow][startCol];
   cout << piece << endl;
   this->board[endRow][endCol]=piece;
   this->board[startRow][startCol] = '-';
   cout << "gd board" << endl;
   this->printBoard(cout);
   for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
        if(this->board[j][i] != '-'){
             char curPiece = this->board[j][i];
             stringstream ss;
             string p;
             ss << curPiece;
             ss >> p;
	     
            if((j+i)%2 == 0){
                graphicsWindow.fillRectangle(50*(j + 1), 50*(8-i),50,50,Xwindow::Black);
             	graphicsWindow.drawBigString(50*(j + 1) + 25, 50*(9-i) - 25, p, Xwindow::Red); 
            }else{
                graphicsWindow.fillRectangle(50*(j + 1), 50*(8-i),50,50,Xwindow::White);
		graphicsWindow.drawBigString(50*(j + 1) + 25, 50*(9-i) - 25, p, Xwindow::Red); 

            }

             graphicsWindow.drawBigString(50*(j + 1) + 25, 50*(9-i) - 25, p, Xwindow::Red); 
    }else{
            if((j+i)%2 == 0){
                graphicsWindow.fillRectangle(50*(j + 1), 50*(8-i),50,50,Xwindow::Black);
            }else{
                graphicsWindow.fillRectangle(50*(j + 1), 50*(8-i),50,50,Xwindow::White);
            }
    }
   }
   }
}
graphicsDisplay::~graphicsDisplay() {};
void graphicsDisplay::printBoard(ostream &out){

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

};


