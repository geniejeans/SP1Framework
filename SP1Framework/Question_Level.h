#include <iostream>
#include "game.h"

using namespace std;

extern Console g_Console;
extern struct SGameChar g_sChar;
extern char map[50][150];
extern bool printFog;
extern bool toggleFog;

void qCheck();
void asnCheck();
void saveMap();
void loadQ(int qNum);
void Question_Asn(bool isTrue);
void Question_resolved();
void reprint_map(int width, int height);