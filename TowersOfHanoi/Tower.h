#include <iostream>
#include <cstdlib>
#include <string>
#include "Disk.h"

using namespace std;

class disk;

class Tower {
private:
	disk* bottom;
	string name = "";
	disk* returnDisk; //again, the temporary variable that we need in order for the method to function properly.
public:
	Tower();
	~Tower();
	void Push(disk* disk);
	disk* Pop();
	bool isEmpty();
	disk* getTop();
	void print();
	disk* getBottom();
	string getName();
	void setName(string newName);
};

Tower::Tower() {
	bottom = NULL;
}

Tower::~Tower() {
	delete bottom;
}

void Tower::Push(disk* disk) {
	if (!bottom) {
		bottom = disk;
	}
	else {
		bottom->pushDisk(disk);
	}
}

disk* Tower::Pop() {
	if (!bottom) {
		return NULL;
	}
	else if (!bottom->getNext()) {
		returnDisk = bottom;
		bottom = NULL;
		return returnDisk;
	}
	else {
		returnDisk = bottom->popDisk();
		return returnDisk;
	}
}

bool Tower::isEmpty() {
	return bottom == NULL;
}

void Tower::print() {
	if (bottom) {
		cout << "Current Stack on Tower: " << endl;
		bottom->print();
	}
}

disk* Tower::getTop() {
	return bottom->FindTopDisk();
}

disk* Tower::getBottom() {
	return bottom;
}

string Tower::getName() {
	return name;
}

void Tower::setName(string newName) {
	name = newName;
}
