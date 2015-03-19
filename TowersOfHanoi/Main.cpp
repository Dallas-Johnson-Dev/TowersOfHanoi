// TowersOfHanoi.cpp : Defines the entry point for the console application.
// Dallas Johnson
// Computer will play a game of towers of hanoi and tell you the minimum number of moves to do it.
// May include a human playable version at the end of the calculation.

#include <iostream>
#include <cstdlib>
#include <string>
#include "Tower.h"
#include "Main.h"

using namespace std;

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
	/*canMoveDisk = moveDisk(LeftPeg, RightPeg);
	canMoveDisk = moveDisk(LeftPeg, RightPeg);
	canMoveDisk = moveDisk(LeftPeg, MiddlePeg);
	canMoveDisk = moveDisk(RightPeg, MiddlePeg);*/

	//Do hanoi
	//We'll simulate the hanoi method here to see why this isnt' working.

	if (diskCount % 2 == 1) {
		//odd case here
		canMoveDisk = moveDisk(LeftPeg, RightPeg);
		canMoveDisk = moveDisk(LeftPeg, MiddlePeg);
		canMoveDisk = moveDisk(MiddlePeg, RightPeg);
	}
	else {

	}

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

//The algorithm for doing the towers of hanoi is as follows
//Odd: 1-3, 1-2, 2-3, repeat.
//Even: 1-3, 2-3, 1-2, repeat (I think)
//We may need to also make something bi-directional, which I may figure out as I do this.
//Also the parameters are a horrible way to do this but it's more for checking sooo....

void hanoi(int count, Tower *&Tower1, Tower *&Tower2, Tower *&Tower3) {
	//First we check if the disk count on the first tower is even or odd, we'll get this with the diskcount parameter up top.
	bool canMoveDisk;
	if (count % 2 == 1) {
		while (!Tower1->isEmpty() && !Tower2->isEmpty()) {
			//Since this is automatic, we'll let the game do this and assume it won't make any mistakes.
			canMoveDisk = moveDisk(Tower1, Tower3);
			canMoveDisk = moveDisk(Tower1, Tower2);
			canMoveDisk = moveDisk(Tower2, Tower3);
		}
	}
	else {
		//handle the even case here
		cout << "Hold up, we're not here yet." << endl;
	}
}
