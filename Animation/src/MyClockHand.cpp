#include "MyClockHand.h"
#include <cmath>

#define pi acos(-1.0)

myClockHand::myClockHand(float newAngle, float newLenght){
	this->angle=newAngle;
	this->lenght=newLenght;
}

void myClockHand::draw(){
	glPushMatrix();
	glNormal3f(0.0,0.0, 1.0);   
		glBegin(GL_TRIANGLES);
			glVertex3d(this->lenght*cos(2*pi-((2*pi*this->angle)/360)), this->lenght*sin(2*pi-((2*pi*this->angle)/360)), 1);
			glVertex3d(0.5, 0, 1);
			glVertex3d(0, this->lenght, 1);
		glEnd();
	glPopMatrix();
}

void myClockHand::setAngle(float newAngle){
	this->angle=newAngle;
}