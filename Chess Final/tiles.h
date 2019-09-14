#ifndef _TILE_H_
#define _TILE_H_
#include "piece.h"
#include <string>
#include <memory>
#include <utility>
using namespace std;
class Piece;
class Board;
class Tile{
    //coordinates of the tile
    int x;
    int y;
    //keeps track of the colour of the piece occupying the tile
    bool colour;
    //change this to a Piece* when it is implemented
    //char piece;
    std::shared_ptr<Piece> piece;
    Board *board;
    public:
    //constructor for Tile
    Tile();
    //getX() returns the x-coordinate for the tile
    int getX();
    //getY() returns the x-coordinate for the tile
    int getY();
    //getColor() returns the colour for the tile
    string getColor();
    //setTarget(string color) assigns what color the tile will be targeted by
    void setTarget(string color);
    //rmTarget() removes targetability of the piece (and tile)
    void rmTarget();
    //getPiece() returns the current piece occupying the tile
    shared_ptr<Piece> getPiece();
    //setTile(int x, int y) sets coordinates of the tile to (x,y) on the board
    void setTile(int x, int y);
    //setPiece(char p) assigns the Piece p to the cell
    void setPiece(std::shared_ptr<Piece> p);
    //implement this when we have the piece class
    //void rmPiece();
    //setBoard(Board *b) assigns b to be the board for the cell
    void setBoard(Board *b);
};


#endif

