#include "myChair.h"
#include "ExampleObject.h"

ExampleObject cube3;

void myChair::draw() {

	//pernas
	glPushMatrix();
	glTranslated(0.9, 0.75, -0.9);
	glScaled(0.2, 1.5, 0.2);
	cube3.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.9, 0.75, 0.9);
	glScaled(0.2, 1.5, 0.2);
	cube3.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.9, 0.75, -0.9);
	glScaled(0.2, 1.5, 0.2);
	cube3.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.9, 0.75, 0.9);
	glScaled(0.2, 1.5, 0.2);
	cube3.draw();
	glPopMatrix();

	//tampo
	glPushMatrix();
	glTranslated(0.0, 1.6, 0.0);
	glScaled(2.0, 0.2, 2.0);
	cube3.draw();
	glPopMatrix();

	//encosto
	glPushMatrix();
	glTranslated(-0.05, 2.5, -0.9);
	glScaled(2.0, 2.0, 0.2);
	cube3.draw();
	glPopMatrix();	
}