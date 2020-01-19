#include "Tetromino.h"
#include <iostream>


Tetromino::Tetromino(enum class Shape shape)
{
	this->rotationIndex = 0;

	std::vector<std::vector<int>> shape_data;
	switch (shape)
	{
	case Shape::I:
		shape_data = 
		{
			{ 1, 1, 1, 1 }
		};
		break;
	case Shape::O:
		shape_data =
		{
			{ 1, 1 },
			{ 1, 1 }
		};
		break;
	case Shape::T:
		shape_data =
		{
			{ 0, 1, 0 },
			{ 1, 1, 1 }
		};
		break;
	case Shape::S:
		shape_data =
		{
			{ 0, 1, 1 },
			{ 1, 1, 0 }
		};
		break;
	case Shape::Z:
		shape_data =
		{
			{ 1, 1, 0 },
			{ 0, 1, 1 }
		};
		break;
	case Shape::J:
		shape_data =
		{
			{ 1, 0, 0 },
			{ 1, 1, 1 }
		};
		break;
	case Shape::L:
		shape_data =
		{
			{ 0, 0, 1 },
			{ 1, 1, 1 },
			{ 0, 0, 0 }
		};
		break;
	}
	this->shape = shape_data;

	switch (shape)
	{
	case Shape::J:
	case Shape::L:
	case Shape::S:
	case Shape::T:
	case Shape::Z:
		this->offset =
		{
			{ {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0} },
			{ {0, 0}, {1, 0}, {1,-1}, {0, 2}, {1, 2} },
			{ {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0} },
			{ {0, 0}, {-1,0}, {-1,-1}, {0,2}, {-1,2} },
		};
		break;
	case Shape::I:
		this->offset =
		{
			{ {0, 0}, {-1,0}, {2, 0}, {-1,0}, {2, 0} },
			{ {-1,0}, {0, 0}, {0, 0}, {0, 1}, {0,-2} },
			{ {-1,1}, {1, 1}, {-2,1}, {1, 0}, {-2,0} },
			{ {0, 1}, {0, 1}, {0, 1}, {0,-1}, {0, 2} },
		};
		break;
	case Shape::O:
		this->offset =
		{
			{ {0, 0} },
			{ {0,-1} },
			{ {-1,-1} },
			{ {-1,0} },
		};
		break;
	}
}

void Tetromino::rotate(bool clockwise)
{
	std::vector<std::vector<int>> transposed;

	for (int col = 0; col < this->shape.front().size(); col++)
	{
		transposed.push_back(std::vector<int> {});
	}

	for (int i = 0; i < this->shape.size(); i++)
	{
		for (int j = 0; j < this->shape.front().size(); j++)
		{
			transposed.at(j).push_back(this->shape.at(i).at(j));
		}
	}

	std::vector<std::vector<int>> newShape;

	if (clockwise)
	{
		for (int i = 0; i < transposed.size(); i++)
		{
			newShape.push_back(std::vector<int> {});
			for (int j = 0; j < transposed.front().size(); j++)
			{
				newShape.at(i).push_back(transposed.at(i).at(transposed.front().size() - j - 1));
			}
		}
		this->incrementRIndex(1);
	}
	else
	{
		for (int i = 0; i < transposed.size(); i++)
		{
			newShape.push_back(std::vector<int> {});
			for (int j = 0; j < transposed.front().size(); j++)
			{
				newShape.at(i).push_back(transposed.at(transposed.size() - i - 1).at(j));
			}
		}
		this->incrementRIndex(-1);
	}

	this->shape = newShape;
}

void Tetromino::incrementRIndex(int val)
{
	if (this->rotationIndex >= 3 && val > 0)
	{
		this->rotationIndex = 0;
	}
	else if (this->rotationIndex <= 0 && val < 0)
	{
		this->rotationIndex = 3;
	}
	else
	{
		this->rotationIndex += val;
	}
}

void Tetromino::update()
{
}

void Tetromino::print()
{
	for (int i = 0; i < this->shape.size(); i++)
	{
		for (int j = 0; j < this->shape.front().size(); j++)
		{
			std::cout << this->shape.at(i).at(j) << " ";
		}
		std::cout << std::endl;
	}
}
