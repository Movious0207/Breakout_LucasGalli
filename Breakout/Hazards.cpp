#include "Hazards.h"

void blocks(Block block[blockRows][blockCols], int blueSprite, float& circlePosX, float& circlePosY, int radius, float& ballDirectionX, float& ballDirectionY)
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
						slRectangleFill(block[i][j].positionX, block[i][j].positionY, blockWidth, blockHeight);
						break;
					case 1:
						slSetForeColor(0, 1, 0, 0.5);
						slRectangleFill(block[i][j].positionX, block[i][j].positionY, blockWidth, blockHeight);
						break;
					case 2:
						slSetForeColor(0, 0, 1, 1);
						slSprite(blueSprite, block[i][j].positionX, block[i][j].positionY, blockWidth, blockHeight);
						break;
					case 3:
						slSetForeColor(1, 1, 0, 0.5);
						slRectangleFill(block[i][j].positionX, block[i][j].positionY, blockWidth, blockHeight);
						break;
					case 4:
						slSetForeColor(0, 1, 1, 0.9);
						slRectangleFill(block[i][j].positionX, block[i][j].positionY, blockWidth, blockHeight);
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
						slRectangleFill(block[i][j].positionX, block[i][j].positionY, blockWidth, blockHeight);
						break;
					case 1:
						slSetForeColor(0, 1, 0, 1);
						slRectangleFill(block[i][j].positionX, block[i][j].positionY, blockWidth, blockHeight);
						break;
					case 2:
						slSetForeColor(0, 0, 1, 0.8);
						slSprite(blueSprite, block[i][j].positionX, block[i][j].positionY, blockWidth, blockHeight);
						break;
					case 3:
						slSetForeColor(1, 1, 0, 1);
						slRectangleFill(block[i][j].positionX, block[i][j].positionY, blockWidth, blockHeight);
						break;
					case 4:
						slSetForeColor(0, 1, 1, 0.5);
						slRectangleFill(block[i][j].positionX, block[i][j].positionY, blockWidth, blockHeight);
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