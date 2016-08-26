#include <iostream>
#include "Framework\console.h"
#include <time.h>
#include "game.h"
#include <sstream>
#include <vector>
//template <size_t size_x, size_t size_y>
using namespace std;

extern Console g_Console;
extern char map[50][150];
extern int timeRemaining;
extern int *changeHealth;
extern struct SGameChar  g_sChar;
extern int menuPointer;
extern int optionPointer;
extern struct SGameChar g_sChar;
extern string timing[10][2];
extern double totalTime;
 

void printMap(int width, int height, bool *timer, bool isMainMenu, bool instructions, bool *health, bool enableFog, char FogArray[50][150], bool options, bool leaderboard);
void deleteMap(int width, int height);
void renderArea(int width, int height, char FogArray[50][150]);