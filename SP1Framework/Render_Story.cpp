#include "Render_Story.h"


extern bool  g_abKeyPressed[K_COUNT];
extern EGAMESTATES g_eGameState;
void renderStory()
{
	if (g_abKeyPressed[K_ESCAPE])
		g_bQuitGame = true;
	if (g_dBounceTime > g_dElapsedTime)
		return;
	if (g_abKeyPressed[K_TAB])
	{
		printStory++;
		g_dBounceTime = g_dElapsedTime + 0.125;
	}
	if (printStory == 0)
	{
		loadMap(8, map, mapFog); //Starting story
	}
	if (printStory == 1)
	{
		loadMap(9, map, mapFog); //Tutorial
	}
	if (printStory == 2)
	{
		g_eGameState = S_GAME_TUT;
		newMap = true;
		printStory = 3;

	}
	else if (*changeHealth != 0 && printStory > 2)
	{
		switch (refreshMap)
		{
		case 0:
			loadMap(10, map, mapFog); //levers 
			if (g_abKeyPressed[K_TAB])
			{
				printStory = 3;
				g_eGameState = S_GAME_1;
				newMap = true;
			}
			break;
		case 1:
			loadMap(11, map, mapFog); //questions
			if (g_abKeyPressed[K_TAB])
			{
				printStory = 4;
				g_eGameState = S_GAME_2;
				newMap = true;
			}
			break;
		case 2:
			loadMap(12, map, mapFog); //boxes 
			if (g_abKeyPressed[K_TAB])
			{
				printStory = 5;
				g_eGameState = S_GAME_3;
				newMap = true;
			}
			break;
		case 3:
			loadMap(13, map, mapFog); //teleporters
			if (g_abKeyPressed[K_TAB])
			{
				printStory = 6;
				g_eGameState = S_GAME_4;
				newMap = true;
			}
			break;
		case 4:
			loadMap(19, map, mapFog); //Final map 
			if (g_abKeyPressed[K_TAB])
			{
				printStory = 7;
				g_eGameState = S_GAME_5;
				newMap = true;
			}
			break;
		case 5:
			loadMap(14, map, mapFog); //success
			if (g_abKeyPressed[K_TAB])
			{
				g_eGameState = S_LEADERBOARD;
				newMap = true;
			}
			break;
		}
	}
	else if (*changeHealth == 0)
	{
		totalTime = 0.0;
		loadMap(15, map, mapFog); //fail
		if (g_abKeyPressed[K_TAB])
		{
			g_eGameState = S_MAIN_MENU;
			newMap = true;
		}
	}
	printMap(mapSizeWidth, mapSizeHeight, &timeToWait, false, false, &printHealth,false,mapFog, false, false);
}