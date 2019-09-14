#include "board.h"
#include "rook.h"
#include <iostream>
#include <sstream>
#include <string>
#include <memory>
#include <utility>


using namespace std;
Board::Board(){
    int size = 8;
    int i = 0;
    while(i < size){
        int j = 0;
        while(j < size){
            board[i][j].setTile(i,j);
            j++;
        }
        i++;
    }
    this->td = nullptr;
}

Board::~Board(){
//implement when pieces are setup
//    for(auto i = whitePieces.begin(); i != whitePieces.end()){
//        delete (*i);
//    }
//    for(auto i = blackPieces.begin(); i != blackPieces.end()){
//        delete (*i);
//    }
//    whitePieces.clear();
//    blackPieces.clear();
}

void Board::setupBoard(){
    int size = 8;
    int i = 0;
    while(i < size){
        int j = 0;
        while(j < size){
            board[i][j].setBoard(this);
            j++;
        }
        i++;
    }
    //initialize empty board
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            this->board[j][i].setPiece(nullptr);
        }
    }
    //update this to create chessboard with setupPiece() function

    const int whitePawnRow = 1;
    const int blackPawnRow = 6;
    int index1 = 0;
    while(index1 < size){
        if(this->board[index1][blackPawnRow].getPiece()== nullptr) this->board[index1][blackPawnRow].setPiece(make_shared<Pawn>("black",index1,blackPawnRow,'p', *this));
        index1++;
    }

    int index2 = 0;
    while(index2 < size){
        if(this->board[index2][whitePawnRow].getPiece()== nullptr) this->board[index2][whitePawnRow].setPiece(std::make_shared<Pawn>("white",index2,whitePawnRow,'P', *this));
        index2++;
    }
    //apply pieces to default positions as needed
    if(this->board[0][0].getPiece()== nullptr)this->board[0][0].setPiece(std::make_shared<Rook>("white",0,0,'R', *this));
    if(this->board[1][0].getPiece()== nullptr)this->board[1][0].setPiece(make_shared<Knight>("white",1,0,'N', *this));
    if(this->board[2][0].getPiece()== nullptr)this->board[2][0].setPiece(make_shared<Bishop>("white",2,0,'B', *this));
    if(this->board[3][0].getPiece()== nullptr)this->board[3][0].setPiece(make_shared<Queen>("white",3,0,'Q', *this));
    if(this->board[4][0].getPiece()== nullptr /*&& whiteKing == 0*/)this->board[4][0].setPiece(make_shared<King>("white",4,0,'K', *this));
    if(this->board[5][0].getPiece()== nullptr)this->board[5][0].setPiece(make_shared<Bishop>("white",5,0,'B', *this));
    if(this->board[6][0].getPiece()== nullptr)this->board[6][0].setPiece(make_shared<Knight>("white",6,0,'N', *this));
    if(this->board[7][0].getPiece()== nullptr)this->board[7][0].setPiece(make_shared<Rook>("white",7,0,'R', *this));

    if(this->board[0][7].getPiece()== nullptr)this->board[0][7].setPiece(make_shared<Rook>("black",0,7,'r', *this));
    if(this->board[1][7].getPiece()== nullptr)this->board[1][7].setPiece(make_shared<Knight>("black",1,7,'n', *this));
    if(this->board[2][7].getPiece()== nullptr)this->board[2][7].setPiece(make_shared<Bishop>("black",2,7,'b', *this));
    if(this->board[3][7].getPiece()== nullptr)this->board[3][7].setPiece(make_shared<Queen>("black",3,7,'q', *this));
    if(this->board[4][7].getPiece()== nullptr /*&& blackKing == 0*/)this->board[4][7].setPiece(make_shared<King>("black",4,7,'k', *this));
    if(this->board[5][7].getPiece()== nullptr)this->board[5][7].setPiece(make_shared<Bishop>("black",5,7,'b', *this));
    if(this->board[6][7].getPiece()== nullptr)this->board[6][7].setPiece(make_shared<Knight>("black",6,7,'n', *this));
    if(this->board[7][7].getPiece()== nullptr)this->board[7][7].setPiece(make_shared<Rook>("black",7,7,'r', *this));
    //initialize textDisplay with default settings here
    this->td = make_shared<textDisplay>();
}

