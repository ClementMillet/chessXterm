#include<iostream>
#include"piece.h"
#include"interface.h"
#include"generate.h"
#include"interpreter.h"


int mainLoop(Piece board[64], int black, int white)
{
	bool game = true;
	while (game)
	{
		interpreter(board, 1);
		system("clear");
		displayBoard(board, white, black);
		if (checkmate(board, -1) == 1)
		{
			std::cout << "\033[31m  Checkmate, White win\033[0m \n" << std::endl;
			return 0;
		}
		else if (checkmate(board, -1) == 0)
		{
			std::cout << "\033[31m  Draw by stalemate\033[0m \n" << std::endl;
			return 0;
		}
		interpreter(board, -1);
		system("clear");
		displayBoard(board, white, black);
		if (checkmate(board, 1) == 1)
		{
			std::cout << "\033[31m  Checkmate, Black win\033[0m \n" << std::endl;
			return 0;
		}
		else if (checkmate(board, 1) == 0)
		{
			std::cout << "\033[31m  Draw by stalemate\033[0m \n" << std::endl;
			return 0;
		}
	}
    return 0;
}


int main()
{
  system("resize -s 35 80");
  system("clear");
	int black = -1;
	int white = 1;
	Piece board[64];

	generate(board);

	displayBoard(board, white, black);

	mainLoop(board, black, white);

	return 0;
}
