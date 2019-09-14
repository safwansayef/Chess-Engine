#include "computer3.h"
Computer3::Computer3(string colour,shared_ptr<Board> board): Computer{colour,board} {};

void Computer3::move(){
    string colour = this->getColour();
    bool kkk = false;
    if(colour=="black") {
        kkk = true;
    }
    //create an array of pieces
    vector<std::shared_ptr<Piece>> pieces;
    vector<std::shared_ptr<Piece>> opponent_pieces;
    for (int i = 0; i < 8; i++) {
        for (int j =0; j< 8; j++) {
            if (theBoard->board[j][i].getPiece() == nullptr) continue;
            if (theBoard->board[j][i].getPiece() != nullptr ) {
                if(theBoard->board[j][i].getPiece()->getColour() == colour) {
                    pieces.emplace_back(theBoard->board[j][i].getPiece());

                }
                else{
                    opponent_pieces.emplace_back(theBoard->board[j][i].getPiece());
                }
            }
        }
    }
    // Checking if Can Check the Opposing king
    for (int i = 0; i < pieces.size(); ++i) {
        int pieceCol = pieces[i]->getCol();
        int pieceRow = pieces[i]->getRow();
        for (int Row =0; Row < 8; ++Row) {
            for (int Col =0; Col < 8; ++Col) {
                if ((pieces[i]->checkValidMove(pieceCol,pieceRow,Col,Row))) {



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
                        continue;
                    }
                    if(theBoard->isinCheck(!kkk,-1,-1) == true) {

                        theBoard->td->notify(pieceCol, pieceRow, Col, Row);
                        theBoard->printBoard(cout);
                        return;
                    }

                    theBoard->board[Col][Row].setPiece(endP);
                    theBoard->board[pieceCol][pieceRow].setPiece(startP);
                    theBoard->board[pieceCol][pieceRow].getPiece()->setRow(pieceRow);
                    theBoard->board[pieceCol][pieceRow].getPiece()->setCol(pieceCol);
                    continue;

                    /*       theBoard->move(pieceCol, pieceRow, Col, Row);
                           theBoard->td->notify(pieceCol, pieceRow, Col, Row);
                           theBoard->printBoard(cout);
                           theBoard->board[Col][Row].getPiece()->setRow(Row);
                           theBoard->board[Col][Row].getPiece()->setCol(Col);
                           theBoard->board[Col][Row].getPiece()->mademove = true;
                           return ;*/

                }
            }
        }
    }

    //Checking to avoid capture
    for (int i =0; i< pieces.size(); ++i) {
        int pieceCol = pieces[i]->getCol();
        int pieceRow = pieces[i]->getRow();
        for (int j=0; j < opponent_pieces.size(); ++j) {
            int oppCol = opponent_pieces[j]->getCol();
            int oppRow = opponent_pieces[j]->getRow();
            if (opponent_pieces[j]->checkValidMove(oppCol,oppRow,pieceCol,pieceRow)) {
                for (int Row = 0; Row < 8; ++Row) {
                    for (int Col = 0; Col< 8; ++Col) {
                        if (pieces[i]->checkValidMove(pieceCol, pieceRow, Col, Row)) {
                            if (opponent_pieces[j]->checkValidMove(oppCol, oppRow, Col, Row)) {
                                continue;
                            } else {

                                shared_ptr <Piece> endP = theBoard->board[Col][Row].getPiece();
                                shared_ptr <Piece> startP = theBoard->board[pieceCol][pieceRow].getPiece();

                                theBoard->move(pieceCol, pieceRow, Col, Row);

                                theBoard->board[Col][Row].getPiece()->setRow(Row);

                                theBoard->board[Col][Row].getPiece()->setCol(Col);

                                if (theBoard->isinCheck(kkk, -1, -1) == true) {

                                    theBoard->board[Col][Row].setPiece(endP);
                                    theBoard->board[pieceCol][pieceRow].setPiece(startP);
                                    theBoard->board[pieceCol][pieceRow].getPiece()->setRow(pieceRow);
                                    theBoard->board[pieceCol][pieceRow].getPiece()->setCol(pieceCol);

                                    continue;
                                }
                                return;

                            }
                        }
                    }
                }
            }
            else {
                continue;
            }
        }
    }

    //Checking for Capturing other pieces
    for (int i =0; i< pieces.size(); ++i) {
        int pieceCol = pieces[i]->getCol();
        int pieceRow = pieces[i]->getRow();

        for (int j=0; j < opponent_pieces.size(); ++j) {
            int oppCol = opponent_pieces[j]->getCol();
            int oppRow = opponent_pieces[j]->getRow();


            if (pieces[i]->checkValidMove(pieceCol,pieceRow,oppCol,oppRow)) {

                shared_ptr<Piece> endP = theBoard->board[oppCol][oppRow].getPiece();
                shared_ptr<Piece> startP = theBoard->board[pieceCol][pieceRow].getPiece();
                theBoard->move(pieceCol, pieceRow, oppCol, oppRow);
                theBoard->board[oppCol][oppRow].getPiece()->setRow(oppRow);
                theBoard->board[oppCol][oppRow].getPiece()->setCol(oppCol);

                if (theBoard->isinCheck(kkk,-1,-1) == true) {
                    theBoard->board[oppCol][oppRow].setPiece(endP);
                    theBoard->board[pieceCol][pieceRow].setPiece(startP);
                    theBoard->board[pieceCol][pieceRow].getPiece()->setRow(pieceRow);
                    theBoard->board[pieceCol][pieceRow].getPiece()->setCol(pieceCol);
                    continue;
                }

//                theBoard->board[oppCol][oppRow].setPiece(endP);
                //              theBoard->board[pieceCol][pieceRow].setPiece(startP);
                //            theBoard->board[pieceCol][pieceRow].getPiece()->setRow(pieceRow);
                //          theBoard->board[pieceCol][pieceRow].getPiece()->setCol(pieceCol);


                //         theBoard->move(pieceCol, pieceRow, oppCol, oppRow);
                theBoard->td->notify(pieceCol, pieceRow, oppCol, oppRow);
                theBoard->printBoard(cout);
                //     theBoard->board[oppCol][oppRow].getPiece()->setRow(oppRow);
                //       theBoard->board[oppCol][oppRow].getPiece()->setCol(oppCol);
                theBoard->board[oppCol][oppRow].getPiece()->mademove = true;
                return ;
            }
            else {
                continue;
            }
        }
    }

    //checking for random moves
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
                for (int j=0; j < opponent_pieces.size(); ++j) {
                    int oppcol = opponent_pieces[j]->getCol();
                    int opprow = opponent_pieces[j]->getRow();
                    if (opponent_pieces[j]->checkValidMove(oppcol,opprow,Col,Row)) {
                        goto nextpiece;
                    }
                }


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
        nextpiece:;
    }
}


