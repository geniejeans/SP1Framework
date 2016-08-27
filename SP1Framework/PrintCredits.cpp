#include "PrintCredits.h"

void printCredits(int width, int height, int *currentX, int *currentY, double *timer, char map[600][150])
{
	//Prints the map info
	COORD c = g_Console.getConsoleSize();
	c.X = c.X / 2 - width;
	c.Y = c.Y - *currentX;
	string line = " ";


	//prints the fog if player choose to have this enhancement
	for (int row = 0; row <= (height * 2); row++)
	{
		if (c.Y < 50 && c.Y > 0)
		{
			line = map[row];
			g_Console.writeToBuffer(c, line);
		}	
		c.Y++;
	}

	if (g_dElapsedTime < *timer)
		return;

	*currentX += 1;
	*timer = g_dElapsedTime + 0.2f;
}