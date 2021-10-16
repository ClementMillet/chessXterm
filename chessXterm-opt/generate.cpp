#include<string>
#include<vector>
#include"generate.h"
#include"piece.h"

void generate(Piece board[64])
{

	Piece e, p, nw1, nw2, nb1, nb2, bw1, bw2, bb1, bb2, rw1, rw2, rb1, rb2, qw, qb, kw, kb;


	rb1.setColor(-1);
	rb1.setName("R");
	board[0] = rb1;

	nb1.setColor(-1);
	nb1.setName("N");
	board[1] = nb1;

	bb1.setColor(-1);
	bb1.setName("B");
	board[2] = bb1;

	qb.setColor(-1);
	qb.setName("Q");
	board[3] = qb;

	kb.setColor(-1);
	kb.setName("K");
	board[4] = kb;

	bb2.setColor(-1);
	bb2.setName("B");
	board[5] = bb2;

	nb2.setColor(-1);
	nb2.setName("N");
	board[6] = nb2;

	rb2.setColor(-1);
	rb2.setName("R");
	board[7] = rb2;

	for (int i = 0; i < 8; i++)
	{
		p.setColor(-1);
		p.setName("P");
		board[8+i] = p;
	}


	for (int i = 0; i < 8; i++)
	{
		p.setColor(1);
		p.setName("P");
		board[48+i] = p;
	}

	rw1.setColor(1);
	rw1.setName("R");
	board[56] = rw1;

	nw1.setColor(1);
	nw1.setName("N");
	board[57] = nw1;

	bw1.setColor(1);
	bw1.setName("B");
	board[58] = bw1;

	qw.setColor(1);
	qw.setName("Q");
	board[59] = qw;

	kw.setColor(1);
	kw.setName("K");
	board[60] = kw;

	bw2.setColor(1);
	bw2.setName("B");
	board[61] = bw2;

	nw2.setColor(1);
	nw2.setName("N");
	board[62] = nw2;

	rw2.setColor(1);
	rw2.setName("R");
	board[63] = rw2;

}


bool isInCheck(Piece board[64], int color)
{
	for (int k = 0; k < 64; k++)
	{
		int i = k/8;
		int j = k%8;
		if ((board[k].getName() == "K") && (board[k].getColor() == color))
		{
			for (int z = 0; z < 64; z++)
			{
				int x = z/8;
				int y = z%8;
				if ((board[z].getColor() == (board[k].getColor())*(-1)) && (board[z].canMoveTo(board, x, y, i, j)))
				{
					return true;
				}
			}
			return false;
		}
	}
	return false;
}

void resetPassant(Piece board[64], int color)
{
	for (int k = 0; k < 64; k++)
	{
		if ((board[k].getPassant()) && (board[k].getColor() == color))
		{
			board[k].setPassant(false);
		}
	}
}

bool kingSideCastling(Piece board[64], int color)
{
	if (color == 1)
	{
		if (board[63].getHasMoved() || board[60].getHasMoved() || (board[62].getColor() != 0) || (board[61].getColor() != 0))
		{
			return false;
		}
		else
		{
			for (int k = 0; k < 64; k++)
			{
				int i = k/8;
				int j = k%8;	
				if ((board[k].getColor() == color * (-1)) && (board[k].canMoveTo(board, i, j, 7, 4) || board[k].canMoveTo(board, i, j, 7, 5) || board[k].canMoveTo(board, i, j, 7, 6)))
				{
					return false;
				}
				
			}
			Piece empty;
			board[61] = board[63];
			board[62] = board[60];
			board[63] = empty;
			board[60] = empty;
			return true;
		}
	}
	else if (color == -1)
	{
	if (board[7].getHasMoved() || board[4].getHasMoved() || (board[6].getColor() != 0) || (board[5].getColor() != 0))
	{
		return false;
	}
	else
	{
		for (int k = 0; k < 64; k++)
		{
			int i = k/8;
			int j = k%8;
			if ((board[k].getColor() == color * (-1)) && (board[k].canMoveTo(board, i, j, 0, 4) || board[k].canMoveTo(board, i, j, 0, 5) || board[k].canMoveTo(board, i, j, 0, 6)))
			{
				return false;
			}
			
		}
		Piece empty;
		board[5] = board[7];
		board[6] = board[4];
		board[7] = empty;
		board[4] = empty;
		return true;
	}
	}
	return false;
}

