#include "computer1.h"

Computer1::Computer1(string colour, shared_ptr<Board> board): Computer{colour, board}
{};


void Computer1::move(){
    string colour = this->getColour();
    bool kkk = false;
    if(colour=="black") {
        kkk = true;
    }
    //create an array of pieces
    vector<std::shared_ptr<Piece>> pieces;
        for (int i = 0; i < 8; i++) {
            for (int j =0; j< 8; j++) {
                if (theBoard->board[j][i].getPiece() == nullptr) continue;
                if (theBoard->board[j][i].getPiece() != nullptr ) {
                    if(theBoard->board[j][i].getPiece()->getColour() == colour) {
                        pieces.emplace_back(theBoard->board[j][i].getPiece());

                        }
                }
            }
        }
    int Row;
    int Col;
    int pieceRow;
    int pieceCol;
    int max_rand = 0;
    for(int i = 0; i < pieces.size(); ++i){
        pieceRow = pieces[i]->getRow();
        pieceCol = pieces[i]->getCol();
        max_rand = 0;
        while (max_rand <= 1000) {

            Row = rand()%8;
            Col = rand()%8;

            if(pieces[i]->checkValidMove(pieceCol, pieceRow, Col, Row)){

            shared_ptr<Piece> endP = theBoard->board[Col][Row].getPiece();
			shared_ptr<Piece> startP = theBoard->board[pieceCol][pieceRow].getPiece();
            theBoard->move(pieceCol, pieceRow, Col, Row);
            theBoard->board[Col][Row].getPiece()->setRow(Row);
            theBoard->board[Col][Row].getPiece()->setCol(Col);

            if (theBoard->isinCheck(kkk,-1,-1) == true) {
                theBoard->board[Col][Row].setPiece(endP);
                theBoard->board[pieceCol][pieceRow].setPiece(startP);
                theBoard->board[pieceCol][pieceRow].getPiece()->setRow(pieceRow);
                theBoard->board[pieceCol][pieceRow].getPiece()->setCol(pieceCol);
                max_rand++;
                continue;
            }

            theBoard->board[Col][Row].setPiece(endP);
            theBoard->board[pieceCol][pieceRow].setPiece(startP);
            theBoard->board[pieceCol][pieceRow].getPiece()->setRow(pieceRow);
            theBoard->board[pieceCol][pieceRow].getPiece()->setCol(pieceCol);


            theBoard->move(pieceCol, pieceRow, Col, Row);
            theBoard->td->notify(pieceCol, pieceRow, Col, Row);
            theBoard->printBoard(cout);
            theBoard->board[Col][Row].getPiece()->setRow(Row);
            theBoard->board[Col][Row].getPiece()->setCol(Col);
            theBoard->board[Col][Row].getPiece()->mademove = true;
            return ;
        }else{
            max_rand++;
            continue;
        }
        }

    }
}
