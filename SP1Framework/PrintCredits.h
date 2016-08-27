#include <iostream>
#include "Framework\console.h"
#include <time.h>
#include "game.h"
#include <sstream>
#include <vector>
//template <size_t size_x, size_t size_y>
using namespace std;

//Must extern this only
extern Console g_Console;
//Dont extern here other than g_Console

//extern char map[50][150];

void printCredits(int width, int height, int *currentX, int *currentY, double *timer, char map[600][150]);