#include "ExampleObject.h"

void ExampleObject::draw() 
{
	glPushMatrix();
	glNormal3f(0.0,0.0, 1.0);
	//glTranslated(0.0,0.0,0.5);
	//glRotated(180, 0.0,1.0,0.0);
	glBegin(GL_QUADS);
	glTexCoord2d(-0.5, -0.5);
	glVertex3d(-0.5, -0.5, 0.5);
	glTexCoord2d(0.5, -0.5);
	glVertex3d(0.5, -0.5, 0.5);
	glTexCoord2d(0.5, 0.5);
	glVertex3d(0.5, 0.5, 0.5);
	glTexCoord2d(-0.5, 0.5);
	glVertex3d(-0.5, 0.5, 0.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glNormal3f(1.0,0.0, 0.0);       
	//glTranslated(0.5,0.0,0.0);
	glBegin(GL_QUADS);
	glTexCoord2d(-0.5, 0.5);
	glVertex3d(0.5, -0.5, 0.5);
	glTexCoord2d(-0.5, -0.5);
	glVertex3d(0.5, -0.5, -0.5);
	glTexCoord2d(0.5, -0.5);
	glVertex3d(0.5, 0.5, -0.5);
	glTexCoord2d(0.5, 0.5);
	glVertex3d(0.5, 0.5, 0.5);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glNormal3f(1.0, 0.0, 0.0);       
	//glTranslated(-0.5,0.0,0.0);
	//glRotated(90, 0.0,1.0,0.0);
	glBegin(GL_QUADS);
	glTexCoord2d(0.5, 0.5);
	glVertex3d(-0.5, 0.5, 0.5);
	glTexCoord2d(0.5, -0.5);
	glVertex3d(-0.5, 0.5, -0.5);
	glTexCoord2d(-0.5, -0.5);
	glVertex3d(-0.5, -0.5, -0.5);
	glTexCoord2d(-0.5, 0.5);
	glVertex3d(-0.5, -0.5, 0.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glNormal3f(0.0, 0.0, 1.0);       
	//glTranslated(0.0,0.0, -0.5);
	//glRotated(-90, 0.0,1.0,0.0);
	glBegin(GL_QUADS);
	glTexCoord2d(0.5, 0.5);
	glVertex3d(0.5, 0.5, -0.5);
	glTexCoord2d(0.5, -0.5);
	glVertex3d(0.5, -0.5, -0.5);
	glTexCoord2d(-0.5, -0.5);
	glVertex3d(-0.5, -0.5, -0.5);
	glTexCoord2d(-0.5, 0.5);
	glVertex3d(-0.5, 0.5, -0.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glNormal3f(0.0, 1.0, 0.0);       
	//glTranslated(0.0,-0.5,0.0);
	//glRotated(90, 1.0,0.0,0.0);
	glBegin(GL_QUADS);
	glTexCoord2d(-0.5, 0.5);
	glVertex3d(-0.5, -0.5, 0.5);
	glTexCoord2d(-0.5, -0.5);
	glVertex3d(-0.5, -0.5, -0.5);
	glTexCoord2d(0.5, -0.5);
	glVertex3d(0.5, -0.5, -0.5);
	glTexCoord2d(0.5, 0.5);
	glVertex3d(0.5, -0.5, 0.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glNormal3f(0.0, 1.0, 0.0);       
	//glTranslated(0.0,0.5,0.0);
	//glRotated(-90, 1.0,0.0,0.0);
	glBegin(GL_QUADS);
	glTexCoord2d(0.5, 0.5);
	glVertex3d(0.5, 0.5, 0.5);
	glTexCoord2d(0.5, -0.5);
	glVertex3d(0.5, 0.5, -0.5);
	glTexCoord2d(-0.5, -0.5);
	glVertex3d(-0.5, 0.5, -0.5);
	glTexCoord2d(-0.5, 0.5);
	glVertex3d(-0.5, 0.5, 0.5);
	glEnd();
	glPopMatrix();
}