bool Board::validateCustomBoard(){
    //check first and last row for pawns
    for(int i = 0; i < 8; ++i){
        if((this->board[i][0].getPiece() == nullptr) || (this->board[i][7].getPiece() == nullptr)){
            continue;
        }else{
            bool pawnFirstRow = (this->board[i][0].getPiece()->getType() == 'P'
                              || this->board[i][0].getPiece()->getType() == 'p');
            bool pawnLastRow = (this->board[i][7].getPiece()->getType() == 'P'
                              || this->board[i][7].getPiece()->getType() == 'p');
            if(pawnFirstRow){
                cout << "Cant leave setup because pawn on first row" << endl;
                return false;
            }
            if(pawnLastRow){
                cout << "Cant leave setup because pawn on last row" << endl;
                return false;
            }

        }
    }
    int wk = 0;
    int bk = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            //if(i == 2 && j == 0){ continue;}
            if(this->board[j][i].getPiece() == nullptr){
                continue;
            }else{

                if(this->board[j][i].getPiece()->getType() == 'K'){


                    wk++;

                }
                if(this->board[j][i].getPiece()->getType() == 'k'){
                    bk++;

                }
            }
        }
    }
    if(bk != 1){
        cout << "Incorrect number of black kings" << endl;
        return false;
    }
    if(wk != 1){
        cout << "Incorrect number of white kings" << endl;
        return false;
    }
    return true;

}

void Board::move(int startRow,int startCol,int endRow,int endCol){

    shared_ptr<Piece> curPiece = this->board[startRow][startCol].getPiece();
    this->board[endRow][endCol].setPiece(curPiece);
    this->board[startRow][startCol].setPiece(nullptr);

}

void Board::customInit(char piece, int col, int row){
    if(piece == 'k') this->board[col][row].setPiece(make_shared<King>("black",col,row,'k', *this));
    if(piece == 'q') this->board[col][row].setPiece(make_shared<Queen>("black",col,row,'q', *this));
    if(piece == 'r') this->board[col][row].setPiece(make_shared<Rook>("black",col,row,'r', *this));
    if(piece == 'n') this->board[col][row].setPiece(make_shared<Knight>("black",col,row,'n', *this));
    if(piece == 'b') this->board[col][row].setPiece(make_shared<Bishop>("black",col,row,'b', *this));
    if(piece == 'p') this->board[col][row].setPiece(make_shared<Pawn>("black",col,row,'p', *this));

    if(piece == 'K') this->board[col][row].setPiece(make_shared<King>("white",col,row,'K', *this));
    if(piece == 'Q') this->board[col][row].setPiece(make_shared<Queen>("white",col,row,'Q', *this));
    if(piece == 'R') this->board[col][row].setPiece(make_shared<Rook>("white",col,row,'R', *this));
    if(piece == 'N') this->board[col][row].setPiece(make_shared<Knight>("white",col,row,'N', *this));
    if(piece == 'B') this->board[col][row].setPiece(make_shared<Bishop>("white",col,row,'B', *this));
    if(piece == 'P') this->board[col][row].setPiece(make_shared<Pawn>("white",col,row,'P', *this));
    if(piece == '-') this->board[col][row].setPiece(nullptr);
    this->td->notify(piece, row, col);
    this->td->printBoard(cout);

}

//printboard is already in textDisplay class, keep this for debugging purposes!
void Board::printBoard(ostream &out){
    const int size = 8;
    int row = 7;
    while(row >= 0){
        int col = 0;

        while(col < size){
            if(this->board[col][row].getPiece() == nullptr){
                out << '_';
                col++;
            }else{
                out << this->board[col][row].getPiece()->getType();
                col++;
            }
        }
        out << endl;
        row--;
    }
    out << endl;
    out << "  abcdefgh" << endl;

}


