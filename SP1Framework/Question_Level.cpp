#include "Question_Level.h"

// temporarily store map
char currentMap[50][150];
// temporarily store character location
short charLoX;
short charLoY;

// Unlock number keys
bool check = false;
// Check Question Number
int checkq = 0;
// Check map player is in
int checkm = 0;

//map size
unsigned int mwidth = 126 / 2;
unsigned int mheight = 36 / 2;
// usage of keys
extern bool g_abKeyPressed[K_COUNT];

//fog
char currentFog[50][150];

void qCheck()
{
	if (map[(g_sChar.m_cLocation.Y) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X) - (90 - mapSizeWidth)] == (char)63)
	{
		saveMap();
		if (checkm == 0)
		{
			if ((g_sChar.m_cLocation.Y) - (25 - mapSizeHeight) == 5 && (g_sChar.m_cLocation.X) - (90 - mapSizeWidth) == 42)
			{
				clearScreen();
				loadQ(0);
				checkq = 99;
				check = true;
			}
		}
		if (checkm == 2)
		{
			if ((g_sChar.m_cLocation.Y) - (25 - mapSizeHeight) == 16 && (g_sChar.m_cLocation.X) - (90 - mapSizeWidth) == 32)
			{
				clearScreen();
				loadQ(1);
				checkq = 1;//indicate which question has been loaded
				check = true;//indicate that a question has been loaded
			}
			if ((g_sChar.m_cLocation.Y) - (25 - mapSizeHeight) == 33 && (g_sChar.m_cLocation.X) - (90 - mapSizeWidth) == 42)
			{
				clearScreen();
				loadQ(2);
				checkq = 2;
				check = true;
			}
			if ((g_sChar.m_cLocation.Y) - (25 - mapSizeHeight) == 23 && (g_sChar.m_cLocation.X) - (90 - mapSizeWidth) == 75)
			{
				clearScreen();
				loadQ(3);
				checkq = 3;
				check = true;
			}
			if ((g_sChar.m_cLocation.Y) - (25 - mapSizeHeight) == 10 && (g_sChar.m_cLocation.X) - (90 - mapSizeWidth) == 14)
			{
				clearScreen();
				loadQ(4);
				checkq = 4;
				check = true;
			}
			if ((g_sChar.m_cLocation.Y) - (25 - mapSizeHeight) == 20 && (g_sChar.m_cLocation.X) - (90 - mapSizeWidth) == 104)
			{
				clearScreen();
				loadQ(5);
				checkq = 5;
				check = true;
			}
			if ((g_sChar.m_cLocation.Y) - (25 - mapSizeHeight) == 1 && (g_sChar.m_cLocation.X) - (90 - mapSizeWidth) == 117)
			{
				clearScreen();
				loadQ(6);
				checkq = 6;
				check = true;
			}
			if ((g_sChar.m_cLocation.Y) - (25 - mapSizeHeight) == 33 && (g_sChar.m_cLocation.X) - (90 - mapSizeWidth) == 113)
			{
				clearScreen();
				loadQ(7);
				checkq = 7;
				check = true;
			}
			if ((g_sChar.m_cLocation.Y) - (25 - mapSizeHeight) == 17 && (g_sChar.m_cLocation.X) - (90 - mapSizeWidth) == 109)
			{
				clearScreen();
				loadQ(8);
				checkq = 8;
				check = true;
			}
			if ((g_sChar.m_cLocation.Y) - (25 - mapSizeHeight) == 19 && (g_sChar.m_cLocation.X) - (90 - mapSizeWidth) == 109)
			{
				clearScreen();
				loadQ(9);
				checkq = 9;
				check = true;
			}
			if ((g_sChar.m_cLocation.Y) - (25 - mapSizeHeight) == 21 && (g_sChar.m_cLocation.X) - (90 - mapSizeWidth) == 109)
			{
				clearScreen();
				loadQ(10);
				checkq = 10;
				check = true;
			}
			if ((g_sChar.m_cLocation.Y) - (25 - mapSizeHeight) == 23 && (g_sChar.m_cLocation.X) - (90 - mapSizeWidth) == 109)
			{
				clearScreen();
				loadQ(11);
				checkq = 11;
				check = true;
			}
		}
	}
}

void asnCheck()
{
	if (check)//see if a question had already loaded
	{
		if (g_abKeyPressed[K_D1])
		{
			if (checkq == 5 || checkq == 7 || checkq == 99)
			{
				Question_Asn(true);
				check = false;
				checkq = 0;
			}
			else
			{
				*changeHealth -= 1;
				Sleep(250);
			}
		}
		if (g_abKeyPressed[K_D2])
		{
			if (checkq == 3 || checkq == 8)
			{
				Question_Asn(true);
				check = false;
				checkq = 0;
			}
			else
			{
				*changeHealth -= 1;
				Sleep(250);
			}
		}
		if (g_abKeyPressed[K_D3])
		{
			if (checkq == 1 || checkq == 6 || checkq == 11)
			{
				Question_Asn(true);
				check = false;
				checkq = 0;
			}
			else
			{
				*changeHealth -= 1;
				Sleep(250);
			}
		}
		if (g_abKeyPressed[K_D4])
		{
			if (checkq == 2 || checkq == 4 || checkq == 9 || checkq == 10)
			{
				Question_Asn(true);
				check = false;
				checkq = 0;
			}
			else
			{
				*changeHealth -= 1;
				Sleep(250);
			}
		}
		if (*changeHealth == 0)
		{
			resetLevel();
		}
	}
}

