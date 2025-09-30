#include "Hazards.h"

void blocks(Block block[blockRows][blockCols], float& circlePosX, float& circlePosY, int radius, float& ballDirectionX, float& ballDirectionY, int blueSprite, int redSprite, int lbSprite, int yellowSprite, int greenSprite)
{
	for (int i = 0; i < blockRows; i++)
	{
		for (int j = 0; j < blockCols; j++)
		{
			if (!block[i][j].isBroken)
			{
				if (j % 2 == 0)
				{
					switch (i)
					{
					case 0:
						slSetForeColor(1, 0.1, 0, 1);
						slSprite(redSprite, block[i][j].positionX, block[i][j].positionY, blockWidth, blockHeight);
						break;
					case 1:
						slSetForeColor(0, 1, 0, 0.5);
						slSprite(greenSprite, block[i][j].positionX, block[i][j].positionY, blockWidth, blockHeight);
						break;
					case 2:
						slSetForeColor(0, 0, 1, 1);
						slSprite(blueSprite, block[i][j].positionX, block[i][j].positionY, blockWidth, blockHeight);
						break;
					case 3:
						slSetForeColor(1, 1, 0, 0.5);
						slSprite(yellowSprite, block[i][j].positionX, block[i][j].positionY, blockWidth, blockHeight);
						break;
					case 4:
						slSetForeColor(0, 1, 1, 0.9);
						slSprite(lbSprite, block[i][j].positionX, block[i][j].positionY, blockWidth, blockHeight);
						break;
					default:
						break;
					}
				}
				else
				{
					switch (i)
					{
					case 0:
						slSetForeColor(1, 0.1, 0, 0.5);
						slSprite(redSprite, block[i][j].positionX, block[i][j].positionY, blockWidth, blockHeight);
						break;
					case 1:
						slSetForeColor(0, 1, 0, 1);
						slSprite(greenSprite, block[i][j].positionX, block[i][j].positionY, blockWidth, blockHeight);
						break;
					case 2:
						slSetForeColor(0, 0, 1, 0.8);
						slSprite(blueSprite, block[i][j].positionX, block[i][j].positionY, blockWidth, blockHeight);
						break;
					case 3:
						slSetForeColor(1, 1, 0, 1);
						slSprite(yellowSprite, block[i][j].positionX, block[i][j].positionY, blockWidth, blockHeight);
						break;
					case 4:
						slSetForeColor(0, 1, 1, 0.5);
						slSprite(lbSprite, block[i][j].positionX, block[i][j].positionY, blockWidth, blockHeight);
						break;
					default:
						break;
					}
				}
				ballCollision(circlePosX, circlePosY, radius, block[i][j], ballDirectionX, ballDirectionY);
			}
		}
	}
	slSetForeColor(1, 1, 1, 1);
}