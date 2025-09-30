#pragma once
#include "Constants.h"

void ballCollision(float& circlePosX, float& circlePosY, int radius, Block& block, float& ballDirectionX, float& ballDirectionY);

void paddleCollision(float circlePosX, float circlePosY, float rectanglePosX, float rectanglePosY, int radius, float& ballDirectionX, float& ballDirectionY);

void wallCollision(float& circlePosX, float& circlePosY, float& rectanglePosX, bool& gameStart, float& ballDirectionX, float& ballDirectionY, int& lives);