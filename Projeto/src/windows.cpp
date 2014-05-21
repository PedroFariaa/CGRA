#include "Window.h"
#include <GL/GLU.h>
#include <cmath>


Window::Window(){
}

void Window::drawSquare(double i, double j){
	glBegin(GL_QUADS);
	glNormal3d(1,0,0);
	glVertex3d(0,0+i,0+j);
	glVertex3d(0,0+i,1/3+j);
	glVertex3d(0,1/3+i,1/3+j);
	glVertex3d(0,1/3+i,0+j);
	glEnd();
}

void Window::draw(){
	//draw first line
	for(int a=0; a<3; a++){
	drawSquare(0, a/6);
	}

}