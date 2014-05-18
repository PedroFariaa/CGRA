#include "MyClock.h"

myClock::myClock(){
	myCylinder* cylinder = new myCylinder(12, 1, true);
	this->cyl=cylinder;
}

void myClock::draw(){
	cyl->draw();
}