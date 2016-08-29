#include "Tutorial_Level.h"

void Final_Stage_HS()
{
	//orange section
	if (map[1][14] == (char)254) //Door1 
	{
		map[7][4] = ' ';
	}
	if (map[1][17] == '1') //Door2
	{
		map[7][14] = ' ';
	}
	if (map[6][39] == '1') //Door3
	{
		map[11][19] = ' ';
	}
	if (map[31][3] == '1' && map[31][8] == '0' && map[31][13] == '1') //Door3
	{
		map[33][16] = ' ';
	}
	//Yellow section
	if (map[21][22] == '1' && map[32][25] == (char)254)
	{
		map[23][11] = ' ';
	}
	if (map[11][38] == (char)254 && map[14][60] == '1')
	{
		map[14][64] = ' ';
	}
	//Green section
	if (map[22][48] == (char)254)
	{
		map[34][33] = ' ';
	}
	if (map[2][102] == '1' && map[2][116] == '0' && map[5][102] == '1' && map[5][116] == '0') // L portal
	{
		map[6][96] = ' ';
	}
	if (map[13][121] == (char)254) // M portal
	{
		map[13][96] = ' ';
	}
	//blue section
	if (map[4][71] == '1') //Q portal
	{
		map[6][71] = ' ';
	}
	if (map[4][77] == '1') //R portal
	{
		map[6][77] = ' ';
	}
	if (map[4][83] == '1') //S portal
	{
		map[6][83] = ' ';
	}
	if (map[4][89] == '1') //T portal
	{
		map[6][89] = ' ';
	}
	if (map[12][72] == '1' && map[12][88] == '1' && map[20][81] == '1')
	{
		map[20][71] = ' ';
	}
	//purple section
	if (map[32][76] == '1' && map[32][81] == '0' && map[32][86] == '1' && map[32][91] == '0' && map[32][96] == '1')
	{
		map[34][100] = ' ';
	}
	if (map[25][98] == (char)254)
	{
		map[25][103] = ' ';
	}
	// something
	if (map[1][17] == '0' && map[6][39] == '0' && map[31][3] == '0' && map[31][8] == '1' && map[31][13] == '0' && map[33][16] == ' ')
	{
		map[35][4] = ' ';
	}
}
