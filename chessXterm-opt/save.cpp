#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include"piece.h"
#include"interpreter.h"

void save(Piece board[64], int color)
{
  std::ofstream flux("savefile.txt");
  if (!flux.is_open())
  {
    std::cout << "  Cannot save : the save file is open" << std::endl;
  }
  else
  {
    flux << color << std::endl;
    for (int k = 0; k < 64; k++)
    {
      if (board[k].getName() != "e")
      {
        int i = k/8;
        int j = k%8;
        flux << intToColor(board[k].getColor()) + " " + board[k].getName() + toLetter(j) + toNum(i);
        if (!board[k].getHasMoved())
        {
          flux << " nm" << std::endl;
        }
        else if (board[k].getPassant())
        {
          flux << " ep" << std::endl;
        }
        else
        {
          flux << std::endl;
        }
      }
    }
  }
}

int load(Piece board[64])
{
  std::ifstream flux("savefile.txt");
  if (!flux.is_open())
  {
    std::cout << "  Cannot load : the save file is open" << std::endl;
  }
  else
  {
    int color;
    std::string Color;
    getline(flux,Color);
    std::stringstream sc;
    sc << Color;
    sc >> color;
    for (int k = 0; k < 64; k++)
    {
      board[k].setName("e");
      board[k].setColor(0);
      board[k].setHasMoved(true);
      board[k].setPassant(false);
    }
    while (!flux.eof())
    { 
      std::string info;
      getline(flux,info);
      std::cout << info << std::endl;
      if (info.size() > 4)
      {
        std::string name(info,2,1);
        std::string col(info,3,1);
        std::string lig(info,4,1);
        std::string color(info,0,1);
        int j = yFind(col);
        int i = xFind(lig);
        board[i*8+j].setName(name);
        board[i*8+j].setColor(colorToInt(color));
        if (info.size() > 5)
        {
          std::string suffix(info,6,2);
          if (suffix == "nm")
          {
            board[i*8+j].setHasMoved(false);
          }
          else if (suffix == "ep")
          {
            board[i*8+j].setPassant(true);
          }
        } 
      }
    }
    return color;
  }
  return 0;
}
