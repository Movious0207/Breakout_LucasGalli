#include <iostream>
#include <ctime>
#include "Hazards.h"

enum class Screen
{
	Menu,
	Game,
	Credits
};

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

	float mousePosX = 0;
	float mousePosY = 0;

	bool gameOver = false;

	int lives = 5;

	int timer = 0;

	Block block[blockRows][blockCols] = { {0} };

	Screen actualScreen = Screen::Menu;

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
	int credits = slLoadTexture("res/Credits.png");
	int menu = slLoadTexture("res/Menu.png");

	while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
	{
		switch (actualScreen)
		{
		case Screen::Menu:

			mousePosX = slGetMouseX();
			mousePosY = slGetMouseY();

			slSprite(menu, width / 2, height / 2, width, height);

			slRectangleFill(width / 2 - 20, height / 2 - 20, blockWidth, blockHeight);
			slRectangleFill(width / 2 - 20, height / 2 - blockWidth+10, blockWidth, blockHeight);
			slRectangleFill(width / 2 - 20, height / 2 - blockWidth*2 + 40, blockWidth, blockHeight);

			if (slGetMouseButton(SL_MOUSE_BUTTON_LEFT) && mousePosX > (width / 2 - 20) - (blockWidth/2)
				&& mousePosX < (width / 2 - 20) + (blockWidth/2)
				&& mousePosY > (height / 2 - 20) - (blockHeight / 2) 
				&& mousePosY < (height / 2 - 20 + blockHeight/2))
			{
				actualScreen = Screen::Game;
			}
			if (slGetMouseButton(SL_MOUSE_BUTTON_LEFT) && mousePosX > (width / 2 - 20 - blockWidth / 2)
				&& mousePosX < (width / 2 - 20 + blockWidth / 2)
				&& mousePosY >(height / 2 - blockWidth + 10 - blockHeight / 2)
				&& mousePosY < (height / 2 - blockWidth + 10 + blockHeight / 2))
			{
				actualScreen = Screen::Credits;
			}
			if (slGetMouseButton(SL_MOUSE_BUTTON_LEFT) && mousePosX > (width / 2 - 20 - blockWidth / 2)
				&& mousePosX < (width / 2 - 20 + blockWidth / 2)
				&& mousePosY >(height / 2 - blockWidth * 2 + 40 - blockHeight / 2)
				&& mousePosY < (height / 2 - blockWidth * 2 + 40 + blockHeight / 2))
			{
				actualScreen = Screen::Credits;
			}

			slRender();

			break;
		case Screen::Game:

			timer += slGetDeltaTime();

			slSetBackColor(0, 0, 0);
			slSetForeColor(1, 1, 1, 1);

			if (slGetKey(SL_KEY_RIGHT))
			{
				if (rectanglePosX < width - (rectangleWidth / 2))
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

			wallCollision(circlePosX, circlePosY, rectanglePosX, gameStart, ballDirectionX, ballDirectionY, lives);

			paddleCollision(circlePosX, circlePosY, rectanglePosX, rectanglePosY, radius, ballDirectionX, ballDirectionY);

			if (slGetKey(' '))
			{
				actualScreen = Screen::Menu;
			}

			gameOver = true;
			for (int rows = 0; rows < blockRows; rows++)
			{
				for (int cols = 0; cols < blockCols; cols++)
				{
					if (!block[rows][cols].isBroken)
					{
						gameOver = false;
					}
				}
			}

			if (lives <= 0)
			{
				gameOver = true;
			}

			slRender();
		
			break;
		case Screen::Credits:
			while (actualScreen == Screen::Credits)
			{
				slSprite(credits, width/2, height/2, width, height);
				if (slGetKey(' '))
				{
					actualScreen = Screen::Menu;
				}
				slRender();
			}
			break;
		default:
			break;
		}

		
	}

	slClose();
}