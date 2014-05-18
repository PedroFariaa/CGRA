#ifndef LightingScene_H
#define LightingScene_H

#include "CGFscene.h"
#include "CGFappearance.h"
#include "myTable.h"
#include "Plane.h"
#include "myCylinder.h"
#include "myLamp.h"
#include "MyClock.h"
#include "MyClockHand.h"

class LightingScene : public CGFscene
{
public:
	void init();
	void display();

	CGFlight* light0;
	CGFlight* light1;
	CGFlight* light2;
	CGFlight* light3;
	CGFlight* light4;


	myClock* clock;
	Plane* floor;
	myLamp* lamp;
	myCylinder* cyl_f;
	myCylinder* cyl;
	myTable* table;
	Plane* wall;
	Plane* boardA;
	Plane* boardB;
	myClockHand* ponteiro_horas;
	CGFappearance* materialA;
	CGFappearance* materialB;
	CGFappearance* tableAppearance;
	CGFappearance* boardAppearance;
	CGFappearance* board2Appearance;
	CGFappearance* windowAppearance;
	CGFappearance* floorAppearance;
	CGFappearance* wallAppearance;
	CGFappearance* clockAppearance;

	~LightingScene();
};

#endif