bool Board::stalemate(bool turn) {
     vector <std::shared_ptr<Piece>> whitemen;
     vector <std::shared_ptr<Piece>> blackmen;
     int wKingcol;
     int wKingrow;
     int bKingcol;
     int bKingrow;



     for (int i = 0; i < 8; i++) {

         for (int j = 0; j < 8; j++) {
             if (this->board[j][i].getPiece() == nullptr) continue;

             if (this->board[j][i].getPiece() != nullptr) {


                 if (this->board[j][i].getPiece()->getColour() == "white") {
                     whitemen.emplace_back(this->board[j][i].getPiece());
                     if (this->board[j][i].getPiece()->getType() == 'K') {
                         wKingcol = this->board[j][i].getPiece()->getCol();
                         wKingrow = this->board[j][i].getPiece()->getRow();
                     }

                 } else {

                     blackmen.emplace_back(this->board[j][i].getPiece());
                     if (this->board[j][i].getPiece()->getType() == 'k') {
                         bKingcol = this->board[j][i].getPiece()->getCol();
                         bKingrow = this->board[j][i].getPiece()->getRow();
                     }

                 }
             }
         }
     }

     if((whitemen.size()==1) && (blackmen.size()==1)) {
         return true;
     }

     // Check if white has any valid moves
     if (turn == false) {

         //Checking if White has any valid turns
         for (int v = 0; v < whitemen.size(); v++) {
             int pieceCol = whitemen[v]->getCol();
             int pieceRow = whitemen[v]->getRow();
             for (int i = 0; i < 8; i++) {
                 for (int j = 0; j < 8; j++) {
                     if (whitemen[v]->checkValidMove(pieceCol, pieceRow, j, i)) {

                         this->printBoard(cout);


                         shared_ptr<Piece> endP = this->board[j][i].getPiece();
	 					 shared_ptr<Piece> startP = this->board[pieceCol][pieceRow].getPiece();

                         this->move(pieceCol, pieceRow, j, i);
                         this->board[j][i].getPiece()->setRow(i);
                         this->board[j][i].getPiece()->setCol(j);

                         if (this->isinCheck(turn,-1,-1) == false) {
                             this->board[j][i].setPiece(endP);
                             this->board[pieceCol][pieceRow].setPiece(startP);
                             this->board[pieceCol][pieceRow].getPiece()->setRow(pieceRow);
                             this->board[pieceCol][pieceRow].getPiece()->setCol(pieceCol);
                             return false;
                         }
                         this->board[j][i].setPiece(endP);
                         this->board[pieceCol][pieceRow].setPiece(startP);
                         this->board[pieceCol][pieceRow].getPiece()->setRow(pieceRow);
                         this->board[pieceCol][pieceRow].getPiece()->setCol(pieceCol);

                     }
                 }
             }
         }
     }
     //Check if black has any valid moves

     if (turn == true) {
         for (int v = 0; v < blackmen.size(); v++) {
             int pieceCol = blackmen[v]->getCol();
             int pieceRow = blackmen[v]->getRow();
             for (int i = 0; i < 8; i++) {
                 for (int j = 0; j < 8; j++) {

                     if (blackmen[v]->checkValidMove(pieceCol, pieceRow, j, i)) {


                         shared_ptr<Piece> endP = this->board[j][i].getPiece();
	 					shared_ptr<Piece> startP = this->board[pieceCol][pieceRow].getPiece();

                         this->move(pieceCol, pieceRow, j, i);
                         this->board[j][i].getPiece()->setRow(i);
                         this->board[j][i].getPiece()->setCol(j);

                         if (this->isinCheck(turn,-1,-1) == false) {

                             this->board[j][i].setPiece(endP);

                             this->board[pieceCol][pieceRow].setPiece(startP);

                             this->board[pieceCol][pieceRow].getPiece()->setRow(pieceRow);

                             this->board[pieceCol][pieceRow].getPiece()->setCol(pieceCol);

                             return false;
                         }

                         this->board[j][i].setPiece(endP);

                         this->board[pieceCol][pieceRow].setPiece(startP);

                         this->board[pieceCol][pieceRow].getPiece()->setRow(pieceRow);

                         this->board[pieceCol][pieceRow].getPiece()->setCol(pieceCol);

                     }
                 }
             }
         }
     }
    return false;
}

