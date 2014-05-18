#ifndef MY_CLOCK
#define MY_CLOCK

#include "CGF/CGFobject.h"
#include "myCylinder.h"

class myClock : public CGFobject {
private:
	myCylinder* cyl;

public:
	myClock();
	void draw();
};



#endif