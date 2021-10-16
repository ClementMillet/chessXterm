#pragma once
#include<string>
#include<vector>
#include"piece.h"
void generate(Piece board[64]);
bool isInCheck(Piece board[64], int color);
bool kingSideCastling(Piece board[64], int color);
bool queenSideCastling(Piece board[64], int color);
void resetPassant(Piece board[64], int color);
int checkmate(Piece board[64], int color);
bool move(Piece board[64], int x, int y, int xDest, int yDest);
bool enPassant(Piece board[64], int x, int y, int xDest, int yDest);
