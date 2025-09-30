#pragma once
#include <cmath>

struct Block
{
	int positionX;
	int positionY;
	bool isBroken;
};

const int width = 1240;
const int height = 800;

const int rectangleWidth = width / 10 + 8;
const int rectangleHeight = height / 100 * 4;

const int blockCols = 11;
const int blockRows = 5;

const float blockWidth = width / 12;
const float blockHeight = (height / 100) * 6;
