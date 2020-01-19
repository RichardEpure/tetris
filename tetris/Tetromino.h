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
	std::vector<int> position;

	void incrementRIndex(int val);

public:
	Tetromino(enum class Shape shape, std::vector<int> pos);
	void rotate(bool clockwise);
	void applyOffset(bool clockwise, int offsetNumber);
	std::vector<std::vector<int>> getShape();
	std::vector<int> getPos();
	std::vector<int> getRelativePivotPos();
	void move(int x, int y);
	void print();
};