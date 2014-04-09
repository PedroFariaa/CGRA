#include "ExampleObject.h"

void ExampleObject::draw() 
{
	glPushMatrix();
	glNormal3f(0.0,0.0, 1.0);
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
	glNormal3f(1.0,0.0, 0.0);  
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
	glNormal3f(0.0,0.0, 1.0);   
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
	glNormal3f(0.0,1.0, 0.0);     
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
	glNormal3f(0.0,1.0, 0.0);  
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