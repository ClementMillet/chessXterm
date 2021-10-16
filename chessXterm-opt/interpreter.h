#pragma once
#include"piece.h"

void interpreter(Piece board[64], int color);
int xFind(std::string com);
int yFind(std::string com);
std::string toLetter(int x);
std::string toNum(int y);
std::string intToColor(int c);
int colorToInt(std::string c);
