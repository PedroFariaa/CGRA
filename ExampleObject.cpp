#include "ExampleObject.h"

void ExampleObject::draw() 
{
	glPushMatrix();
	glNormal3f(0.0,0.0, 1.0);       
	glTranslated(0.0,0.0,-0.5);
	glRotated(180, 0.0,1.0,0.0);
	glRectf(-0.5, -0.5, 0.5, 0.5);  
	glPopMatrix();

	glPushMatrix();
	glNormal3f(0.0,0.0, 1.0);       
	glTranslated(0.0,0.0,0.5);
	glRectf(-0.5, -0.5, 0.5, 0.5);  
	glPopMatrix();
	
	glPushMatrix();
	glNormal3f(0.0,0.0, 1.0);       
	glTranslated(0.5,0.0,0.0);
	glRotated(90, 0.0,1.0,0.0);
	glRectf(-0.5, -0.5, 0.5, 0.5);  
	glPopMatrix();

	glPushMatrix();
	glNormal3f(0.0,1.0, 0.0);       
	glTranslated(-0.5,0.0,0.0);
	glRotated(-90, 0.0,1.0,0.0);
	glRectf(-0.5, -0.5, 0.5, 0.5);  
	glPopMatrix();

	glPushMatrix();
	glNormal3f(0.0,0.0, 0.0);       
	glTranslated(0.0,-0.5,0.0);
	glRotated(90, 1.0,0.0,0.0);
	glRectf(-0.5, -0.5, 0.5, 0.5);  
	glPopMatrix();

	glPushMatrix();
	glNormal3f(0.0,0.0, 0.0);       
	glTranslated(0.0,0.5,0.0);
	glRotated(-90, 1.0,0.0,0.0);
	glRectf(-0.5, -0.5, 0.5, 0.5);   
	glPopMatrix();


	/*
	glBegin(GL_QUADS);
		glVertex3d(0,0,0);
		glVertex3d(4,0,0);
		glVertex3d(4,3,0);
		glVertex3d(0,3,0);
	glEnd();

	glBegin(GL_TRIANGLES);
		glVertex3d(5,3,0);
		glVertex3d(2,4,0);
		glVertex3d(-1,3,0);
	glEnd();
	*/


}