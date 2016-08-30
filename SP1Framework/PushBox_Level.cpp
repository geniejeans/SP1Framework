#include "PushBox_Level.h"

extern int door; //Enabling that the if statements only run once
void doorMapChanges_J()
{
	//Doors:
	if (map[6][106] == (char)254 && door == 0) //Door1 
	{                                          //If position with X is replaced with a box, the door will open.
		map[5][82] = ' ';
		door = 1;
	}

	if (map[11][121] == (char)254 && door == 1) //Door2
	{
		map[24][96] = ' ';
		door = 2;
	}

	if (map[21][86] == (char)254 && door == 2) //Door3
	{
		map[4][57] = ' ';
		door = 3;
	}

	if (map[9][71] == (char)254 && door == 3) //Door4
	{
		map[14][80] = ' ';
		door = 4;
	}

	if (map[14][22] == (char)254 && door == 4) //Door5
	{
		map[1][30] = ' ';
		door = 5;
	}

	if (map[1][12] == (char)254 && door == 5) //Door6
	{
		map[5][12] = ' ';
		door = 6;
	}

	if (map[11][18] == (char)254 && door == 6) //Door7
	{
		map[21][7] = ' ';
		door = 7;
	}

	if (map[31][15] == (char)254 && door == 7) //Door8
	{
		map[34][29] = ' ';
		door = 8;
	}

	if (map[1][121] == (char)254 && door == 8) //secret
	{
		map[2][122] = ' ';
		map[2][123] = ' ';
		door = 9;
	}
}