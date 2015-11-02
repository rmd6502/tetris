#include "gamestate.h"

extern static const String[] Lpiece = {
"* ",
"* ",
"**"};
extern static const String[] Tpiece = {
"***:,
" * "};
extern static const String[] Opiece = {
"**",
"**"};
extern static const String[] Zpiece = {
"** ",
" **"};
extern static const String[] Ipiece = {
"*",
"*",
"*",
"*"};

struct TetrisBoard : public GameBoard<30,60> {
};

struct TetrisPiece : public GamePiece {
    TetrisPiece(const String[] piece, bool reversed);
    // Flags that this piece is reflected, L and Z
    bool reversed;
    // 0-3, for 0-270º respectively
    unsigned char rotation;
};

