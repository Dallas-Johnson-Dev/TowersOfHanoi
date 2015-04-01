// Dallas Johnson
// Computer will play a game of towers of hanoi and tell you the minimum number of moves to do it.
// May include a human playable version at the end of the calculation.

#ifndef __TOWER__
#define __TOWER__
#include <iostream>
#include <cstdlib>
#include <string>
#include "Disk.h"

using namespace std;

class disk;

class Tower {
private:
	disk* top;
	disk* returnDisk; //again, the temporary variable that we need in order for the method to function properly.
public:
	Tower(); //Our constructor
	~Tower(); //Our destructor
	void Push(disk* newDisk); //Pushes a disk onto the stack downward. The lowest value of the stack should be at the top due to this being towers of Hanoi, but really will add anything in top-down fashion.
	disk* Pop(); //Pops the disk off of the stack. This is far simpler than the Push method, but basically takes the top of the stack off and returns it as a disk object.
	bool isEmpty(); //Boolean that checks for if the top of the stack is NULL (empty)
	disk* getTop(); //Returns the head (top) of the stack.
};

Tower::Tower() {
	top = NULL;
}

Tower::~Tower() {
	delete top;
}

void Tower::Push(disk* newDisk) {
	disk* temp = top;
	top = newDisk;
	top->setNext(temp);
}

disk* Tower::Pop() {
	if (!top) return NULL;
	disk* returnDisk = top;
	top = top->getNext();
	return returnDisk;
}

bool Tower::isEmpty() {
	return top == NULL;
}

disk* Tower::getTop() {
	return top;
}

#endif //__TOWER__
