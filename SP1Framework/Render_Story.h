#include <iostream>
#include "game.h"
using namespace std;

extern struct SGameChar g_sChar;
extern double  g_dElapsedTime;
extern double  g_dBounceTime;
extern unsigned int mapSizeWidth;
extern unsigned int mapSizeHeight;
extern bool newMap;
extern int refreshMap;
extern bool timeToWait;
extern bool printHealth;
extern int printStory;
extern char mapFog[50][150];
extern char map[50][150];

void renderStory();