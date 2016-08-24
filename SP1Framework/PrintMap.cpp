#include "PrintMap.h"

void printMap(int width, int height, bool *timer, bool isMainMenu, bool instructions, bool *health, bool enableFog, char(&FogArray)[50][150], bool options)
{
	double timeToWait = 1.0;

	//Prints the map info
	COORD c = g_Console.getConsoleSize();
	c.X = c.X / 2 - width;
	c.Y = c.Y / 2 - height;
	string line = " ";
	renderArea(height, width, FogArray);
	for (int row = 0; row <= (height*2); row++)
	{
		if (enableFog)
		{
			line = FogArray[row];
			g_Console.writeToBuffer(c, line);
			c.Y++;
		}
		else
		{
			line = map[row];
			g_Console.writeToBuffer(c, line);
			c.Y++;
		}
	}
	if (isMainMenu)
	{
		c.X += 44 - 10;
		c.Y++;
		if (menuPointer == 0)
		{
			g_Console.writeToBuffer(c, "-> Start Game!", 0x0A);
			c.Y++;
			g_Console.writeToBuffer(c, "Instructions!", 0x0A);
			c.Y++;
			g_Console.writeToBuffer(c, "Options!", 0x0A);
			c.Y++;
			g_Console.writeToBuffer(c, "Quit Game!", 0x0C);
		}
		else if (menuPointer == 1)
		{
			g_Console.writeToBuffer(c, "Start Game!", 0x0A);
			c.Y++;
			g_Console.writeToBuffer(c, "-> Instructions!", 0x0A);
			c.Y++;
			g_Console.writeToBuffer(c, "Options!", 0x0A);
			c.Y++;
			g_Console.writeToBuffer(c, "Quit Game!", 0x0C);
		}
		else if (menuPointer == 2)
		{
			g_Console.writeToBuffer(c, "Start Game!", 0x0A);
			c.Y++;
			g_Console.writeToBuffer(c, "Instructions!", 0x0A);
			c.Y++;
			g_Console.writeToBuffer(c, "-> Options!", 0x0A);
			c.Y++;
			g_Console.writeToBuffer(c, "Quit Game!", 0x0C);
		}
		else if (menuPointer == 3)
		{
			g_Console.writeToBuffer(c, "Start Game!", 0x0A);
			c.Y++;
			g_Console.writeToBuffer(c, "Instructions!", 0x0A);
			c.Y++;
			g_Console.writeToBuffer(c, "Options!", 0x0A);
			c.Y++;
			g_Console.writeToBuffer(c, "-> Quit Game!", 0x0C);
		}
		
	}
	if (instructions)
	{
		c.X += width - 9;
		c.Y++;
		g_Console.writeToBuffer(c, "Escape to go back!", 0x0A);
	}
	if (options)
	{
		c.X += 44 - 10;
		c.Y++;
		if (optionPointer == 0)
		{
			g_Console.writeToBuffer(c, "-> Fog: ON", 0x0A);
			c.Y++;
			g_Console.writeToBuffer(c, "Fog: OFF", 0x0A);
		}
		else if (optionPointer == 1)
		{
			g_Console.writeToBuffer(c, "Fog: ON", 0x0A);
			c.Y++;
			g_Console.writeToBuffer(c, "-> Fog: OFF", 0x0A);
		}

	}
	if (*timer == true)
	{
		if (timeRemaining > 0)
		{
			c.X += width - 17;
			c.Y++;
			g_Console.writeToBuffer(c, "You only have " + to_string(timeRemaining) + " seconds remaining");
		}
		else
		{
			c.X += width - 4;
			c.Y++;
			g_Console.writeToBuffer(c, "OVERTIME", 0x0C);
		}
		
	}
	if (*health == true)
	{
		if (*timer == true)
		{
			if (timeRemaining > 0)
			{
				c.X += width + 5;
				c.Y -= 37;
			}
			else
			{
				c.X += width - 8;
				c.Y -= 37;
			}
		}
		else
		{
			c.X += width + 50;
			c.Y -= 38;
		}
		if (*changeHealth != 0)
		{
			for (int i = *changeHealth; i > 0; i--)
			{
				g_Console.writeToBuffer(c, (char)3, 0x0C); //Red color hearts
				c.X += 2;
			}
		}

	}

}

void deleteMap(int width, int height) //Activates at level Teleporter only
{
	for (int row = (height * 2)-1; row >= 0; row--)
	{
		for (int col = (width * 2)-1; col >= 0; col--)
		{
			if (map[row][col] != (char)255)
			{
				map[row][col] = (char)255;
				mapFog[row][col] = (char)255;
				break;
			}
		}
	}
}

