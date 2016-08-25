#include <iostream>
#include <fstream> //Test for file opening
#include <string>
#include "game.h"

using namespace std;

//Cannot find a way to do this
extern struct teleporter portalPos[26];

void loadMap(int level, char MapArray[50][150], char  FogArray[50][150]);