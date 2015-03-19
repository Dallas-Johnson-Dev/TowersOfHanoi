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
	disk(int value);
	~disk();
	disk* getNext();
	int getValue();
	bool isLarger();
	void pushDisk(disk* disk);
	void setNext(disk* disk);
	disk* popDisk();
	void print();
	disk* FindTopDisk();
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

void disk::setNext(disk* disk) {
	next = disk;
}

int disk::getValue() {
	return sizeValue;
}

bool disk::isLarger() {
	if (!next) {
		return true;
	}
	else {
		tempNext = next;
		if (!tempNext->getNext()) {//Check two disks ahead to make sure that we dont' have to iterate the list.
			return sizeValue > tempNext->getValue();
		}
		while (tempNext->getNext()) {//Iterate if we must
			if (!tempNext->getNext()->getNext()) {
				break;
			}
			tempNext = tempNext->getNext();
		}
		return tempNext->getValue() > tempNext->getNext()->getValue();
	}
}

void disk::pushDisk(disk* disk) {//Since this must all be done with loops, we'll have to simulate recursion.
	if (!next) {
		next = disk;
		return;
	}
	tempNext = next;
	while (tempNext->getNext()) {
		tempNext = tempNext->getNext();
	}
	tempNext->setNext(disk);
	//tempNext = NULL;//since we really don't care at this point about the temp next in this node, we can just de-initialize it.
}

disk* disk::popDisk() {
	tempNext = next;
	if (!tempNext->getNext())
	{
		returnNext = next;
		next = NULL;
		return returnNext;
	}
	while (tempNext->getNext()) {
		if (!tempNext->getNext()->getNext()) { //this condition is in case something happens where we don't have another next after this.
			break;
		}
		tempNext = tempNext->getNext();
	}
	//D->D->D->D->NULL
	//We need  ^ one here as our return, so we stay two behind to find the one ahead, fi that makes sense.
	returnNext = tempNext->getNext();
	tempNext->setNext(NULL);
	tempNext = NULL;
	return returnNext;
}

void disk::print() {
	cout << "Disk " << sizeValue << endl;
	if (!next) {
		return;
	}
	else {
		tempNext = next;
	}
	while (tempNext) {
		cout << "Disk " << tempNext->getValue() << endl;
		tempNext = tempNext->getNext();
	}
}

disk* disk::FindTopDisk() {
	if (!next) {
		return this;
	}
	tempNext = next;
	while (tempNext) {
		if (!tempNext->getNext()) {
			break;
		}
		tempNext = tempNext->getNext();
	}
	returnNext = tempNext;
	tempNext = NULL;
	return returnNext;
}
#endif