bool Board::isinCheck(bool turn, int kingRow, int kingCol) {
    vector <std::shared_ptr<Piece>> whitemen;
    vector <std::shared_ptr<Piece>> blackmen;
    for (int i = 0; i < 8; i++) {

        for (int j = 0; j < 8; j++) {
            if (this->board[j][i].getPiece() == nullptr) continue;

            if (this->board[j][i].getPiece() != nullptr) {

                if (this->board[j][i].getPiece()->getColour() == "white") {

                    whitemen.emplace_back(this->board[j][i].getPiece());

                } else {
                    blackmen.emplace_back(this->board[j][i].getPiece());

                }
            }
        }
    }
// if checking for the white king in check
    if (turn == false) {

        if ((kingRow == -1) && (kingCol == -1)) {

            for (int i = 0; i < whitemen.size(); i++) {

                if (whitemen[i]->getType() == 'K') {
                    kingRow = whitemen[i]->getRow();
                    kingCol = whitemen[i]->getCol();

                    break;
                }
            }
        }

        for (int j = 0; j < blackmen.size(); j++) {

            int attackRow = blackmen[j]->getRow();
            int attackCol = blackmen[j]->getCol();


            if (blackmen[j]->checkValidMove(attackCol, attackRow, kingCol, kingRow)) {

                return true;
            } else { continue; }
        }
        return false;
    }

    // if checking for the black king in check
    if (turn == true) {
        if ((kingRow == -1) && (kingCol == -1)) {


            for (int i = 0; i < blackmen.size(); i++) {

                if (blackmen[i]->getType() == 'k') {
                    kingRow = blackmen[i]->getRow();
                    kingCol = blackmen[i]->getCol();

                    break;
                }
            }
        }



        for (int j = 0; j < whitemen.size(); j++) {

            int attackRow = whitemen[j]->getRow();
            int attackCol = whitemen[j]->getCol();


            if (whitemen[j]->checkValidMove(attackCol, attackRow, kingCol, kingRow)) {


                return true;
            } else {
                continue;
            }
        } // end of loop for all white attacking pieces

        return false;
    }
}

