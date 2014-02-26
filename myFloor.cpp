#include "ExampleObject.h"
#include "myFloor.h"

ExampleObject cube2;

void myFloor::draw() 
{
	glPushMatrix();
	glTranslated(4.0, -0.05, 3.0);
	glScaled(8.0, 0.1, 6.0);
	cube2.draw();
	glPopMatrix();
}