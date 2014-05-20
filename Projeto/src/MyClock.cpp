#include "MyClock.h"
#include "MyClockHand.h"
#include <iostream>

myClock::myClock(){
	myCylinder* cylinder = new myCylinder(12, 1, true);
	this->cyl=cylinder;
	ponteiro_horas = new myClockHand(0,0.2);
	ponteiro_minutos = new myClockHand(0, 0.35);
	ponteiro_segundos = new myClockHand(0, 0.5);

	float ambclockHand[3] = {0.2, 0.2, 0.2};
	float difclockHand[3] = {0.9, 0.9, 0.9};
	float specclockHand[3] = {0.2, 0.2, 0.2};
	float shininessclockHand = 200.f;

	clockHandAppearance = new CGFappearance(ambclockHand, difclockHand, specclockHand, shininessclockHand);
	clockHandAppearance->setTexture("clockHand.png");

	ponteiro_horas->setAngle(90);
	ponteiro_minutos->setAngle(180);
	ponteiro_segundos->setAngle(270);

}

void myClock::draw(){
	glPushMatrix();
	glScaled(0.5, 0.5, 0.2);
	glRotated(90, 1, 0, 0);
	cyl->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 0, 0.21);
	clockHandAppearance->apply();
	ponteiro_horas->draw();
	ponteiro_minutos->draw();
	ponteiro_segundos->draw();
	glPopMatrix();
}

void myClock::update(unsigned long millisegundos){
	float ms = (float) 6*millisegundos/2000000000;
	this->ponteiro_horas->setAngle(ponteiro_horas->getAngle()-ms/3600);
	this->ponteiro_minutos->setAngle(ponteiro_minutos->getAngle()-ms/60);
	this->ponteiro_segundos->setAngle(ponteiro_segundos->getAngle()-ms);
}