bool queenSideCastling(Piece board[64], int color)
{
	if (color == 1)
	{
		if (board[56].getHasMoved() || board[60].getHasMoved() || (board[59].getColor() != 0) || (board[58].getColor() != 0) || (board[57].getColor() != 0))
		{
			return false;
		}
		else
		{
			for (int k = 0; k < 64; k++)
			{
				int i = k/8;
				int j = k%8;
				if ((board[k].getColor() == color * (-1)) && (board[k].canMoveTo(board, i, j, 7, 4) || board[k].canMoveTo(board, i, j, 7, 3) || board[k].canMoveTo(board, i, j, 7, 2) || board[k].canMoveTo(board, i, j, 7, 1)))
				{
					return false;
				}
				
			}
			Piece empty;
			board[59] = board[56];
			board[58] = board[60];
			board[56] = empty;
			board[60] = empty;
			return true;
		}

	}
	else if (color == -1)
	{
		if (board[0].getHasMoved() || board[4].getHasMoved() || (board[3].getColor() != 0) || (board[2].getColor() != 0) || (board[1].getColor() != 0))
		{
			return false;
		}
		else
		{
			for (int k = 0; k < 64; k++)
			{
				int i = k/8;
				int j = k%8;
				if ((board[k].getColor() == color * (-1)) && (board[k].canMoveTo(board, i, j, 0, 4) || board[k].canMoveTo(board, i, j, 0, 3) || board[k].canMoveTo(board, i, j, 0, 2) || board[k].canMoveTo(board, i, j, 0, 1)))
				{
					return false;
				}
			}
			Piece empty;
			board[3] = board[0];
			board[2] = board[4];
			board[0] = empty;
			board[4] = empty;
			return true;
		}
	}
	return false;
}



int checkmate(Piece board[64], int color)
{
	for (int k = 0; k < 64; k++)
	{
		int i = k/8;
		int j = k%8;
		if (board[k].getColor() == color)
		{
			for (int z = 0; z < 64; z++)
			{
				int x = z/8;
				int y = z%8;
				Piece trans;
				Piece empty;
				if (board[k].canMoveTo(board, i, j, x, y))
				{
					trans = board[z];
					board[z] = board[k];
					board[k] = empty;


					if (isInCheck(board, color) == false)
					{
						board[k] = board[z];
						board[z] = trans;
						return -1;
					}
					board[k] = board[z];
					board[z] = trans;
				}
				else if (enPassant(board, i, j, x, y))
				{
					int dv;
					if (board[z].getColor() == -1)
					{
						dv = 1;
					}
					else if (board[z].getColor() == 1)
					{
						dv = -1;
					}
					else
					{
						dv = 0;
					}
					board[k] = board[z];
					board[z] = empty;
					board[(x - dv) * 8 + y].setName("P");
					board[(x - dv) * 8 + y].setColor(board[k].getColor()*(-1));
					board[(x - dv) * 8 + y].setPassant(true);
					return -1;
				}
			}
		}
	}
	if (isInCheck(board, color))
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}


bool move(Piece board[64], int x, int y, int xDest, int yDest)
{
	int z = x * 8 + y;
	int zDest = xDest * 8 + yDest;
	if (board[z].canMoveTo(board, x, y, xDest, yDest))
	{
		Piece mem;
		Piece trans;
		Piece empty;
		mem = board[zDest];
		board[zDest] = board[z];
		board[z] = empty;
		if (isInCheck(board, board[zDest].getColor()))
		{
			trans = board[zDest];
			board[zDest] = mem;
			board[z] = trans;
			return false;
		}
		else
		{
			if ((((xDest == 7) && (board[zDest].getColor() == -1)) || ((xDest == 0) && (board[zDest].getColor() == 1))) && (board[zDest].getName() == "P"))
			{
				bool again = true;
				std::string piece;
				do
				{
					std::cout << "Promotion ? : ";
					std::cin >> piece;
					std::cout << std::endl;
					if ((piece == "N") || (piece == "B") || (piece == "R") || (piece == "Q"))
					{
						board[zDest].setName(piece);
						again = false;
					}
					else
					{
						std::cout << "Invalid promotion, retry" << std::endl;
					}
				} while (again);
				return true;
			}
			else
			{
				board[zDest].setHasMoved(true);
				return true;
			}
		}
	}
	else
	{
		return false;
	}
}


bool enPassant(Piece board[64], int x, int y, int xDest, int yDest)
{
	int z = x * 8 + y;
	int zDest = xDest * 8 + yDest; 
	if (board[z].getName() == "P")
	{
		int dv;
		if (board[z].getColor() == -1)
		{
			dv = 1;
		}
		else if (board[z].getColor() == 1)
		{
			dv = -1;
		}
		else
		{
			dv = 0;
		}
		if ((board[zDest].getColor() == 0) && (board[(xDest - dv) * 8 + yDest].getPassant()) && (board[(xDest - dv) * 8 + yDest].getColor() == (-1) * board[z].getColor()) && (xDest == x + dv) && ((yDest == y - 1) || (yDest == y + 1)))
		{
			Piece empty;
			Piece init = board[z];
			Piece fin = board[zDest];
			Piece inter = board[(xDest - dv) * 8 + yDest];
			board[z] = empty;
			board[zDest] = init;
			board[(xDest - dv) * 8 + yDest] = empty;
			if (isInCheck(board, board[zDest].getColor()))
			{
				board[z] = init;
				board[zDest] = fin;
				board[(xDest - dv) * 8 + yDest] = inter;
				return false;
			}
			else
			{
				return true;
			}
		}
		return false;
	}
	return false;
}
