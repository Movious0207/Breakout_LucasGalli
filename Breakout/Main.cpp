#include <iostream>
#include <ctime>
#include <string>
#include "Hazards.h"

using namespace std;

enum class Screen
{
	Menu,
	Game,
	Credits,
	Quit
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
	bool isPaused = false;
	bool canPress = true;
	bool isRunning = true;

	int lives = 5;

	float time = 0;
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

	int font = slLoadFont("res/minecraft.ttf");
	slSetFont(font, 30);

	int barraSprite = slLoadTexture("res/barra.png");
	int blueSprite = slLoadTexture("res/BlueBlock.png");
	int redSprite = slLoadTexture("res/RedBlock.png");
	int lBSprite = slLoadTexture("res/LightBlueBlock.png");
	int yellowSprite = slLoadTexture("res/YellowBlock.png");
	int greenSprite = slLoadTexture("res/GreenBlock.png");
	int credits = slLoadTexture("res/Credits.png");
	int menu = slLoadTexture("res/Menu.png");
	int winScreen = slLoadTexture("res/winScreen.png");
	int loseScreen = slLoadTexture("res/loseScreen.png");
	int playButton = slLoadTexture("res/PlayButton.png");
	int credButton = slLoadTexture("res/CreditsButton.png");
	int menuButton = slLoadTexture("res/MenuButton.png");
	int quitButton = slLoadTexture("res/QuitButton.png");

	while (!slShouldClose() && isRunning)
	{
		switch (actualScreen)
		{
		case Screen::Menu:

			mousePosX = slGetMouseX();
			mousePosY = slGetMouseY();

			slSetForeColor(1, 1, 1, 1);

			slSprite(menu, width / 2, height / 2, width, height);

			slSprite(playButton, width / 2, height / 2 - 20, blockWidth, blockHeight);
			slSprite(credButton, width / 2, height / 2 - blockWidth+10, blockWidth, blockHeight);
			slSprite(quitButton, width / 2, height / 2 - blockWidth*2 + 40, blockWidth, blockHeight);

			if (!slGetMouseButton(SL_MOUSE_BUTTON_LEFT) && !slGetKey(SL_KEY_ESCAPE))
			{
				canPress = true;
			}

			if (slGetMouseButton(SL_MOUSE_BUTTON_LEFT) && mousePosX > (width / 2 - 20) - (blockWidth/2)
				&& mousePosX < (width / 2 - 20) + (blockWidth/2)
				&& mousePosY > (height / 2 - 20) - (blockHeight / 2) 
				&& mousePosY < (height / 2 - 20 + blockHeight/2))
			{
				actualScreen = Screen::Game;
			}
			if (slGetMouseButton(SL_MOUSE_BUTTON_LEFT) && mousePosX > (width / 2 - 20 - blockWidth / 2) && canPress
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
				actualScreen = Screen::Quit;
			}

			if (canPress && slGetKey(SL_KEY_ESCAPE))
			{
				isRunning = false;
			}

			slRender();

			break;
		case Screen::Game:

			gameOver = false;
			isPaused = false;
			canPress = false;

			lives = 5;
			timer = 0;
			ballDirectionX = 1;
			ballDirectionY = 1;
			time = 0;
			circlePosY = 100;

			gameStart = false;

			for (int i = 0; i < blockRows; i++)
			{
				for (int j = 0; j < blockCols; j++)
				{
					block[i][j].positionX = (j * (blockWidth + 5) + ((width / 10) - 50));
					block[i][j].positionY = (height - (height / 10)) - (i * (blockHeight + 5));
					block[i][j].isBroken = false;
				}
			}
			while (actualScreen == Screen::Game)
			{
				if (!gameOver && !isPaused)
				{
					time += slGetDeltaTime();
					timer = time;

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

					blocks(block, circlePosX, circlePosY, radius, ballDirectionX, ballDirectionY,blueSprite, redSprite, lBSprite, yellowSprite, greenSprite);

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

					if (!slGetKey(SL_KEY_ESCAPE))
					{
						canPress = true;
					}
					if (slGetKey(SL_KEY_ESCAPE) && canPress)
					{
						isPaused = true;
						canPress = false;
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

					string timerText = "Timer: " + to_string(timer);
					slText(0, height-30, timerText.c_str());

					string liveText = "Lives: " + to_string(lives);
					slText(150, height - 30, liveText.c_str());


					slRender();
				}
				else if (!gameOver && isPaused)
				{

					mousePosX = slGetMouseX();
					mousePosY = slGetMouseY();

					if (!slGetKey(SL_KEY_ESCAPE))
					{
						canPress = true;
					}
					if (slGetKey(SL_KEY_ESCAPE) && canPress)
					{
						isPaused = false; 
						canPress = false;
					}

					slSprite(playButton, width / 2 - 20, height / 2 - 20, blockWidth, blockHeight);
					slSprite(menuButton, width / 2 - 20, height / 2 - blockWidth + 10, blockWidth, blockHeight);

					if (slGetMouseButton(SL_MOUSE_BUTTON_LEFT) && mousePosX > (width / 2 - 20) - (blockWidth / 2)
						&& mousePosX < (width / 2 - 20) + (blockWidth / 2)
						&& mousePosY >(height / 2 - 20) - (blockHeight / 2)
						&& mousePosY < (height / 2 - 20 + blockHeight / 2))
					{
						isPaused = false;
					}
					if (slGetMouseButton(SL_MOUSE_BUTTON_LEFT) && mousePosX > (width / 2 - 20 - blockWidth / 2)
						&& mousePosX < (width / 2 - 20 + blockWidth / 2)
						&& mousePosY >(height / 2 - blockWidth + 10 - blockHeight / 2)
						&& mousePosY < (height / 2 - blockWidth + 10 + blockHeight / 2))
					{
						actualScreen = Screen::Menu;
						canPress = false;
					}

					slRender();
				}
				else
				{
					if (lives <= 0)
					{
						slSprite(loseScreen, width / 2, height / 2, width, height);
					}
					else
					{
						slSprite(winScreen, width / 2, height / 2, width, height);
					}
					if (slGetKey(SL_KEY_ESCAPE))
					{
						actualScreen = Screen::Menu;
						canPress = false;
					}
					slRender();
				}
			}
			
		
			break;
		case Screen::Credits:
			while (actualScreen == Screen::Credits)
			{
				slSprite(credits, width/2, height/2, width, height);
				if (slGetKey(SL_KEY_ESCAPE))
				{
					actualScreen = Screen::Menu;
					canPress = false;
				}
				slRender();
			}
			break;
		default:
			slClose();
			break;
		}

		
	}

	slClose();
}