void renderArea(int height, int width, char(&FogArray)[50][150])
{
	bool cornerwalls = false;
	float walls = 0.0f;
	bool wall = false;
	bool walltemp = false;
	int playerX = (g_sChar.m_cLocation.X) - (90 - width);
	int playerY = (g_sChar.m_cLocation.Y) - (25 - height);
	/*for (int row = playerY - 3; row <= playerY + 3; row++)
	{
		for (int col = playerX - 3; col <= playerX + 3; col++)
		{
			FogArray[row][col] = map[row][col];
		}
	}*/

	for (int row = playerY; row >= playerY - 3; row--) //North ^
	{
		
		for (int col = playerX - ceil(walls / 2.0f); col <= playerX + ceil(walls / 2.0f); col++)
		{
			if (map[row][playerX] == ' ')
			{
				FogArray[row][playerX - 1] = map[row][playerX - 1];
				FogArray[row][playerX + 1] = map[row][playerX + 1];
			}
			else
			{
				if (map[row + 1][playerX - 1] == (char)219 && col == playerX - ceil(walls / 2.0f))
					continue;
				if (map[row + 1][playerX + 1] == (char)219 && col == playerX + ceil(walls / 2.0f))
					continue;
				else
					FogArray[row][col] = map[row][col];
			}
			if (map[row][playerX] == (char)219)
				wall = true;
		}
		if (wall)
			break;
		walls++;
	}
	wall = false;
	walls = 0;

	for (int row = playerY; row <= playerY + 3; row++) //South v
	{
		for (int col = playerX - ceil(walls / 2.0f); col <= playerX + ceil(walls / 2.0f); col++)
		{

			if (map[row][playerX] == ' ')
			{
				FogArray[row][playerX - 1] = map[row][playerX - 1];
				FogArray[row][playerX + 1] = map[row][playerX + 1];
			}
			else
			{
				if (map[row - 1][playerX - 1] == (char)219 && col == playerX - ceil(walls / 2.0f))
					continue;
				if (map[row - 1][playerX + 1] == (char)219 && col == playerX + ceil(walls / 2.0f))
					continue;
				else
					FogArray[row][col] = map[row][col];
			}
			if (map[row][playerX] == (char)219)
				wall = true;
		}
		if (wall)
			break;
		walls++;
	}
	wall = false;
	walls = 0;

	for (int row = playerX; row <= playerX + 5; row++) //East >
	{
		if (walls > 3) // Limit each sides to be 1.5 ceil == 2 so 2 on either sides from player (for fov)
			walls = 3;
		for (int col = playerY - ceil(walls / 2.0f); col <= playerY + ceil(walls / 2.0f); col++)
		{
			if (map[playerY][row] == ' ') //Reduce range fov in corridors
			{
				FogArray[playerY - 1][row] = map[playerY-1][row];
				FogArray[playerY][row] = map[playerY][row];
				FogArray[playerY + 1][row] = map[playerY + 1][row];
			}
			else
			{
				if (map[playerY - 1][row - 1] == (char)219 && col == playerY - ceil(walls / 2.0f))
					continue;
				else if (map[playerY + 1][row - 1] == (char)219 && col == playerY + ceil(walls / 2.0f))
					continue;
				else
					FogArray[col][row] = map[col][row];
			}
			if (map[playerY][row] == (char)219 || map[playerY][row] == (char)186)
				wall = true;
		}
		if (wall)
			break;
		walls++;
	}
	wall = false;
	walls = 0;

	for (int row = playerX; row >= playerX - 5; row--) //West <
	{
		if (walls > 3) // Limit each sides to be 1.5 ceil == 2 so 2 on either sides from player (for fov)
			walls = 3;
		for (int col = playerY - ceil(walls / 2.0f); col <= playerY + ceil(walls / 2.0f); col++)
		{
			if (map[playerY][row] == ' ')
			{
				FogArray[playerY - 1][row] = map[playerY - 1][row];
				FogArray[playerY][row] = map[playerY][row];
				FogArray[playerY + 1][row] = map[playerY + 1][row];
			}
			else
			{
				if (map[playerY - 1][row + 1] == (char)219 && col == playerY - ceil(walls / 2.0f))
					continue;
				else if (map[playerY + 1][row + 1] == (char)219 && col == playerY + ceil(walls / 2.0f))
					continue;
				else
					FogArray[col][row] = map[col][row];
			}
			if (map[playerY][row] == (char)219 || map[playerY][row] == (char)186)
				wall = true;
		}
		if (wall)
			break;
		walls++;
	}
	wall = false;
	walls = 0;
}