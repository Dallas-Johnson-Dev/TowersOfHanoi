// Dallas Johnson
// Computer will play a game of towers of hanoi and tell you the minimum number of moves to do it.
// May include a human playable version at the end of the calculation.

#ifndef __HANOITOWER__
#define __HANOITOWER__

#include <iostream>
#include <cstdlib>
#include <string>
#include "Tower.h"

using namespace std;

class Tower;

int main(int argc, char* argv[]);
bool moveDisk(Tower *&Tower1, Tower *&Tower2);
void hanoi(int count, Tower *&Tower1, Tower *&Tower2, Tower *&Tower3);

#endif //__HANOI__

