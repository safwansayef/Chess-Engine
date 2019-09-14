#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include "board.h"
#include <memory>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "computer.h"
#include "computer1.h"
#include "computer2.h"
#include "computer3.h"

using namespace std;


int main(int argc, char *argv[]) {
	auto ChessBoard = std::make_shared<Board>();
	//auto td = std::make_unique<textDisplay>();
	string input;
	double Wscore = 0; // Tracks score of white player
	double Bscore = 0; // Tracks score of black player
	bool active = false; // initially no game is active
	bool turn = false; // F when white's turn. T when black's turn
	string playerw; // white player
	string playerb; // black player
	vector<std::shared_ptr<Piece>> whitemen;
	vector<std::shared_ptr<Piece>> blackmen;
	bool isWComp = false;
	bool isBComp = false;
    srand(time(NULL));




    //initializes chessboard with default piece placement
	ChessBoard->setupBoard();
	auto WComp = std::make_shared<Computer1>("white", ChessBoard);
	auto BComp = std::make_shared<Computer1>("black", ChessBoard);
    auto WComp2 = std::make_shared<Computer2>("white", ChessBoard);
    auto BComp2 = std::make_shared<Computer2>("black", ChessBoard);
    auto WComp3 = std::make_shared<Computer3>("white", ChessBoard);
    auto BComp3 = std::make_shared<Computer3>("black", ChessBoard);
	while(true) {
		//ADD AI DOING MOVE HERE
		if(active && (turn == false) && isWComp){
			//White Ai player does his stuff
			if(playerw == "computer[1]"){
                WComp->move();
            }
            if(playerw == "computer[2]"){
                WComp2->move();
            }
            if(playerw == "computer[3]"){
                WComp3->move();
            }

			turn= !turn;
			if(ChessBoard->isinCheck(turn,-1,-1)==false) {

				if(ChessBoard->stalemate(turn)== true) {
					cout << "Stalemate!" << endl;
					Bscore = Bscore + 0.5;
					Wscore = Wscore + 0.5;
					isWComp = false;
					isBComp = false;
					active = false; // game has ended
					turn = false; //by default it is white's turn now
					ChessBoard->setupBoard();
					//***UPDATE TEXT DISPLAY HERE and Board to go back to normal setup

					continue;
				}

				continue; // if no stalemate and no check then continue reading input
			}


			if(ChessBoard->isinCheck(turn,-1,-1)==true) {
								if(ChessBoard->isCheckMate(turn)){
									if (turn==false){ // White has been Checkmated
									cout << "Checkmate! Black wins!" << endl;
									Bscore++;
									isWComp = false;
									isBComp = false;
									active = false; // game has ended
									turn = false;
									ChessBoard->setupBoard();
									//***UPDATE TEXT DISPLAY HERE and Board to go back to normal setup
									//ChessBoard->setupBoard(); //resetting the ChessBoard to standard setup
									continue;
									}
									if (turn==true){ // Black has been Checkmated
									cout << "Checkmate! White wins!" << endl;
									Wscore++;
									isWComp = false;
									isBComp = false;
									active = false; // game has ended
									turn = false;
									ChessBoard->setupBoard();
									//***UPDATE TEXT DISPLAY HERE and Board to go back to normal setup
									//ChessBoard->setupBoard(); //resetting the ChessBoard to standard setup
									continue;
									}
								}
								if (turn==false)
								cout << "White is in check" << endl;
								if(turn==true)
								cout << "Black is in check" << endl;
				}
			continue;
		}
		if(active && (turn == true) && isBComp){
			//Black Ai player does his stuff
            if(playerb == "computer[1]"){
                BComp->move();
            }
            if(playerb == "computer[2]"){
                BComp2->move();
            }
            if(playerb == "computer[3]"){
                BComp3->move();
            }

			turn= !turn;
			if(ChessBoard->isinCheck(turn,-1,-1)==false) {

				if(ChessBoard->stalemate(turn)== true) {
					cout << "Stalemate!" << endl;
					Bscore = Bscore + 0.5;
					Wscore = Wscore + 0.5;
					isWComp = false;
					isBComp = false;
					active = false; // game has ended
					turn = false; //by default it is white's turn now
					ChessBoard->setupBoard();
					//***UPDATE TEXT DISPLAY HERE and Board to go back to normal setup
					//ChessBoard->setupBoard(); //resetting the ChessBoard to standard setup
					continue;
				}

				continue; // if no stalemate and no check then continue reading input
			}


			if(ChessBoard->isinCheck(turn,-1,-1)==true) {
								if(ChessBoard->isCheckMate(turn)){
									if (turn==false){ // White has been Checkmated
									ChessBoard->printBoard(cout);
									cout << "Checkmate! Black wins!" << endl;
									Bscore++;
									isWComp = false;
									isBComp = false;
									active = false; // game has ended
									turn = false;
									ChessBoard->setupBoard();
									//***UPDATE TEXT DISPLAY HERE and Board to go back to normal setup
									//ChessBoard->setupBoard(); //resetting the ChessBoard to standard setup
									continue;
									}
									if (turn==true){ // Black has been Checkmated
									cout << "Checkmate! White wins!" << endl;
									Wscore++;
									isWComp = false;
									isBComp = false;
									active = false; // game has ended
									turn = false;
									ChessBoard->setupBoard();
									//***UPDATE TEXT DISPLAY HERE and Board to go back to normal setup
									//ChessBoard->setupBoard(); //resetting the ChessBoard to standard setup
									continue;
									}
								}
								if (turn==false)
								cout << "White is in check" << endl;
								if(turn==true)
								cout << "Black is in check" << endl;
				}
			continue;
		}

		cin >> input;
		if (cin.eof()) {
			//print the Scoreboard and quit loop
			cout << "Final Score:" << endl;
			cout << "White: " << Wscore << endl;
			cout << "Black " << Bscore << endl;
			break;
		}
		if (input == "game") {
			cin >> playerw;
			cin >> playerb;
			if(active) {
				cout << "A game is already in progress." << endl;
				continue;}
			active = true;
			whitemen.clear();
			blackmen.clear();
			//////Setting up vector of pieces for first time
			for (int i = 0; i < 8; i++) {
				for (int j =0; j< 8; j++) {
					if (ChessBoard->board[j][i].getPiece() != nullptr ) {

						if(ChessBoard->board[j][i].getPiece()->getColour() == "white") {

							whitemen.emplace_back(ChessBoard->board[j][i].getPiece());



						} else {
							blackmen.emplace_back(ChessBoard->board[j][i].getPiece());



						}
					}
					else {
						continue;
					}
				}
			}
			// End of filling in white and black men vectors

			if (playerw == "human") {
				isWComp = false;
			}
			else if (playerw == "computer[1]") {
				isWComp = true;
				auto temp1 = std::make_shared<Computer1>("white", ChessBoard);
				std::swap(WComp, temp1);
			}
			else if (playerw == "computer[2]") {
                isWComp = true;
                auto temp2 = std::make_shared<Computer2>("white", ChessBoard);
                std::swap(WComp2, temp2);
			}
			else if (playerw == "computer[3]") {
				isWComp = true;
                auto temp3 = std::make_shared<Computer3>("white", ChessBoard);
                std::swap(WComp3, temp3);
			}
			else if (playerw == "computer[4]") {
				isWComp = true;
			}
			else { cout << "Incorrect white player. Please re-enter game command with correct player" << endl;
				active = false;
				continue; }

			if (playerb == "human") {
				isBComp = false;
			 }
			else if (playerb == "computer[1]") {
				isBComp = true;
				auto temp4 = std::make_shared<Computer1>("black", ChessBoard);
				std::swap(BComp, temp4);
			}
            else if (playerb == "computer[2]") {
                isBComp = true;
                auto temp5 = std::make_shared<Computer2>("black", ChessBoard);
                std::swap(BComp2, temp5);
            }
			else if (playerb == "computer[3]") {
				isBComp = true;
                auto temp6 = std::make_shared<Computer3>("black", ChessBoard);
                std::swap(BComp3, temp6);
			}
			else if (playerb == "computer[4]") {
				isBComp = true;
			}
			else { cout << "Incorrect black player. Please re-enter game command with correct player" << endl;
				active = false;
				continue; }
			// When game command is correctly typed below happens

			// ChessBoard->printBoard(cout);
			// cout << endl;

			ChessBoard->td->printBoard(cout);
			continue; // Game has been set up, goes back to read input
		} // game condition closes
		if (input == "setup") {
			if (active == true){
				cout << "A game is already in progress. Cannot enter setup mode." << endl;
				continue; // GO back to reading command
			}
			if (active == false) {
				bool custom = true;
				// custom board initialization begins here
				bool done = false;

				while(!done){
					string op;
					char piece;
					string location;
					while(cin >> op){
						if(op == "+"){
							cin >> piece;
							cin >> location;
							int col = location[0] - 97;
							int row = location[1]-'1';
							//delete old piece as needed
							ChessBoard->customInit(piece,col, row);

							// ChessBoard->printBoard(cout);


                            // ChessBoard->td->printBoard(cout);
						}else if(op == "-"){
							cin >> location;
							int col = location[0] - 97;
							int row = location[1]-'1';
                            ChessBoard->customInit('-', col, row);

							// ChessBoard->printBoard(cout);

							// ChessBoard->td->printBoard(cout);
						} else if(op == "="){ //***THIS OPERATOR IS NOT WORKING
							string col_input;
							cin >> col_input;
							if(col_input == "white"){
								turn = false;
							} else {
								turn = true; }



						}else if(op == "done"){
							//validate board configuration here
							//check if there are exactly 2 kings
							if(!ChessBoard->validateCustomBoard()){
								continue;
							}else{
								//need to check if pawns are placed on first or last row ??
								done = true;
								break;
							}
						} else {
							cout << "Invalid command. Please re-enter." << endl;
							continue;
						}
					}



				}

			}

		}else if (input == "move") {
		    // setup command if condition closes
			string startpos;
			string endpos;
			cin >> startpos >> endpos;
			if (active==false){
				cout << "There is no game in progress. Please start a game first" << endl;
			}
			if (active) {
				int startCol = startpos[0] - 97;
				int startRow = startpos[1]-'1';
				int endCol = endpos[0] - 97;
				int endRow = endpos[1]-'1';
				if (ChessBoard->board[startCol][startRow].getPiece() == nullptr ) {
					cout << "Trying to move a blank tile. Not a valid move" << endl;
					continue;
				}
				//if we reach here means we are not trying to move blank tile
					string move_p_col = ChessBoard->board[startCol][startRow].getPiece()->getColour();

					if((move_p_col == "white" && turn == true) || (move_p_col == "black" && turn == false)) {
						cout << "Trying to move other player's piece. Invalid move" << endl;
						continue;
					}
					//if we reach here that a player is trying to play one of his pieces

						if (ChessBoard->board[startCol][startRow].getPiece()->checkValidMove(startCol, startRow, endCol, endRow) == false) {

							cout << "That piece can't move there. Invalid move" << endl;
							continue;
						}
						//if we reach here we mean the move is a legal move in terms of movement pattern


						shared_ptr<Piece> endP = ChessBoard->board[endCol][endRow].getPiece();
						shared_ptr<Piece> startP = ChessBoard->board[startCol][startRow].getPiece();
                        ChessBoard->move(startCol, startRow, endCol, endRow);
                        ChessBoard->board[endCol][endRow].getPiece()->setRow(endRow);
                        ChessBoard->board[endCol][endRow].getPiece()->setCol(endCol);




						if (ChessBoard->isinCheck(turn,-1,-1) == true) { //Checking if current player's king is in check from the move he made
							cout << "That move puts your king in check. Invalid move" << endl;
							ChessBoard->board[endCol][endRow].setPiece(endP);
                            ChessBoard->board[startCol][startRow].setPiece(startP);

                            ChessBoard->board[startCol][startRow].getPiece()->setRow(startRow);
                            ChessBoard->board[startCol][startRow].getPiece()->setCol(startCol);

							continue;
						}
						ChessBoard->board[endCol][endRow].setPiece(endP);
                            ChessBoard->board[startCol][startRow].setPiece(startP);

                            ChessBoard->board[startCol][startRow].getPiece()->setRow(startRow);
                            ChessBoard->board[startCol][startRow].getPiece()->setCol(startCol);
						//if we reach here that means the move was valid in all terms and can be played on the actual board

						// Check for castling
						if ((ChessBoard->board[startCol][startRow].getPiece()->getType() == 'K') && (abs(startCol-endCol) == 2)) {

						    if (endCol > startCol) {

						        ChessBoard->move(7,startRow,5,startRow);
                                ChessBoard->td->notify(7, startRow, 5, endRow);

                                ChessBoard->board[5][startRow].getPiece()->mademove = true;
                                ChessBoard->board[5][startRow].getPiece()->setRow(startRow);
                                ChessBoard->board[5][startRow].getPiece()->setCol(5);
						    }
						    else {

						        ChessBoard->move(0,startRow,3,startRow);
                                ChessBoard->td->notify(0, startRow, 3, endRow);
                                ChessBoard->board[3][startRow].getPiece()->mademove = true;
                                ChessBoard->board[3][startRow].getPiece()->setRow(startRow);
                                ChessBoard->board[3][startRow].getPiece()->setCol(5);
						    }
						}
						if ((ChessBoard->board[startCol][startRow].getPiece()->getType() == 'k') && (abs(startCol-endCol) == 2)) {

                            if (endCol > startCol) {

                                ChessBoard->move(7,startRow,5,startRow);
                                ChessBoard->td->notify(7, startRow, 5, endRow);
                                ChessBoard->board[5][startRow].getPiece()->mademove = true;
                                ChessBoard->board[5][startRow].getPiece()->setRow(startRow);
                                ChessBoard->board[5][startRow].getPiece()->setCol(5);
                            }
                            else {

                                ChessBoard->move(0,startRow,3,startRow);
                                ChessBoard->td->notify(0, startRow, 3, endRow);
                                ChessBoard->board[3][startRow].getPiece()->mademove = true;
                                ChessBoard->board[3][startRow].getPiece()->setRow(startRow);
                                ChessBoard->board[3][startRow].getPiece()->setCol(5);
                            }
						}
						//end catsling

						// Pawn Promotion
						// White Player Pawn Promotion
						if (!turn) {
						    if ((ChessBoard->board[startCol][startRow].getPiece()->getType() == 'P') && (endRow==7)) {
						        char pp;
						        cin >> pp;
								while(true) {
									if(pp == 'Q') {
										ChessBoard->board[startCol][startRow].setPiece(nullptr);
										ChessBoard->board[startCol][startRow].setPiece(make_shared<Queen>("white",startCol,startRow,'Q', *ChessBoard));
										ChessBoard->td->notify(pp, startRow, startCol);
										break;
									} else if(pp == 'R') {
										ChessBoard->board[startCol][startRow].setPiece(nullptr);
										ChessBoard->board[startCol][startRow].setPiece(make_shared<Rook>("white",startCol,startRow,'R', *ChessBoard));
										ChessBoard->td->notify(pp, startRow, startCol);
										break;
									}else if(pp == 'B'){
										ChessBoard->board[startCol][startRow].setPiece(nullptr);
										ChessBoard->board[startCol][startRow].setPiece(make_shared<Bishop>("white",startCol,startRow,'B', *ChessBoard));
										ChessBoard->td->notify(pp, startRow, startCol);
										break;
									}else if(pp == 'N'){
										ChessBoard->board[startCol][startRow].setPiece(nullptr);
										ChessBoard->board[startCol][startRow].setPiece(make_shared<Knight>("white",startCol,startRow,'N', *ChessBoard));
										ChessBoard->td->notify(pp, startRow, startCol);
										break;
									}else{
										cout << "Invalid input for changing white pawn. Please retry"<< endl;
										cin >> pp;
										continue;
									}
								}
						    }
						} //White pawn promotion ends here
						// Black Pawn Promtion
						if (turn) {
						    if((ChessBoard->board[startCol][startRow].getPiece()->getType() == 'p') && (endRow==0)) {
						        char pp;
						        cin >> pp;
								while(true) {
									if(pp == 'q') {
										ChessBoard->board[startCol][startRow].setPiece(nullptr);
										ChessBoard->board[startCol][startRow].setPiece(make_shared<Queen>("black",startCol,startRow,'q', *ChessBoard));
										ChessBoard->td->notify(pp, startRow, startCol);
										break;
									} else if(pp == 'r') {
										ChessBoard->board[startCol][startRow].setPiece(nullptr);
										ChessBoard->board[startCol][startRow].setPiece(make_shared<Rook>("black",startCol,startRow,'r', *ChessBoard));
										ChessBoard->td->notify(pp, startRow, startCol);
										break;
									}else if(pp == 'b'){
										ChessBoard->board[startCol][startRow].setPiece(nullptr);
										ChessBoard->board[startCol][startRow].setPiece(make_shared<Bishop>("black",startCol,startRow,'b', *ChessBoard));
										ChessBoard->td->notify(pp, startRow, startCol);
										break;
									}else if(pp == 'n'){
										ChessBoard->board[startCol][startRow].setPiece(nullptr);
										ChessBoard->board[startCol][startRow].setPiece(make_shared<Knight>("black",startCol,startRow,'n', *ChessBoard));
										ChessBoard->td->notify(pp, startRow, startCol);
										break;
									}else{
										cout << "Invalid input for changing black pawn. Please retry"<< endl;
										cin >> pp;
										continue;
									}
								}
						    }
						}


							ChessBoard->move(startCol, startRow, endCol, endRow);

							ChessBoard->td->notify(startCol, startRow, endCol, endRow);
                 			ChessBoard->td->printBoard(cout);

                            ChessBoard->board[endCol][endRow].getPiece()->mademove = true;
               				ChessBoard->board[endCol][endRow].getPiece()->setRow(endRow);
                            ChessBoard->board[endCol][endRow].getPiece()->setCol(endCol);

                            //Now that the move is made on the board we update position of all the black and white men
                            whitemen.clear();
                            blackmen.clear();

                            for (int i = 0; i < 8; i++) {
                            	for (int j =0; j< 8; j++) {
									if (ChessBoard->board[j][i].getPiece() == nullptr) {
										continue;
									}
                            		// if we reach here it means the piece on this tile is either black or white
                            			if(ChessBoard->board[j][i].getPiece()->getColour() == "white") {
                            				whitemen.emplace_back(ChessBoard->board[j][i].getPiece());


											} else {
                            					blackmen.emplace_back(ChessBoard->board[j][i].getPiece());

												}

                            	} // j loop ends
                            } // i loop ends
                            	//Finished updating the vector men
							turn = !turn; // The move has been made, change the turn


                if(ChessBoard->isinCheck(turn,-1,-1)==false) {

                            	if(ChessBoard->stalemate(turn)== true) {
                                    cout << "Stalemate!" << endl;
                                    Bscore = Bscore + 0.5;
                                    Wscore = Wscore + 0.5;
									isWComp = false;
									isBComp = false;
                                    active = false; // game has ended
                                    turn = false; //by default it is white's turn now
									ChessBoard->setupBoard();
                                    //***UPDATE TEXT DISPLAY HERE and Board to go back to normal setup
                                    //ChessBoard->setupBoard(); //resetting the ChessBoard to standard setup
                                    continue;
                                }

								continue; // if no stalemate and no check then continue reading input
                            	}


                if(ChessBoard->isinCheck(turn,-1,-1)==true) {

						if(ChessBoard->isCheckMate(turn)){

							if (turn==false){ // White has been Checkmated
							cout << "Checkmate! Black wins!" << endl;
							Bscore++;
							isWComp = false;
							isBComp = false;
							active = false; // game has ended
							turn = false;
							ChessBoard->setupBoard();
							//***UPDATE TEXT DISPLAY HERE and Board to go back to normal setup
							//ChessBoard->setupBoard(); //resetting the ChessBoard to standard setup
							continue;
							}
							if (turn==true){ // Black has been Checkmated
							cout << "Checkmate! White wins!" << endl;
							Wscore++;
							isWComp = false;
							isBComp = false;
							active = false; // game has ended
							turn = false;
							ChessBoard->setupBoard();
							//***UPDATE TEXT DISPLAY HERE and Board to go back to normal setup
							//ChessBoard->setupBoard(); //resetting the ChessBoard to standard setup
							continue;
							}
						}
						if (turn==false)
						cout << "White is in check" << endl;
						if(turn==true)
						cout << "Black is in check" << endl;
					}
			} // active ending here for move command
		} // move condition closes

		else if (input == "resign") {
			if (active) {
				if(turn == false) {  //if black's turn and resign then award white a point else opposite
					Bscore++;
					cout << "Black wins!" << endl;
				} else {
					Wscore++;
					cout << "White wins!" << endl;
				}
				isWComp = false;
				isBComp = false;
				active = false; // game has ended
				turn = false;
				ChessBoard->setupBoard();
				//resetting the ChessBoard to standard setup
				//***UPDATE TEXT DISPLAY HERE

			}	else {

				cout << "There is no game in progress. Please start a game first" << endl;

			}
		}

		else {

			cout << "Command not recognised. Please input a valid command" << endl;
			continue;
		}
	} // while loop for reading input closes
} // main function closes
