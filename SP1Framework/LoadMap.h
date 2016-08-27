#include <iostream>
#include <fstream> //Test for file opening
#include <string>
#include "game.h"
#include <sstream>

using namespace std;

//Cannot find a way to do this with array
extern struct teleporter portalPos[26];
extern bool boardUpdate;
extern string timing[10][2];
extern double totalTime;

void loadMap(int level, char MapArray[50][150], char FogArray[50][150]);