#include "gamestate.h"

extern static const unsigned char[] Lpiece = {2,2,3,0};
//"* ",
//"* ",
//"**"};
extern static const unsigned char[] Jpiece = {1,1,3,0};
//" *",
//" *",
//"**"};
extern static const unsigned char[] Tpiece = {7,2,0,0};
//"***:,
//" * "};
extern static const unsigned char[] Opiece = {3,3,0,0};
//"**",
//"**"};
extern static const unsigned char[] Zpiece = {6,3,0,0};
//" **",
//"** "};
extern static const unsigned char[] Spiece = {3,6,0,0};
//"** ",
//" **"};
extern static const unsigned char[] Ipiece = {1,1,1,1};
//"*",
//"*",
//"*",
//"*"};

struct TetrisPieceSpec {
    unsigned char[] bitmap;
    Pixel color;
} pieces[] = {
    // L, orange
    { Lpiece, Pixel(255,128,0) },
    // J, blue
    { Jpiece, Pixel(0,0,255) },
    // T, yellow
    { Tpiece, Pixel(255,255,0) },
    // O, teal
    { Opiece, Pixel(0,128,128) },
    // Z, green
    { Zpiece, Pixel(0,255,0) },
    // S, purple
    { Spiece, Pixel(255,0,255) },
    // I, red
    { Ipiece, Pixel(255,0,0) },
};


struct TetrisBoard : public GameBoard<30,60> {
    // The piece currently dropping
    TetrisPiece piece;
};

struct TetrisPiece : public GamePiece {
    TetrisPiece(TetrisPieceSpec piece);
    // 0-3, for 0-270º respectively
    unsigned char rotation;
};

