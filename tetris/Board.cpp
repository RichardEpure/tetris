#include "Board.h"
#include <iostream>


Board::Board(int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		this->grid.push_back(std::vector<int> {});
		for (int j = 0; j < cols; j++)
		{
			this->grid.at(i).push_back(0);
		}
	}
}

bool Board::superImpose(Tetromino tetro)
{
	std::vector<std::vector<int>> shape = tetro.getShape();
	int rows = shape.size();
	int cols = shape.at(0).size();

	int posX = tetro.getPos().at(0);
	int posY = tetro.getPos().at(1);

	if (posX < 0 || posX > this->grid.at(0).size()-cols || posY < 0 || posY > this->grid.size()-rows)
	{
		return false;
	}

	std::vector<int> pivotPos = tetro.getRelativePivotPos();
	posX += 1-pivotPos.at(0);
	posY += 1-pivotPos.at(1);

	int gridI = posY, gridJ = posX;
	std::vector<std::vector<int>> newGrid = this->grid;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (shape.at(i).at(j) != 0)
			{
				if (newGrid.at(gridI).at(gridJ) != 0)
				{
					return false;
				}
				newGrid.at(gridI).at(gridJ) = shape.at(i).at(j);
			}
			gridJ++;
		}
		gridJ = posX;
		gridI++;
	}
	this->grid = newGrid;
	return true;
}

void Board::clearLine()
{

}

void Board::clearBoard()
{
	for (int i = 0; i < this->grid.size(); i++)
	{
		for (int j = 0; j < this->grid.at(0).size(); j++)
		{
			this->grid.at(i).at(j) = 0;
		}
	}
}

void Board::print()
{
	for (int i = 0; i < this->grid.size(); i++)
	{
		for (int j = 0; j < this->grid.at(0).size(); j++)
		{
			std::cout << this->grid.at(i).at(j) << " ";
		}
		std::cout << std::endl;
	}
}