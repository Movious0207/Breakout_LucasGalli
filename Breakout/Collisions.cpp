#include "Collisions.h"

void ballCollision(int& circlePosX, int& circlePosY, int radius, Block& block, int& ballDirectionX, int& ballDirectionY)
{
	if (!block.isBroken)
	{
		if (circlePosY + radius < block.positionY + rectangleHeight / 2
			&& circlePosY + radius > block.positionY - rectangleHeight / 2
			&& circlePosX < block.positionX + rectangleWidth / 2
			&& circlePosX > block.positionX - rectangleWidth / 2)
		{
			block.isBroken = true;
			circlePosY -= 10;
			ballDirectionY *= -1;
		}
		else if (circlePosY - radius < block.positionY + rectangleHeight / 2
			&& circlePosY - radius > block.positionY - rectangleHeight / 2
			&& circlePosX < block.positionX + rectangleWidth / 2
			&& circlePosX > block.positionX - rectangleWidth / 2)
		{
			block.isBroken = true;
			circlePosY += 10;
			ballDirectionY *= -1;
		}
		if (circlePosX - radius < block.positionX + rectangleWidth / 2
			&& circlePosX - radius > block.positionX - rectangleWidth / 2
			&& circlePosY < block.positionY + rectangleHeight / 2
			&& circlePosY > block.positionY - rectangleHeight / 2)
		{
			block.isBroken = true;
			circlePosX += 10;
			ballDirectionX *= -1;
		}
		else if (circlePosX + radius < block.positionX + rectangleWidth / 2
			&& circlePosX + radius > block.positionX - rectangleWidth / 2
			&& circlePosY < block.positionY + rectangleHeight / 2
			&& circlePosY > block.positionY - rectangleHeight / 2)
		{
			block.isBroken = true;
			circlePosX -= 10;
			ballDirectionX *= -1;
		}
	}
}

void paddleCollision(int circlePosX, int circlePosY, int rectanglePosX, int rectanglePosY, int radius, int& ballDirectionX, int& ballDirectionY)
{
	if (circlePosX + radius < rectanglePosX - rectangleWidth / 2
		|| circlePosX - radius > rectanglePosX + rectangleWidth / 2
		|| circlePosY - radius > rectanglePosY + rectangleHeight / 2
		|| circlePosY + radius < rectanglePosY + rectangleHeight / 2 - 40)
	{
	}
	else
	{
		//if (circlePosX > rectanglePosX )
		//{
		//	ballDirectionX = 1;
		//}
		//else
		//{
		//	ballDirectionX = -1;
		//}

		//ballDirectionX = (circlePosX - rectanglePosX) / (rectangleWidth / 2);

		//ballDirectionX = (circlePosX - (rectanglePosX - rectangleWidth / 2)) / (circlePosX + (rectanglePosX - rectangleWidth / 2));
		ballDirectionY = 1;
	}
}

void wallCollision(int& circlePosX,int& circlePosY,int& rectanglePosX,bool& gameStart, int& ballDirectionX, int& ballDirectionY)
{
	if (circlePosX > width - 10)
	{
		ballDirectionX = -1;
	}
	if (circlePosX < 0 + 10)
	{
		ballDirectionX = 1;
	}
	if (circlePosY < 0 + 10)
	{
		circlePosY = 100;
		circlePosX = rectanglePosX;
		ballDirectionY = 1;
		gameStart = false;
	}
	if (circlePosY > height - 10)
	{
		ballDirectionY = -1;
	}
}