void saveMap() // save the current state of the map
{
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 150; j++)
		{
			currentMap[i][j] = map[i][j];//find and save current map to array
			currentFog[i][j] = mapFog[i][j];//find and save current map to array
		}
	}

	charLoX = g_sChar.m_cLocation.X;// saves the character's location
	charLoY = g_sChar.m_cLocation.Y;
}

void loadQ(int qNum)
{
	string mapname = " ";
	printFog = false;
	switch (qNum)
	{
	case 0:
		mapname = "Maps_Text/Q0.txt";
		break;
	case 1:
		mapname = "Maps_Text/Q1.txt";
		break;
	case 2:
		mapname = "Maps_Text/Q2.txt";
		break;
	case 3:
		mapname = "Maps_Text/Q3.txt";
		break;
	case 4:
		mapname = "Maps_Text/Q4.txt";
		break;
	case 5:
		mapname = "Maps_Text/Q5.txt";
		break;
	case 6:
		mapname = "Maps_Text/Q6.txt";
		break;
	case 7:
		mapname = "Maps_Text/Q7.txt";
		break;
	case 8:
		mapname = "Maps_Text/Q8.txt";
		break;
	case 9:
		mapname = "Maps_Text/Q9.txt";
		break;
	case 10:
		mapname = "Maps_Text/Q10.txt";
		break;
	case 11:
		mapname = "Maps_Text/Q11.txt";
		break;
	}

	//Function use to store data from text file to 2d array
	string line = " ";
	//clear 2d array
	memset(map, '\0', sizeof(map[0][0]) * 50 * 150);

	//store to array
	ifstream myfile(mapname);
	int row = 0;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			for (unsigned int i = 0; i <= line.length(); i++)
			{
				map[row][i] = line[i];
			}
			row++;
		}
		myfile.close();
	}
	else
	{
		cout << "file cannot be opened" << endl;
	}
}

void Question_Asn(bool isTrue) //what happens if a question is answered correctly
{
	if (isTrue)
	{
		clearScreen();
		for (int i = 0; i < 50; i++)
		{
			for (int j = 0; j < 150; j++)
			{
				map[i][j] = currentMap[i][j];
				mapFog[i][j] = currentFog[i][j];//find and save current map to array
			}
		}

		//reprint_map(mwidth, mheight);

		g_sChar.m_cLocation.X = charLoX;
		g_sChar.m_cLocation.Y = charLoY;
		renderCharacter();
		Question_resolved();
	}
}

void Question_resolved() //deleting doors, ? marks, and resetting the temporary fields
{
	if (map[(g_sChar.m_cLocation.Y) - (25 - mheight)][(g_sChar.m_cLocation.X + 1) - (90 - mwidth)] == (char)186)
	{
		map[(g_sChar.m_cLocation.Y) - (25 - mheight)][(g_sChar.m_cLocation.X + 1) - (90 - mwidth)] = (char)32;
	}
	if (map[(g_sChar.m_cLocation.Y) - (25 - mheight)][(g_sChar.m_cLocation.X - 1) - (90 - mwidth)] == (char)186)
	{
		map[(g_sChar.m_cLocation.Y) - (25 - mheight)][(g_sChar.m_cLocation.X - 1) - (90 - mwidth)] = (char)32;
	}
	if (map[(g_sChar.m_cLocation.Y + 1) - (25 - mheight)][(g_sChar.m_cLocation.X) - (90 - mwidth)] == (char)186)
	{
		map[(g_sChar.m_cLocation.Y + 1) - (25 - mheight)][(g_sChar.m_cLocation.X) - (90 - mwidth)] = (char)32;
	}
	if (map[(g_sChar.m_cLocation.Y - 1) - (25 - mheight)][(g_sChar.m_cLocation.X) - (90 - mwidth)] == (char)186)
	{
		map[(g_sChar.m_cLocation.Y - 1) - (25 - mheight)][(g_sChar.m_cLocation.X) - (90 - mwidth)] = (char)32;
	}
	if (map[(g_sChar.m_cLocation.Y) - (25 - mheight)][(g_sChar.m_cLocation.X) - (90 - mwidth)] == (char)63)
	{
		map[(g_sChar.m_cLocation.Y) - (25 - mheight)][(g_sChar.m_cLocation.X) - (90 - mwidth)] = (char)32;
	}
	if (map[5][42] = (char)63)
	{
		map[5][42] = ' ';
	}
	if (map[5][43] = (char)186)
	{
		map[5][43] = ' ';
	}
	memset(currentMap, '\0', sizeof(currentMap[0][0]) * 50 * 150);;//clean up
	charLoX = 0;
	charLoY = 0;
	printFog = toggleFog;
}

//void reprint_map(int width, int height) // reprint the map back in its original state
//{
//	COORD c = g_Console.getConsoleSize();
//	c.X = c.X / 2 - width;
//	c.Y = c.Y / 2 - height;
//	string line = " ";
//	for (int row = 0; row <= (height * 2); row++)
//	{
//		line = map[row];
//		g_Console.writeToBuffer(c, line);
//		c.Y++;
//	}
//}