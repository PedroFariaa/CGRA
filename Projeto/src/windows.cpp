#include "Window.h"
#include <GL/GLU.h>
#include <cmath>


Window::Window(){
}

void Window::draw(){
	// - - - - - - Linha de Baixo - - - - - -
	//quadrado da direita
	glPushMatrix();
	glTranslated(0,0.5,0.5);
	glBegin(GL_QUADS);
	glNormal3d(1,0,0);
	glTexCoord2d(-1,-1);
	glVertex3d(0,-0.5,-0.5);
	glTexCoord2d(0.025,-1);
	glVertex3d(0,0.5,-0.5);
	glTexCoord2d(0.025, 0.025);
	glVertex3d(0,0.5,0.5);
	glTexCoord2d(0.025,-1);
	glVertex3d(0,-0.5,0.5);
	glEnd();
	glPopMatrix();

	//quadrado do meio
	glPushMatrix();
	glTranslated(0,0.5,1.5);
	glBegin(GL_QUADS);
	glNormal3d(1,0,0);
	glTexCoord2d(0.025,-1);
	glVertex3d(0,-0.5,-0.5);
	glTexCoord2d(0.025,0.025);
	glVertex3d(0,0.5,-0.5);
	glTexCoord2d(0.975,0.025);
	glVertex3d(0,0.5,0.5);
	glTexCoord2d(0.975,-1);
	glVertex3d(0,-0.5,0.5);
	glEnd();
	glPopMatrix();

	//quadrado da esquerda
	glPushMatrix();
	glTranslated(0,0.5,2.5);
	glBegin(GL_QUADS);
	glNormal3d(1,0,0);
	glTexCoord2d(0.975,-1);
	glVertex3d(0,-0.5,-0.5);
	glTexCoord2d(0.975,0.025);
	glVertex3d(0,0.5,-0.5);
	glTexCoord2d(2,0.025);
	glVertex3d(0,0.5,0.5);
	glTexCoord2d(2,-1);
	glVertex3d(0,-0.5,0.5);
	glEnd();
	glPopMatrix();

	// - - - - - - Linha do Meio - - - - - -
	//quadrado da direita
	glPushMatrix();
	glTranslated(0,1.5,0.5);
	glBegin(GL_QUADS);
	glNormal3d(1,0,0);
	glTexCoord2d(-1,0.025);
	glVertex3d(0,-0.5,-0.5);
	glTexCoord2d(-1,0.975);
	glVertex3d(0,0.5,-0.5);
	glTexCoord2d(0.025,0.975);
	glVertex3d(0,0.5,0.5);
	glTexCoord2d(0.025,0.025);
	glVertex3d(0,-0.5,0.5);
	glEnd();
	glPopMatrix();
	
	//quadrado da esquerda
	glPushMatrix();
	glTranslated(0,1.5,2.5);
	glBegin(GL_QUADS);
	glNormal3d(1,0,0);
	glTexCoord2d(0.975,0.025);
	glVertex3d(0,-0.5,-0.5);
	glTexCoord2d(0.975,0.975);
	glVertex3d(0,0.5,-0.5);
	glTexCoord2d(2,0.975);
	glVertex3d(0,0.5,0.5);
	glTexCoord2d(2,0.025);
	glVertex3d(0,-0.5,0.5);
	glEnd();
	glPopMatrix();

	// - - - - - - Linha de Cima - - - - - -
	//quadrado da direita
	glPushMatrix();
	glTranslated(0,2.5,0.5);
	glBegin(GL_QUADS);
	glNormal3d(1,0,0);
	glTexCoord2d(-1,0.975);
	glVertex3d(0,-0.5,-0.5);
	glTexCoord2d(-1,2);
	glVertex3d(0,0.5,-0.5);
	glTexCoord2d(0.025,2);
	glVertex3d(0,0.5,0.5);
	glTexCoord2d(0.025,0.975);
	glVertex3d(0,-0.5,0.5);
	glEnd();
	glPopMatrix();

	//quadrado do meio
	glPushMatrix();
	glTranslated(0,2.5,1.5);
	glBegin(GL_QUADS);
	glNormal3d(1,0,0);
	glTexCoord2d(0.025,0.975);
	glVertex3d(0,-0.5,-0.5);
	glTexCoord2d(0.025,2);
	glVertex3d(0,0.5,-0.5);
	glTexCoord2d(0.975,2);
	glVertex3d(0,0.5,0.5);
	glTexCoord2d(0.975,0.975);
	glVertex3d(0,-0.5,0.5);
	glEnd();
	glPopMatrix();

	// quadrado da esquerda
	glPushMatrix();
	glTranslated(0,2.5,2.5);
	glBegin(GL_QUADS);
	glNormal3d(1,0,0);
	glTexCoord2d(0.975,0.975);
	glVertex3d(0,-0.5,-0.5);
	glTexCoord2d(0.975,2);
	glVertex3d(0,0.5,-0.5);
	glTexCoord2d(2,2);
	glVertex3d(0,0.5,0.5);
	glTexCoord2d(2,0.975);
	glVertex3d(0,-0.5,0.5);
	glEnd();
	glPopMatrix();
}