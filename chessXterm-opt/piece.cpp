#include"piece.h"


bool Piece::canMoveTo(Piece board[64], int x, int y, int xDest, int yDest)
{
	int k = x * 8 + y;
	int kDest = xDest * 8 + yDest;
	if ((x == 8) || (y == 8) || (xDest == 8) || (yDest == 8))
	{
		return false;
	}

	if (getName() == "P")
	{
		int dv;
		if (getColor() == -1)
		{
			dv = 1;
		}
		else if (getColor() == 1)
		{
			dv = -1;
		}
        else
        {
            dv = 0;
        }
		if ((board[kDest].getColor() == 0) && (yDest == y) && (xDest == x + dv))
		{
			return true;
		}
		if ((board[kDest].getColor() == 0) && (yDest == y) && (xDest == x + 2 * dv) && (((x == 6) && (getColor() == 1)) || ((x == 1) && (getColor() == -1))))
		{
			setPassant(true);
			return true;
		}
		if ((board[kDest].getColor() == getColor()*(-1)) && (xDest == x + dv) && ((yDest == y - 1) || (yDest == y + 1)))
		{
			return true;
		}

	}
	if (getName() == "N")
	{
		if ((board[kDest].getColor() != getColor()) && ((((xDest == x + 1) || (xDest == x - 1)) && ((yDest == y + 2) || (yDest == y - 2))) || (((xDest == x + 2) || (xDest == x - 2)) && ((yDest == y + 1) || (yDest == y - 1)))))
		{
			return true;
		}
	}
	if (getName() == "B")
	{
		if ((board[kDest].getColor() != getColor()) && (abs(xDest - x) == abs(yDest - y)))
		{
			int coeffx;
			int coeffy;
			if ((xDest - x) > 0)
			{
				coeffx = 1;
			}
			else
			{
				coeffx = -1;
			}
			if ((yDest - y) > 0)
			{
				coeffy = 1;
			}
			else
			{
				coeffy = -1;
			}
			for (int i = 1; i < abs(xDest - x); i++)
			{
				if (board[(x + coeffx*i) * 8 + y + coeffy*i].getColor() != 0)
				{
					return false;
				}
			}
			return true;
		}
		return false;
	}
	if (getName() == "R")
	{
		if ((board[kDest].getColor() != getColor()) && ((xDest == x) ^ (yDest == y)))
		{
			int coeffx;
			int coeffy;
			if (xDest == x)
			{
				coeffx = 0;
				if ((yDest - y) > 0)
				{
					coeffy = 1;
				}
				else
				{
					coeffy = -1;
				}
				for (int i = 1; i < abs(yDest - y); i++)
				{
					if (board[(x + coeffx*i) * 8 + y + coeffy*i].getColor() != 0)
					{
						return false;
					}
				}
				hasMoved_ = true;
				return true;
			}
			else if (yDest == y)
			{
				coeffy = 0;
				if ((xDest - x) > 0)
				{
					coeffx = 1;
				}
				else
				{
					coeffx = -1;
				}
				for (int i = 1; i < abs(xDest - x); i++)
				{
					if (board[(x + coeffx*i) * 8 + y + coeffy*i].getColor() != 0)
					{
						return false;
					}
				}
				hasMoved_ = true;
				return true;
			}

		}
		return false;
	}
	if (getName() == "Q")
	{
		if ((board[kDest].getColor() != getColor()) && (((xDest == x) ^ (yDest == y)) || (abs(xDest - x) == abs(yDest - y))))
		{
			int coeffx;
			int coeffy;
			if ((xDest == x) ^ (yDest == y))
			{
				if (xDest == x)
				{
					coeffx = 0;
					if ((yDest - y) > 0)
					{
						coeffy = 1;
					}
					else
					{
						coeffy = -1;
					}
					for (int i = 1; i < abs(yDest - y); i++)
					{
						if (board[(x + coeffx*i) * 8 + y + coeffy*i].getColor() != 0)
						{
							return false;
						}
					}
					return true;
				}
				else if (yDest == y)
				{
					coeffy = 0;
					if ((xDest - x) > 0)
					{
						coeffx = 1;
					}
					else
					{
						coeffx = -1;
					}
					for (int i = 1; i < abs(xDest - x); i++)
					{
						if (board[(x + coeffx*i) * 8 + y + coeffy*i].getColor() != 0)
						{
							return false;
						}
					}
					return true;
				}
			}
			else if (abs(xDest - x) == abs(yDest - y))
			{
				if ((xDest - x) > 0)
				{
					coeffx = 1;
				}
				else
				{
					coeffx = -1;
				}
				if ((yDest - y) > 0)
				{
					coeffy = 1;
				}
				else
				{
					coeffy = -1;
				}
				for (int i = 1; i < abs(xDest - x); i++)
				{
					if (board[(x + coeffx*i) * 8 + y + coeffy*i].getColor() != 0)
					{
						return false;
					}
				}
				return true;
			}
		}
		return false;
	}
	if (getName() == "K")
	{
		if ((board[kDest].getColor() != getColor()) && (((xDest == x - 1) || (xDest == x) || (xDest == x + 1)) && ((yDest == y - 1) || (yDest == y) || (yDest == y + 1))))
		{
			if ((xDest == x) && (yDest == y))
			{
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




void Piece::display(int color)
{


    if (getName() == "P")
    {
        if (getColor() == -1)
        {
            std::cout << "\u265F ";
        }
        else if (getColor() == 1)
        {
            std::cout << "\u2659 ";
        }
    }
   else if (getName() == "N")
   {
       if (getColor() == -1)
       {
           std::cout << "\u265E ";
       }
       else if (getColor() == 1)
       {
           std::cout << "\u2658 ";
       }
   }
    else if (getName() == "B")
    {
        if (getColor() == -1)
        {
            std::cout << "\u265D ";
        }
        else if (getColor() == 1)
        {
            std::cout << "\u2657 ";
        }
    }
    else if (getName() == "R")
    {
        if (getColor() == -1)
        {
            std::cout << "\u265C ";
        }
        else if (getColor() == 1)
        {
            std::cout << "\u2656 ";
        }
    }
    else if (getName() == "Q")
    {
        if (getColor() == -1)
        {
            std::cout << "\u265B ";
        }
        else if (getColor() == 1)
        {
            std::cout << "\u2655 ";
        }
    }
    else if (getName() == "K")
    {
        if (getColor() == -1)
        {
            std::cout << "\u265A ";
        }
        else if ((getColor() == 1))
        {
            std::cout << "\u2654 ";
        }
    }
    else
    {
        std::cout << "  ";
    }
}
