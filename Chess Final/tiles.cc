#include "tiles.h"

Tile::Tile():
    colour{1}{}
int Tile::getX(){
    return this->x;
}
int Tile::getY(){
    return this->y;
}
string Tile::getColor(){
int add_pos =( this->getX() + this->getY() ) ;

    if((add_pos%2)!= 0){
        return "White";
    }else{
        return "Black";
    }
}
//void Tile::setTarget(string color){
//    if(color == "Black"){
//        this->black = true;
//    }
//    if(color == "White"){
//        this->white = true;
//    }
//
//}
//void Tile::rmTarget(){
//    this->white = false;
//    this->black = false;
//}
shared_ptr<Piece> Tile::getPiece(){
    return this->piece;
}
void Tile::setTile(int x, int y){
    this->x = x;
    this->y = y;
}
void Tile::setPiece(std::shared_ptr<Piece> p){
    this->piece = p;
}
//void Tile::rmPiece(){
//    if(!piece){
//        return;
//    }else{
//        this->piece = "";
//    }
//}

void Tile::setBoard(Board *b){
    this->board = b;
}

