#pragma once
#include<string>
#include<iostream>

class Piece
{
private:
	std::string name_;
	int color_;
	bool passant_;
	bool hasMoved_;
public:
	Piece() {
		name_ = "e";
		color_ = 0;
		passant_ = false;
		hasMoved_ = false;
	};
	~Piece() {

	};
	void setName(std::string name)
	{
		name_ = name;
	}
	void setColor(int color) {
		color_ = color;
	};
	std::string getName() {
		return name_;
	}
	int getColor() const {
		return color_;
	};
	void setPassant(bool p) {
		passant_ = p;
	};
	bool getPassant() {
		return passant_;
	};
	bool getHasMoved() {
		return hasMoved_;
	};
	void setHasMoved(bool b) {
		hasMoved_ = b;
	};

	void display(int color);
	bool canMoveTo(Piece board[64], int x, int y, int xDest, int yDest);
};
