#pragma once

#include <vector>


enum class Shape
{
	I, O, T, S, Z, J, L
};

class Tetromino
{
private:
	std::vector<std::vector<int>> shape;
	std::vector<std::vector<std::vector<int>>> offset;
	int rotationIndex;

	void incrementRIndex(int val);

public:
	Tetromino(enum class Shape shape);
	void rotate(bool clockwise);
	void update();
	void print();
};