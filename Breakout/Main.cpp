#include <iostream>
#include "sl.h"

using namespace std;

const int width = 1920;
const int height = 1080;

int main()
{
	slWindow(width, height, "Breakout", 0);

	while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
	{
		slSetBackColor(255, 255, 255);
		slRender();
	}

	slClose();
}