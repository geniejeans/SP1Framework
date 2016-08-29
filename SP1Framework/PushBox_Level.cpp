#include "PushBox_Level.h"

void doorMapChanges_J()
{
	
	//Doors:
	if (map[6][106] == (char)254) //Door1 
	{                                          //If position with X is replaced with a box, the door will open.
		map[5][82] = ' ';
	}

	if (map[11][121] == (char)254) //Door2
	{
		map[24][96] = ' ';
	}

	if (map[21][86] == (char)254) //Door3
	{
		map[4][57] = ' ';
	}

	if (map[9][71] == (char)254) //Door4
	{
		map[14][80] = ' ';
	}

	if (map[14][22] == (char)254) //Door5
	{
		map[1][30] = ' ';
	}

	if (map[1][12] == (char)254) //Door6
	{
		map[5][12] = ' ';
	}

	if (map[11][18] == (char)254) //Door7
	{
		map[21][7] = ' ';
	}

	if (map[31][15] == (char)254) //Door8
	{
		map[34][29] = ' ';
	}
}