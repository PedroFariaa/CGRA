#ifndef MY_CLOCK_HAND
#define MY_CLOCK_HAND

#include "CGF/CGFobject.h"
#include "myCylinder.h"

class myClockHand:public CGFobject {
private:
	float angle;
	float lenght;
public: 
	myClockHand(float newAngle, float newLenght);
	void draw(); 
	void setAngle(float newAngle);
	float getAngle();
};

#endif