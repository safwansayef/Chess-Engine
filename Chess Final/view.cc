#include "view.h"

View::View(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            board[j][i]= '-';
        }
    }
        //apply pieces to default positions as needed
        this->board[0][0]='R';
        this->board[1][0]='N';
        this->board[2][0]='B';
        this->board[3][0]='Q';
        this->board[4][0]='K';
        this->board[5][0]='B';
        this->board[6][0]='N';
        this->board[7][0]='R';
        this->board[0][7]='r';
        this->board[1][7]='n';
        this->board[2][7]='b';
        this->board[3][7]='q';
        this->board[4][7]='k';
        this->board[5][7]='b';
        this->board[6][7]='n';
        this->board[7][7]='r';

        int size = 8;

        const int blackPawnRow = 1;
        const int whitePawnRow = 6;
        int index1 = 0;
        while(index1 < size){
            this->board[index1][blackPawnRow] = 'P';
            index1++;
        }

        int index2 = 0;
        while(index2 < size){
            this->board[index2][whitePawnRow] ='p';
            index2++;
        }
}

View::~View(){}

void View::notify(char piece, int x, int y){
    if(piece == '-'){
        this->board[y][x] = '-';
    }else{
        this->board[y][x] = piece;
    }

}

void View::notify(int startRow,int startCol,int endRow,int endCol){
        char curPiece = this->board[startRow][startCol];
        this->board[endRow][endCol]=curPiece;
        this->board[startRow][startCol] = '-';
}
