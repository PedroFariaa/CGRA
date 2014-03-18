#include "myTable.h"
#include "ExampleObject.h"

ExampleObject cube;

void myTable::draw() {

	//pernas
	glPushMatrix();
	glTranslated(2.35, 1.75, -1.35);
	glScaled(0.3, 3.5, 0.3);
	cube.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(2.35, 1.75, 1.35);
	glScaled(0.3, 3.5, 0.3);
	cube.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-2.35, 1.75, -1.35);
	glScaled(0.3, 3.5, 0.3);
	cube.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-2.35, 1.75, 1.35);
	glScaled(0.3, 3.5, 0.3);
	cube.draw();
	glPopMatrix();

	//tampo
	glPushMatrix();
	glTranslated(0.0, 3.65, 0.0);
	glScaled(5.0, 0.3, 3);
	cube.draw();
	glPopMatrix();	
}