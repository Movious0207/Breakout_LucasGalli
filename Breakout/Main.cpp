#include <iostream>
#include <ctime>
#include "Hazards.h"

int main()
{
	srand(time(nullptr));

	float rectanglePosX = width / 2;
	float rectanglePosY = 50;
	bool gameStart = false;

	float circlePosX = 0;
	float circlePosY = 100;

	int speed = 800;
	int ballSpeed = 700;

	float ballDirectionX = 1;
	float ballDirectionY = 1;

	int timer = 0;

	Block block[blockRows][blockCols] = { {0} };

	for (int i = 0; i < blockRows; i++)
	{
		for (int j = 0; j < blockCols; j++)
		{
			block[i][j].positionX = (j * (blockWidth + 5) + ((width / 10)-50));
			block[i][j].positionY = (height - (height/10)) - (i * (blockHeight + 5));
			block[i][j].isBroken = false;
		}
	}

	int radius = (width/1000) * 20;

	slWindow(width, height, "Breakout", false);

	int barraSprite = slLoadTexture("res/barra.png");
	int blueSprite = slLoadTexture("res/BlueBlock.png");

	while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
	{
		timer += slGetDeltaTime();

		slSetBackColor(0, 0, 0);
		slSetForeColor(1, 1, 1, 1);

		if (slGetKey(SL_KEY_RIGHT))
		{
			if (rectanglePosX < width - (rectangleWidth/2))
			{
				rectanglePosX += speed * slGetDeltaTime();
			}
		}
		if (slGetKey(SL_KEY_LEFT))
		{
			if (rectanglePosX > 0 + (rectangleWidth / 2))
			{
				rectanglePosX -= speed * slGetDeltaTime();
			}
		}

		blocks(block, blueSprite, circlePosX, circlePosY, radius, ballDirectionX, ballDirectionY);

		slSprite(barraSprite, rectanglePosX, rectanglePosY, rectangleWidth, rectangleHeight);

		if (!gameStart)
		{
			slCircleFill(rectanglePosX, circlePosY, radius, 15);

			circlePosX = rectanglePosX;

			if (slGetKey(SL_KEY_UP))
			{
				gameStart = true;
				if (slGetKey(SL_KEY_RIGHT))
				{
					ballDirectionX = 1;
				}
				if (slGetKey(SL_KEY_LEFT))
				{
					ballDirectionX = -1;
				}
			}
		}
		else
		{
			slCircleFill(circlePosX, circlePosY, radius, 15);

			circlePosX += ballSpeed * ballDirectionX * slGetDeltaTime();

			circlePosY += ballSpeed * ballDirectionY * slGetDeltaTime();
		}

		wallCollision(circlePosX, circlePosY, rectanglePosX, gameStart, ballDirectionX, ballDirectionY);

		paddleCollision(circlePosX, circlePosY, rectanglePosX, rectanglePosY, radius, ballDirectionX, ballDirectionY);

		slRender();
	}

	slClose();
}