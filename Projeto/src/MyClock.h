#ifndef MY_CLOCK
#define MY_CLOCK

#include "CGF/CGFobject.h"
#include "myCylinder.h"
#include "myClockHand.h"
#include "CGFapplication.h"

class myClock : public CGFobject {
private:
	myCylinder* cyl;
	myClockHand* ponteiro_horas;
	myClockHand* ponteiro_minutos;
	myClockHand* ponteiro_segundos;
	CGFappearance* clockHandAppearance;

public:
	myClock(); 
	void draw();
	void update(unsigned long millisegundos);
};

#endif