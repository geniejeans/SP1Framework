#include "Tutorial_Level.h"
extern int tutdoor; 
void Tutorial_Level_HS()
{

	if (map[2][19] == (char)49 && map[8][19] == (char)49 && tutdoor == 0) //Door1 
	{
		map[5][22] = ' ';
		tutdoor = 1;
	}
	if (map[5][75] == (char)254) //Door2
	{
		map[5][81] = ' ';

	}
}
