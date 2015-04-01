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
	Tower* MiddlePeg = new Tower();
	Tower* RightPeg = new Tower();
	int diskCount = 3; //default our disk number to three unless otherwise specified.

	cout << "How many disks do you wish to start with? ";
	cin >> diskCount;

	for (int i = diskCount; i > 0; i--) {
		LeftPeg->Push(new disk(i)); //create the disks in descending order on the left peg.
	}
	//Print out our tower to see if they're adding properly. 

	//Try a disk move with one of our towers and see if they work.
	bool canMoveDisk;
	/*canMoveDisk = moveDisk(LeftPeg, RightPeg);
	canMoveDisk = moveDisk(LeftPeg, RightPeg);
	canMoveDisk = moveDisk(LeftPeg, MiddlePeg);
	canMoveDisk = moveDisk(RightPeg, MiddlePeg);*/

	//Do hanoi
	//We'll simulate the hanoi method here to see why this isnt' working.
	int movesDone = 0;
	if (diskCount % 2 == 1) {
		while (true) {
			//odd case here
			//The sequence this should follow is like this
			/*
			{Left, Right}
			{Left, Middle}
			{Middle, Right}
			*/
			moveDisk(LeftPeg, RightPeg, 1, 3);
			movesDone++;
			if (LeftPeg->isEmpty() && MiddlePeg->isEmpty()) break;
			moveDisk(LeftPeg, MiddlePeg, 1, 2);
			movesDone++;
			if (LeftPeg->isEmpty() && MiddlePeg->isEmpty()) break;
			moveDisk(MiddlePeg, RightPeg, 2, 3);
			movesDone++;
			if (LeftPeg->isEmpty() && MiddlePeg->isEmpty()) break;
		}
	}
	else {
		//even case here
		//The sequence this should follow is like this
		/*
		{Left, Middle}
		{Left, Right}
		{Middle, Right}
		*/
		while (true) {
			moveDisk(LeftPeg, MiddlePeg, 1, 2);
			movesDone++;
			if (LeftPeg->isEmpty() && MiddlePeg->isEmpty()) break;
			moveDisk(LeftPeg, RightPeg, 1, 3);
			movesDone++;
			if (LeftPeg->isEmpty() && MiddlePeg->isEmpty()) break;
			moveDisk(MiddlePeg, RightPeg, 2, 3);
			movesDone++;
			if (LeftPeg->isEmpty() && MiddlePeg->isEmpty()) break;
		}
	}

	cout << "Number of moves taken: " << movesDone << endl;

	//destruction of the towers
	delete LeftPeg;
	delete MiddlePeg;
	delete RightPeg;
	return 0;
}

void moveDisk(Tower *&Tower1, Tower *&Tower2, int first, int second) {
	//Re-write for bi-directionality
	disk * firstDisk = Tower1->Pop();
	disk * secondDisk = Tower2->Pop();
	if (!firstDisk) {
		Tower1->Push(secondDisk);
		cout << "Moved disk " << secondDisk->getValue() << " from tower " << second << " to tower " << first << endl;
		cout << "----------------+" << endl;
	}
	else if (!secondDisk) {
		Tower2->Push(firstDisk);
		cout << "Moved disk " << firstDisk->getValue() << " from tower " << first << " to tower " << second << endl;
		cout << "----------------+" << endl;
	}
	else if (!firstDisk && !secondDisk) {
		cout << "How did you manage to do this...?" << endl;
		exit(0);
	}
	else {
		if (firstDisk->getValue() < secondDisk->getValue()) {
			Tower2->Push(secondDisk);
			Tower2->Push(firstDisk);
			cout << "Moved disk " << firstDisk->getValue() << " from tower " << first << " to tower " << second << endl;
			cout << "----------------+" << endl;
		}
		else if (firstDisk->getValue() > secondDisk->getValue()) {
			Tower1->Push(firstDisk);
			Tower1->Push(secondDisk);
			cout << "Moved disk " << secondDisk->getValue() << " from tower " << second << " to tower " << first << endl;
			cout << "----------------+" << endl;
		}
	}
}

