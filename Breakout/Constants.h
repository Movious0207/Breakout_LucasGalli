#pragma once
struct Block
{
	int positionX;
	int positionY;
	bool isBroken;
};

const int width = 1440;
const int height = 800;

const int rectangleWidth = width / 10 + 8;
const int rectangleHeight = height / 100 * 4;

const int blockCols = 11;
const int blockRows = 5;

const int blockWidth = width / 12;
const int blockHeight = (height / 100) * 6;