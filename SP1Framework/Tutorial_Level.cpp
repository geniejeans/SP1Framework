#include "Tutorial_Level.h"

void Tutorial_Level_HS()
{
	if (map[2][20] == (char)49 && map[8][20] == (char)49) //Door1 
	{
		map[5][22] = ' ';
	}
	if (map[5][75] == (char)254) //Door1 
	{
		map[5][81] = ' ';
		map[5][82] = ' ';
		map[5][76] = ' ';
	}
}
