#include "Collisions.h"

void ballCollision(float& circlePosX, float& circlePosY, int radius, Block& block, float& ballDirectionX, float& ballDirectionY)
{
	if (!block.isBroken)
	{
		if (circlePosY + radius < block.positionY + rectangleHeight / 2
			&& circlePosY + radius > block.positionY - rectangleHeight / 2
			&& circlePosX < block.positionX + rectangleWidth / 2
			&& circlePosX > block.positionX - rectangleWidth / 2)
		{
			block.isBroken = true;
			circlePosY -= 15;
			ballDirectionY *= -1;
		}
		else if (circlePosY - radius < block.positionY + rectangleHeight / 2
			&& circlePosY - radius > block.positionY - rectangleHeight / 2
			&& circlePosX < block.positionX + rectangleWidth / 2
			&& circlePosX > block.positionX - rectangleWidth / 2)
		{
			block.isBroken = true;
			circlePosY += 15;
			ballDirectionY *= -1;
		}
		if (circlePosX - radius < block.positionX + rectangleWidth / 2
			&& circlePosX - radius > block.positionX - rectangleWidth / 2
			&& circlePosY < block.positionY + rectangleHeight / 2
			&& circlePosY > block.positionY - rectangleHeight / 2)
		{
			block.isBroken = true;
			circlePosX += 15;
			ballDirectionX *= -1;
		}
		else if (circlePosX + radius < block.positionX + rectangleWidth / 2
			&& circlePosX + radius > block.positionX - rectangleWidth / 2
			&& circlePosY < block.positionY + rectangleHeight / 2
			&& circlePosY > block.positionY - rectangleHeight / 2)
		{
			block.isBroken = true;
			circlePosX -= 15;
			ballDirectionX *= -1;
		}
	}
}

void paddleCollision(float circlePosX, float circlePosY, float rectanglePosX, float rectanglePosY, int radius, float& ballDirectionX, float& ballDirectionY)
{
	if (circlePosX + radius < rectanglePosX - rectangleWidth / 2
		|| circlePosX - radius > rectanglePosX + rectangleWidth / 2
		|| circlePosY - radius > rectanglePosY + rectangleHeight / 2
		|| circlePosY + radius < rectanglePosY + rectangleHeight / 2 - 40)
	{
	}
	else
	{
		float distanceFromMiddle = (circlePosX - rectanglePosX) /  (rectangleWidth / 2);

		ballDirectionX = distanceFromMiddle;

		ballDirectionY = 1;
	}
}

void wallCollision(float& circlePosX, float& circlePosY, float& rectanglePosX,bool& gameStart, float& ballDirectionX, float& ballDirectionY)
{
	if (circlePosX > width - 10)
	{
		circlePosX -= 15;
		ballDirectionX *= -1;
	}
	if (circlePosX < 0 + 10)
	{
		circlePosX += 15;
		ballDirectionX *= -1;
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