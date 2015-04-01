// Dallas Johnson
// Computer will play a game of towers of hanoi and tell you the minimum number of moves to do it.
// May include a human playable version at the end of the calculation.

#ifndef __DISK__
#define __DISK__
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class disk {
private:
	disk* next;
	int sizeValue;
	//These will never be accessed ever outside of the methods that need them. These are so that the pop and push methods will work properly.
	disk* tempNext;
	disk* returnNext;
public:
	disk(int value); //Our constructor
	~disk(); //Our destructor
	disk* getNext(); //Gets the next disk after this one
	int getValue(); //Returns the value of the current disk
	void setNext(disk* nextDisk); //set's the next value of the current disk
};

disk::disk(int value) {
	sizeValue = value;
	next = NULL;
}

disk::~disk() {
	delete next;
}

disk* disk::getNext() {
	return next;
}

void disk::setNext(disk* nextDisk) {
	next = nextDisk;
}

int disk::getValue() {
	return sizeValue;
}

#endif
