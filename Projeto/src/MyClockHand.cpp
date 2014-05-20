#include "MyClockHand.h"
#include <cmath>

myClockHand::myClockHand(float newAngle, float newLenght){
	this->angle=newAngle; 
	this->lenght=newLenght; 
}

float myClockHand::getAngle(){
	return this->angle;
}

void myClockHand::draw(){ 
	glPushMatrix();

	glRotated(angle, 0, 0,1); 
	glBegin(GL_TRIANGLES);
	glNormal3f(0.0,0.0, 1.0); 
	glVertex3d(0.01, 0, 0); 
	glVertex3d(0,this->lenght*0.8,0);
	glVertex3d(-0.01, 0,0);
	glEnd();
	glPopMatrix();
}

void myClockHand::setAngle(float newAngle){
	this->angle=newAngle;
}