#ifndef LightingScene_H
#define LightingScene_H

#include "CGFscene.h"
#include "CGFappearance.h"
#include "myTable.h"
#include "Plane.h"
#include "myCylinder.h"
#include "myLamp.h"

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


	Plane* floor;
	myLamp* lamp;
	myCylinder* cyl_f;
	myCylinder* cyl;
	myTable* table;
	Plane* wall;
	Plane* boardA;
	Plane* boardB;
	CGFappearance* materialA;
	CGFappearance* materialB;
	CGFappearance* tableAppearance;
	CGFappearance* boardAppearance;
	CGFappearance* board2Appearance;
	CGFappearance* windowAppearance;
	CGFappearance* floorAppearance;
	CGFappearance* wallAppearance;

	~LightingScene();
};

#endif