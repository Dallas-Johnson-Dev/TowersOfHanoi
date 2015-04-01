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

int main(int argc, char* argv[]); //Where everything happens, all calculations and algorithms are run here. The main file has only one method and it's for moving the disks back and forth.
void moveDisk(Tower *&Tower1, Tower *&Tower2, int first, int second); // A bi-directional moving method where you can move one disk from one tower and vice versa by checking the size of one disk's value against another.

#endif //__HANOI__