bool Board::isCheckMate(bool turn) {

    vector<std::shared_ptr<Piece>> whitemen;
    vector<std::shared_ptr<Piece>> blackmen;
    int kingrow;
    int kingcol;



    for (int i = 0; i < 8; i++) {

        for (int j =0; j< 8; j++) {
            if (this->board[j][i].getPiece() == nullptr) continue;

            if (this->board[j][i].getPiece() != nullptr ) {

                if(this->board[j][i].getPiece()->getColour() == "white") {

                    whitemen.emplace_back(this->board[j][i].getPiece());

                } else {
                    blackmen.emplace_back(this->board[j][i].getPiece());

                }
            }
        }
    }

    if (!turn) {


        for (int i = 0; i < whitemen.size(); i++) {

            if (whitemen[i]->getType() == 'K') {
                kingrow = whitemen[i]->getRow();
                kingcol = whitemen[i]->getCol();

                break;
            }
        }
        for (int j = 0; j<blackmen.size(); j++) {

            int attackRow = blackmen[j]->getRow();
            int attackCol = blackmen[j]->getCol();
            // Checking for obsturction
            if(blackmen[j]->checkValidMove(attackCol, attackRow, kingcol, kingrow)){
                // CHecking if white piece can eat black attacker
                for (int k =0; k<whitemen.size(); ++k) {
                    int defendRow = whitemen[k]->getRow();
                    int defendCol = whitemen[k]->getCol();

                    if(whitemen[k]->checkValidMove(defendCol,defendRow,attackCol,attackRow)) {

                        return false;
                    }
                }
                // Check if Vertical Direction can be Blocked
                if (attackCol==kingcol) {
                    // Check if Upper Vertical Direction of Check can be Obstructed
                    if (kingrow>attackRow) {
                        for (int i = attackRow+1; i < kingrow; ++i) {
                            for (int k =0; k < whitemen.size(); ++k) {
                                if (whitemen[k]->getType()=='K') {
                                    continue;
                                }
                                int defendRow = whitemen[k]->getRow();
                                int defendCol = whitemen[k]->getCol();
                                if(whitemen[k]->checkValidMove(defendCol,defendRow,attackCol,i)) {
                                    return false;
                                }
                            }
                        }
                    }
                    // Check if Lower Vertical Direction of Check can be Obstructed
                    if (kingrow<attackRow) {
                        for (int i = kingrow+1; i < attackRow; ++i) {
                            for (int k =0; k < whitemen.size(); ++k) {
                                if (whitemen[k]->getType()=='K') {
                                    continue;
                                }
                                int defendRow = whitemen[k]->getRow();
                                int defendCol = whitemen[k]->getCol();
                                if(whitemen[k]->checkValidMove(defendCol,defendRow,attackCol,i)) {
                                    return false;
                                }
                            }
                        }
                    }
                }
                // Check if Horizontal Direction can be Blocked
                if (attackRow==kingrow) {
                    if (kingcol>attackCol) {
                        for (int i = attackCol+1; i < kingrow; ++i) {
                            for (int k =0; k < whitemen.size(); ++k) {
                                if (whitemen[k]->getType()=='K') {
                                    continue;
                                }
                                int defendRow = whitemen[k]->getRow();
                                int defendCol = whitemen[k]->getCol();
                                if(whitemen[k]->checkValidMove(defendCol,defendRow,i,attackCol)) {
                                    return false;
                                }
                            }
                        }
                    }
                    // Check if Lower Vertical Direction of Check can be Obstructed
                    if (kingcol<attackCol) {
                        for (int i = kingcol+1; i < attackCol; ++i) {
                            for (int k =0; k < whitemen.size(); ++k) {
                                if (whitemen[k]->getType()=='K') {
                                    continue;
                                }
                                int defendRow = whitemen[k]->getRow();
                                int defendCol = whitemen[k]->getCol();
                                if(whitemen[k]->checkValidMove(defendCol,defendRow,i,attackCol)) {
                                    return false;
                                }
                            }
                        }
                    }
                }
                // Check if we can block Check for diagonal move when king is above and to the left of attacker
                if ((kingcol < attackCol) && (kingrow < attackRow)) {
                    for (int col= attackCol-1, row=attackRow-1; col > kingcol && row > kingrow; --col, --row) {
                        for (int k =0; k < whitemen.size(); ++k) {
                            if (whitemen[k]->getType()=='K') {
                                continue;
                            }
                            int defendRow = whitemen[k]->getRow();
                            int defendCol = whitemen[k]->getCol();
                            if(whitemen[k]->checkValidMove(defendCol,defendRow,col,row)) {
                                return false;
                            }
                        }
                    }
                }
                // Check if we can block Check for diagonal move when king is above and to the right of attacker
                if ((kingcol > attackCol) && (kingrow < attackRow)) {
                    for (int col= attackCol+1, row=attackRow-1; col < kingcol && row > kingrow; ++col, --row) {
                        for (int k =0; k < whitemen.size(); ++k) {
                            if (whitemen[k]->getType()=='K') {
                                continue;
                            }
                            int defendRow = whitemen[k]->getRow();
                            int defendCol = whitemen[k]->getCol();
                            if(whitemen[k]->checkValidMove(defendCol,defendRow,col,row)) {
                                return false;
                            }
                        }
                    }
                }
                // Check if we can block Check for diagonal move when king is below and to the right of attacker

                if ((kingcol > attackCol) && (kingrow > attackRow)) {
                    for (int col= attackCol+1, row=attackRow+1; col < kingcol && row < kingrow; ++col, ++row) {
                        for (int k =0; k < whitemen.size(); ++k) {
                            if (whitemen[k]->getType()=='K') {
                                continue;
                            }
                            int defendRow = whitemen[k]->getRow();
                            int defendCol = whitemen[k]->getCol();
                            if(whitemen[k]->checkValidMove(defendCol,defendRow,col,row)) {
                                return false;
                            }
                        }
                    }
                }
                // Check if we can block Check for diagonal move when king is below and to the left of attacker

                if ((kingcol < attackCol) && (kingrow > attackRow)) {
                    for (int col= attackCol-1, row=attackRow+1; col > kingcol && row < kingrow; --col, ++row) {
                        for (int k =0; k < whitemen.size(); ++k) {
                            if (whitemen[k]->getType()=='K') {
                                continue;
                            }
                            int defendRow = whitemen[k]->getRow();
                            int defendCol = whitemen[k]->getCol();
                            if(whitemen[k]->checkValidMove(defendCol,defendRow,col,row)) {
                                return false;
                            }
                        }
                    }
                }
            }
            else {continue;}
        }
    }

    if (turn){
        for (int i = 0; i < blackmen.size(); i++) {

            if (blackmen[i]->getType() == 'k')  {
                kingrow = blackmen[i]->getRow();
                kingcol = blackmen[i]->getCol();
                break;
            }
        }
        for (int j = 0; j<whitemen.size(); j++) {

            int attackRow = whitemen[j]->getRow();
            int attackCol = whitemen[j]->getCol();
            // Checking for obsturction
            if(whitemen[j]->checkValidMove(attackCol, attackRow, kingcol, kingrow)){
                // CHecking if white piece can eat black attacker
                for (int k =0; k<blackmen.size(); ++k) {
                    int defendRow = blackmen[k]->getRow();
                    int defendCol = blackmen[k]->getCol();
                    if(blackmen[k]->checkValidMove(defendCol,defendRow,attackCol,attackRow)) {


                        return false;
                    }
                }
                // Check if Vertical Direction can be Blocked
                if (attackCol==kingcol) {
                    // Check if Upper Vertical Direction of Check can be Obstructed
                    if (kingrow>attackRow) {
                        for (int i = attackRow+1; i < kingrow; ++i) {
                            for (int k =0; k < blackmen.size(); ++k) {
                                if (blackmen[k]->getType()=='k') {
                                    continue;
                                }
                                int defendRow = blackmen[k]->getRow();
                                int defendCol = blackmen[k]->getCol();
                                if(blackmen[k]->checkValidMove(defendCol,defendRow,attackCol,i)) {


                                    return false;
                                }
                            }
                        }
                    }
                    // Check if Lower Vertical Direction of Check can be Obstructed
                    if (kingrow<attackRow) {
                        for (int i = kingrow+1; i < attackRow; ++i) {
                            for (int k =0; k < blackmen.size(); ++k) {
                                if (blackmen[k]->getType()=='k') {
                                    continue;
                                }
                                int defendRow = blackmen[k]->getRow();
                                int defendCol = blackmen[k]->getCol();
                                if(blackmen[k]->checkValidMove(defendCol,defendRow,attackCol,i)) {


                                    return false;
                                }
                            }
                        }
                    }
                }
                // Check if Horizontal Direction can be Blocked
                if (attackRow==kingrow) {
                    if (kingcol>attackCol) {
                        for (int i = attackCol+1; i < kingrow; ++i) {
                            for (int k =0; k < blackmen.size(); ++k) {
                                if (blackmen[k]->getType()=='k') {
                                    continue;
                                }
                                int defendRow = blackmen[k]->getRow();
                                int defendCol = blackmen[k]->getCol();
                                if(blackmen[k]->checkValidMove(defendCol,defendRow,i,attackCol)) {


                                    return false;
                                }
                            }
                        }
                    }
                    // Check if Lower Vertical Direction of Check can be Obstructed
                    if (kingcol<attackCol) {
                        for (int i = kingcol+1; i < attackCol; ++i) {
                            for (int k =0; k < blackmen.size(); ++k) {
                                if (blackmen[k]->getType()=='k') {
                                    continue;
                                }
                                int defendRow = blackmen[k]->getRow();
                                int defendCol = blackmen[k]->getCol();
                                if(blackmen[k]->checkValidMove(defendCol,defendRow,i,attackCol)) {


                                    return false;
                                }
                            }
                        }
                    }
                }
                // Check if we can block Check for diagonal move when king is above and to the left of attacker
                if ((kingcol < attackCol) && (kingrow < attackRow)) {
                    for (int col= attackCol-1, row=attackRow-1; col > kingcol && row > kingrow; --col, --row) {
                        for (int k =0; k < blackmen.size(); ++k) {
                            if (blackmen[k]->getType()=='k') {
                                continue;
                            }
                            int defendRow = blackmen[k]->getRow();
                            int defendCol = blackmen[k]->getCol();
                            if(blackmen[k]->checkValidMove(defendCol,defendRow,col,row)) {


                                return false;
                            }
                        }
                    }
                }
                // Check if we can block Check for diagonal move when king is above and to the right of attacker
                if ((kingcol > attackCol) && (kingrow < attackRow)) {
                    for (int col= attackCol+1, row=attackRow-1; col < kingcol && row > kingrow; ++col, --row) {
                        for (int k =0; k < blackmen.size(); ++k) {
                            if (blackmen[k]->getType()=='k') {
                                continue;
                            }
                            int defendRow = blackmen[k]->getRow();
                            int defendCol = blackmen[k]->getCol();
                            if(blackmen[k]->checkValidMove(defendCol,defendRow,col,row)) {


                                return false;
                            }
                        }
                    }
                }
                // Check if we can block Check for diagonal move when king is below and to the right of attacker

                if ((kingcol > attackCol) && (kingrow > attackRow)) {
                    for (int col= attackCol+1, row=attackRow+1; col < kingcol && row < kingrow; ++col, ++row) {
                        for (int k =0; k < blackmen.size(); ++k) {
                            if (blackmen[k]->getType()=='k') {
                                continue;
                            }
                            int defendRow = blackmen[k]->getRow();
                            int defendCol = blackmen[k]->getCol();
                            if(blackmen[k]->checkValidMove(defendCol,defendRow,col,row)) {


                                return false;
                            }
                        }
                    }
                }
                // Check if we can block Check for diagonal move when king is below and to the left of attacker

                if ((kingcol < attackCol) && (kingrow > attackRow)) {
                    for (int col= attackCol-1, row=attackRow+1; col > kingcol && row < kingrow; --col, ++row) {
                        for (int k =0; k < blackmen.size(); ++k) {
                            if (blackmen[k]->getType()=='k') {
                                continue;
                            }
                            int defendRow = blackmen[k]->getRow();
                            int defendCol = blackmen[k]->getCol();
                            if(blackmen[k]->checkValidMove(defendCol,defendRow,col,row)) {


                                return false;
                            }
                        }
                    }
                }

            }
            else {continue;}
        }
    }


    // Check bottom Row
    if (this->board[kingcol][kingrow].getPiece()->checkValidMove(kingcol,kingrow,kingcol-1,kingrow-1)) { //left diagnol bottom
        if(isinCheck(turn,kingrow-1,kingcol-1) == false){


            return false;
        }
    }
    if (this->board[kingcol][kingrow].getPiece()->checkValidMove(kingcol,kingrow,kingcol,kingrow-1)) { //staright bottom
        if(isinCheck(turn,kingrow-1,kingcol)==false) {


            return false;
        }
    }
    if (this->board[kingcol][kingrow].getPiece()->checkValidMove(kingcol,kingrow,kingcol+1,kingrow-1)) { // right diagnol bottom
        if(isinCheck(turn,kingrow-1,kingcol+1)==false) {


            return false;
        }
    }

    // Check sides
    if (this->board[kingcol][kingrow].getPiece()->checkValidMove(kingcol,kingrow,kingcol-1,kingrow)) { // staright left side
        if(isinCheck(turn,kingrow,kingcol-1)==false) {

            return false;
        }
    }
    if (this->board[kingcol][kingrow].getPiece()->checkValidMove(kingcol,kingrow,kingcol+1,kingrow)) { // straight right
        if(isinCheck(turn,kingrow,kingcol+1)==false){


            return false;
        }
    }
    // Check top Row
    if (this->board[kingcol][kingrow].getPiece()->checkValidMove(kingcol,kingrow,kingcol-1,kingrow+1)) { // left diagnol top
        if(isinCheck(turn,kingrow+1,kingcol-1)==false) {

            return false;
        }
    }
    if (this->board[kingcol][kingrow].getPiece()->checkValidMove(kingcol,kingrow,kingcol,kingrow+1)) { // straight top
        if(isinCheck(turn,kingrow+1,kingcol)==false) {


            return false;
        }
    }
    if (this->board[kingcol][kingrow].getPiece()->checkValidMove(kingcol,kingrow,kingcol+1,kingrow+1)) { // right diagonal top
        if(isinCheck(turn,kingrow+1,kingcol+1)==false) {


            return false;
        }
    }
    return true;
}

