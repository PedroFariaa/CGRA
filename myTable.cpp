#include "myTable.h"
#include "ExampleObject.h"

ExampleObject cube;

void myTable::draw() {

	//pernas
	glPushMatrix();
	glTranslated(5.85, 1.75, 1.15);
	glScaled(0.3, 3.5, 0.3);
	cube.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(5.85, 1.75, 3.85);
	glScaled(0.3, 3.5, 0.3);
	cube.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(1.15, 1.75, 1.15);
	glScaled(0.3, 3.5, 0.3);
	cube.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(1.15, 1.75, 3.85);
	glScaled(0.3, 3.5, 0.3);
	cube.draw();
	glPopMatrix();

	//tampo
	glPushMatrix();
	glTranslated(3.5, 3.65, 2.5);
	glScaled(5.0, 0.3, 3);
	cube.draw();
	glPopMatrix();	
}