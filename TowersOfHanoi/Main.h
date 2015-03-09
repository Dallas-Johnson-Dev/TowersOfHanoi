// Dallas Johnson
// Computer will play a game of towers of hanoi and tell you the minimum number of moves to do it.
// May include a human playable version at the end of the calculation.

#ifndef __HANOI__
#define __HANOI__

#include <iostream>
#include <cstdlib>
#include <string>
#include "Tower.h"

class Tower;
using namespace std;

int main(int argc, char* argv);
bool moveDisk(Tower *&Tower1, Tower *&Tower2);

#endif //__HANOI__
