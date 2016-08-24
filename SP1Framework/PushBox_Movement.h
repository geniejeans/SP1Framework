#include <iostream>
#include "game.h"

using namespace std;

extern struct SGameChar g_sChar;
extern double  g_dElapsedTime;
extern double  g_dBounceTime;
extern unsigned int mapSizeWidth;
extern unsigned int mapSizeHeight;

void pushBoxMovement_J();