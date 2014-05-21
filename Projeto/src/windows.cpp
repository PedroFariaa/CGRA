#include "Window.h"
#include <GL/GLU.h>
#include <cmath>


Window::Window(){
}

void Window::drawSquare(){
	glBegin(GL_QUADS);
	glNormal3d(1,0,0);
	glVertex3d(0,0,0);
	glVertex3d(0,1,0);
	glVertex3d(0,1,1);
	glVertex3d(0,0,1);
	glEnd();
}

void Window::draw(){
	drawSquare();
	glPushMatrix();
	glTranslated(0,0,1);
	drawSquare();
	glTranslated(0,0,1);
	drawSquare();
	glPopMatrix();

	glTranslated(0,1,0);
	glPushMatrix();
	drawSquare();
	glTranslated(0,0,1);
	glTranslated(0,0,1);
	drawSquare();
	glPopMatrix();

	glTranslated(0,1,0);
	drawSquare();
	glPushMatrix();
	glTranslated(0,0,1);
	drawSquare();
	glTranslated(0,0,1);
	drawSquare();
	glPopMatrix();
}