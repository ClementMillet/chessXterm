#include<string>
#include<iostream>
#include"piece.h"


void displayMarginLeft(int marg)
{
	std::string margin;
	for (int i = 0; i < marg; i++)
	{
		margin += "\033[0m ";
	}
	std::cout << margin;
}

void displayMarginLeft2(int marg, int i)
{
	std::string margin;
	for (int k = 0; k < marg-2; k++)
	{
		margin += " ";
	}
	std::cout << "\033[0m" << margin << 8-i << " ";
}


void displayMarginUp(int marg)
{
	for (int i = 0; i < marg; i++)
	{
		std::cout << std::endl;
	}
}

void displaySubLine(Piece board[64], int white, int black, int i, int j, int color)
{
    if (color == -1)
    {
        std::cout << "\033[30;46m";
        Piece* piece = &board[i * 8 + j];
        piece->display(-1);
    }
	else if (color == 1)
    {
        std::cout << "\033[30;47m";
        Piece* piece = &board[i *8 + j];
        piece->display(1);
    }
}

void displayInfo(int i)
{
	std::cout << "\033[32m";
	switch(i)
	{
		case 0:
		{
			std::cout << "	Command info :";
			break;
		}
		case 1:
		{
			std::cout << "	Type 's' to save the game";
			break;
		}
		case 2:
		{
			std::cout << "	Type 'l' to load a saved game";
			break;
		}
		case 3:
		{
			std::cout << "	Type 'xiyj' to move a piece, with xi it's coordinate";
			break;
		}
		case 4:
		{
			std::cout << "	and yj it's destination (ex: e2e4)";
			break;
		}
		case 5:
		{
			std::cout << "	(You need to add 'ep' for the 'En passant' capture)";
			break;
		}
		case 6:
		{
			std::cout << "	Type 'OO' to castle (king side)";
			break;
		}
		case 7:
		{
			std::cout << "	Type 'OOO' to castle (queen side)";
			break;
		}
		case 8:
		{
			std::cout << "	Type 'Q', 'N', 'R' or 'B' for the pawn promotion";
			break;
		}
		case 9:
		{
			std::cout << "	('Q' for queen, 'N' for knight, 'R' for rook and 'B' for bishop)";
			break;
		}
	}
}

void displayBoard(Piece board[64], int white, int black)
{
    std::cout << "\n\n\n";
	int margin = 10;
	for (int i = 0; i < 8; i++)
	{
		std::cout << "\033[0m";
		displayMarginLeft2(10, i);
		for (int j = 0; j < 8; j++)
		{
			int color;
			if ((i + j) % 2 == 0)
			{
				color = white;
			}
			else
			{
				color = black;
			}
			displaySubLine(board, white, black, i, j, color);
		}
		std::cout << "\033[0m";
		displayInfo(i);
		std::cout << "\033[0m";
		std::cout << "\n";
	}
	displayMarginLeft(margin);
	std::cout << "a b c d e f g h ";
	displayInfo(8);
	std::cout << "\033[0m";
  std::cout << "\n\n";
}
