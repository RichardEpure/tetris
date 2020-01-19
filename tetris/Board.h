#pragma once
 
#include "Tetromino.h"
#include <vector>


class Board
{
private:
	std::vector<std::vector<int>> grid;

public:
	Board(int rows, int cols);
	bool superImpose(Tetromino tetro);
	void clearLine();
	void clearBoard();
	void print();
};