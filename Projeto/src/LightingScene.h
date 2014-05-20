#ifndef LightingScene_H
#define LightingScene_H

#include "CGFscene.h"
#include "CGFappearance.h"
#include "myTable.h"
#include "Plane.h"
#include "myCylinder.h"
#include "myLamp.h"
#include "MyClock.h"
#include "myRobot.h"

class LightingScene : public CGFscene{

public:
	int sceneVar;
	int light0Status, light1Status, light2Status, light3Status, light4Status;
	bool clockStatus;
	int robotTexture;
	int wireframe;

	void init();
	void display();
	void update(unsigned long ms);
	int ResetClock();
	void moveRobot(int dir);
	void rotateRobot(int dir);

	CGFlight* light0;
	CGFlight* light1;
	CGFlight* light2;
	CGFlight* light3;
	CGFlight* light4;

	myRobot* robot;
	myClock* clock;
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
	CGFappearance* clockAppearance;
	CGFappearance* robotAppearance;

	void toggleSomething();
	~LightingScene();
};

#endif