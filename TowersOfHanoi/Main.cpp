// TowersOfHanoi.cpp : Defines the entry point for the console application.
// Dallas Johnson
// Computer will play a game of towers of hanoi and tell you the minimum number of moves to do it.
// May include a human playable version at the end of the calculation.

#include <iostream>
#include <cstdlib>
#include <string>
#include "Tower.h"

using namespace std;

//method prototypes: our header fucked everything up somehow;
bool moveDisk(Tower *&Tower1, Tower *&Tower2);

//End prototyping

class Tower;

int main(int argc, char* argv[])
{
	//Setting up the three tower pegs. Since there's only three we'll just use three variables for them to keep track easier of which one we're using
	Tower* LeftPeg = new Tower();
	LeftPeg->setName("Left Tower");
	Tower* MiddlePeg = new Tower();
	MiddlePeg->setName("Middle Tower");
	Tower* RightPeg = new Tower();
	RightPeg->setName("Right Tower");
	int diskCount = 3; //default our disk number to three unless otherwise specified.

	cout << "How many disks do you wish to start with? ";
	cin >> diskCount;

	for (int i = diskCount; i > 0; i--) {
		LeftPeg->Push(new disk(i)); //create the disks in descending order on the left peg.
	}
	//Print out our tower to see if they're adding properly.
	LeftPeg->print();
	MiddlePeg->print();
	RightPeg->print();

	//Try a disk move with one of our towers and see if they work.
	bool canMoveDisk;
	canMoveDisk = moveDisk(LeftPeg, RightPeg);
	canMoveDisk = moveDisk(LeftPeg, RightPeg);
	canMoveDisk = moveDisk(LeftPeg, MiddlePeg);
	canMoveDisk = moveDisk(RightPeg, MiddlePeg);
	//destruction of the towers
	delete LeftPeg;
	delete MiddlePeg;
	delete RightPeg;
	return 0;
}

bool moveDisk(Tower *&Tower1, Tower *&Tower2) {
	disk *towerPop = Tower1->Pop();
	Tower2->Push(towerPop);
	cout << "Move disk " << towerPop->getValue() << " from " << Tower1->getName() << " to " << Tower2->getName() << endl;
	if (!Tower2->getBottom()->isLarger()) {
		towerPop = Tower2->Pop();
		Tower1->Push(towerPop);
		cout << "Failed!" << endl;
		return false;
	}
	cout << "Success!" << endl;
	return true;
}
