#include<string>
#include<vector>
#include<iostream>
#include"piece.h"
#include"generate.h"
#include"interface.h"
#include"save.h"


int yFind(std::string com)
{
	if (com == "a")
	{
		return 0;
	}
	else if (com == "b")
	{
		return 1;
	}
	else if (com == "c")
	{
		return 2;
	}
	else if (com == "d")
	{
		return 3;
	}
	else if (com == "e")
	{
		return 4;
	}
	else if (com == "f")
	{
		return 5;
	}
	else if (com == "g")
	{
		return 6;
	}
	else if (com == "h")
	{
		return 7;
	}
	else
	{
		return 8;
	}

}

int xFind(std::string com)
{
	if (com == "8")
	{
		return 0;
	}
	else if (com == "7")
	{
		return 1;
	}
	else if (com == "6")
	{
		return 2;
	}
	else if (com == "5")
	{
		return 3;
	}
	else if (com == "4")
	{
		return 4;
	}
	else if (com == "3")
	{
		return 5;
	}
	else if (com == "2")
	{
		return 6;
	}
	else if (com == "1")
	{
		return 7;
	}
	else
	{
		return 8;
	}
}

std::string toLetter(int x)
{
	switch (x)
	{
	case 0:
		return "a";
	case 1:
		return "b";
	case 2:
		return "c";
	case 3:
		return "d";
	case 4:
		return "e";
	case 5:
		return "f";
	case 6:
		return "g";
	case 7:
		return "h" ;
	default:
		return "error";
	}
} 

std::string toNum(int y)
{
	switch (y)
	{
	case 0:
		return "8";
	case 1:
		return "7";
	case 2:
		return "6";
	case 3:
		return "5";
	case 4:
		return "4";
	case 5:
		return "3";
	case 6:
		return "2";
	case 7:
		return "1";
	default:
		return "error";
	}
} 

std::string intToColor(int c)
{
	switch (c)
	{
	case -1:
		return "B"; 
	case 1:
		return "W";
	default:
		return "error";
	}
}

int colorToInt(std::string c)
{
	if (c == "B") 
	{
		return -1;
	}
	else if (c == "W")
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*
bool isValid(Piece board[8][8], std::string piece, int x, int y , int xDest, int yDest, int color )
{
	for (int i=0; i< 8; i++)
		for (int j = 0; j < 8; j++)
		{
			if ((board[i][j].getName() == piece) && (board[i][j].getColor() == color ) && (i == x) && (j == y))
			{
				return board[i][j].canMoveTo(board, x, y, xDest, yDest);
			}
		}
	return false;
}
*/

void interpreter(Piece board[64], int color)
{
	Piece mem;
	Piece empty;
	std::string com;
	std::string piece;
	std::string X;
	std::string Y;
	std::string Xdest;
	std::string Ydest;
	int x;
	int y;
	int xDest;
	int yDest;
	if (isInCheck(board, color))
	{
		std::cout << "\033[31m  Check\033[0m" << std::endl;
	}

	bool again = true;
	do
	{
		if (color == -1)
		{
			std::cout << "  Black : ";
		}
		else if (color == 1)
		{
			std::cout << "  White : ";
		}

		std::cin >> com;
		/*com = "d2-d4";*/
		if (com == "s")
		{
			save(board, color);
		}
		else if (com == "l")
		{
			if (load(board) == (-1)*color)
			{
				again = false;
			}
			else
			{
				system("clear");
				displayBoard(board, 1, -1);
			}
		}
		else if ((com == "OO") && (kingSideCastling(board, color)))
		{
			again = false;
		}
		else if (((com == "OOO") && (queenSideCastling(board, color))))
		{
			again = false;
		}
		else if (com.size() == 4)
		{
			X = com[1];
			Y = com[0];
			Xdest = com[3];
			Ydest = com[2];

			x = xFind(X);
			y = yFind(Y);
			xDest = xFind(Xdest);
			yDest = yFind(Ydest);
			if ((board[x * 8 + y].getColor() == color))
			{
				if (move(board, x, y, xDest, yDest))
				{
					again = false;
				}
				else
				{
					std::cout << "  Illegal move, try again" << std::endl;
				}
			}
			else
			{
				std::cout << "  Illegal move, try again" << std::endl;
			}
		}
		else if (com.size() == 6)
		{
			std::string keyword(com, 4, 2);
			if (keyword == "ep")
			{
				X = com[1];
				Y = com[0];
				Xdest = com[3];
				Ydest = com[2];
				piece = com[4];

				x = xFind(X);
				y = yFind(Y);
				xDest = xFind(Xdest);
				yDest = yFind(Ydest);
				if (enPassant(board, x, y, xDest, yDest))
				{
					again = false;
				}
				else
				{
					std::cout << "  Illegal move, try again" << std::endl;
				}
			}
			else
			{
				std::cout << "  Illegal move, try again" << std::endl;
			}
		}
		else
		{
			std::cout << "  Invalid command, try again" << std::endl;
		}
	} while (again);
	resetPassant(board, color*(-1));

}
