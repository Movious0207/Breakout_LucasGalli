#pragma once
#include "Constants.h"

void ballCollision(int& circlePosX, int& circlePosY, int radius, Block& block, int& ballDirectionX, int& ballDirectionY);

void paddleCollision(int circlePosX, int circlePosY, int rectanglePosX, int rectanglePosY, int radius, int& ballDirectionX, int& ballDirectionY);

void wallCollision(int& circlePosX, int& circlePosY, int& rectanglePosX, bool& gameStart, int& ballDirectionX, int& ballDirectionY);