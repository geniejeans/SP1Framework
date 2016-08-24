#include <iostream>
#include <fstream> //Test for file opening
#include <string>
#include "game.h"

using namespace std;

extern char map[50][150];
extern char mapFog[50][150];
extern int checkm;

extern struct teleporter portalPos[26];

void loadMap(int level);