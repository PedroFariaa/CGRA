#include "LightingScene.h"
#include "CGFaxis.h"
#include "CGFapplication.h"
#include "myTable.h"
#include "Plane.h"
#include "myCylinder.h"
#include "myLamp.h"
#include "MyClock.h"
#include "MyClockHand.h"
#include "myRobot.h"

#include <math.h>

float pi = acos(-1.0);
float convertToRadius=pi/180.0;

#define BOARD_HEIGHT 6.0
#define BOARD_WIDTH 6.4

// Positions for two lights
float light0_pos[4] = {4, 6.0, 1.0, 1.0};
float light1_pos[4] = {10.5, 6.0, 1.0, 1.0};

float light2_pos[4] = {10.5, 6.0, 5.0, 1.0};
float light3_pos[4] = {4, 6.0, 5.0, 1.0};

float light4_pos[4] = {0.15, 4.0, 7.5, 1.0};

// Global ambient light (do not confuse with ambient component of individual lights)
//float globalAmbientLight[4]= {0.2,0.2,0.2,1.0};
float globalAmbientLight[4]= {0.0,0.0,0.0,1.0};

// number of divisions
#define BOARD_A_DIVISIONS 30
#define BOARD_B_DIVISIONS 100

//Coefficients for board
float ambBoard[3] = {0.2, 0.2, 0.2};
float difBoard[3] = {0.9, 0.9, 0.9};
float specBoard[3] = {0.2, 0.2, 0.2};
float shininessBoard = 10.f;

//Coefficients for board2
float ambBoard2[3] = {0.2, 0.2, 0.2};
float difBoard2[3] = {0.4, 0.4, 0.4};
float specBoard2[3] = {0.7, 0.7, 0.7};
float shininessBoard2 = 200.f;


// Coefficients for material A
float ambA[3] = {0.2, 0.2, 0.2};
float difA[3] = {0.6, 0.6, 0.6};
float specA[3] = {0.0, 0.8, 0.8};
float shininessA = 120.f;

// Coefficients for material B
float ambB[3] = {0.2, 0.2, 0.2};
float difB[3] = {0.6, 0.6, 0.6};
float specB[3] = {0.8, 0.8, 0.8};
float shininessB = 120.f;

// Coefficients for table texture
float ambTable[3] = {0.2, 0.2, 0.2};
float difTable[3] = {0.9, 0.9, 0.9};
float specTable[3] = {0.2, 0.2, 0.2};
float shininessTable = 200.f;

float ambientNull[4]={0,0,0,1};
float yellow[4]={1,1,0,1};

void LightingScene::toggleSomething(){

}

void LightingScene::init(){

	this->sceneVar=0;

	light0Status = 0;
	light1Status = 0;
	light2Status = 0;
	light3Status = 0;
	light4Status = 0;
	clockStatus = true;
	robotTexture = 0;
	wireframe = 0;

	// Enables lighting computations
	glEnable(GL_LIGHTING);

	// Sets up some lighting parameters
	// Computes lighting only using the front face normals and materials
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);  

	// Define ambient light (do not confuse with ambient component of individual lights)
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbientLight);  

	// Declares and enables two lights, with null ambient component

	light0 = new CGFlight(GL_LIGHT0, light0_pos);
	light0->setAmbient(ambientNull);
	light0->setSpecular(yellow);

	//light0->disable();
	//light0->enable();

	light1 = new CGFlight(GL_LIGHT1, light1_pos);
	light1->setAmbient(ambientNull);

	//light1->disable();
	//light1->enable();

	light2 = new CGFlight(GL_LIGHT2, light2_pos);
	light2->setAmbient(ambientNull);
	light2->setKc(0.0);
	light2->setKl(1.0);
	light2->setKq(0.0);

	//light2->disable();
	//light2->enable();

	light3 = new CGFlight(GL_LIGHT3, light3_pos);
	light3->setAmbient(ambientNull);
	light3->setSpecular(yellow);
	light3->setKc(0.0);
	light3->setKl(0.0);
	light3->setKq(1.0);

	//light3->disable();
	//light3->enable();

	light4 = new CGFlight(GL_LIGHT4, light4_pos);
	light4->setAmbient(ambientNull);
	light4->setSpecular(yellow);
	light4->setKc(0.0);
	light4->setKl(0.0);
	light4->setKq(1.0);

	//light4->disable();
	//light4->enable();

	// Uncomment below to enable normalization of lighting normal vectors
	glEnable (GL_NORMALIZE);

	//Declares scene elements
	clock = new myClock();
	lamp = new myLamp(5,4);
	cyl_f = new myCylinder(30, 4, false);
	cyl = new myCylinder(30, 4, true);
	table = new myTable();
	wall = new Plane(10, -1, -1, 2, 2);
	floor = new Plane(120, 0, 0, 10, 12);
	boardA = new Plane(BOARD_A_DIVISIONS, 0, 0, 1, 1);
	boardB = new Plane(BOARD_B_DIVISIONS, 0,-0.14,1,1.14);
	robot = new myRobot(5.0,0.1,5.0,0,8);


	//Declares materials
	//materialA = new CGFappearance(ambA,difA,specA,shininessA);
	//materialB = new CGFappearance(ambB,difB,specB,shininessB);

	tableAppearance = new CGFappearance(ambTable, difTable, specTable, shininessTable);
	tableAppearance->setTexture("table.png");
	boardAppearance = new CGFappearance(ambBoard, difBoard, specBoard, shininessBoard);
	boardAppearance->setTexture("slides.png");
	board2Appearance = new CGFappearance(ambBoard2, difBoard2, specBoard2, shininessBoard2);
	board2Appearance->setTexture("board.png");
	board2Appearance->setTextureWrap(GL_CLAMP, GL_CLAMP);
	windowAppearance = new CGFappearance(ambBoard2, difBoard2, specBoard2, shininessBoard2);
	windowAppearance->setTexture("window.png");
	windowAppearance->setTextureWrap(GL_CLAMP, GL_CLAMP);
	floorAppearance = new CGFappearance(ambBoard, difBoard, specBoard, shininessBoard);
	floorAppearance->setTexture("floor.png");
	wallAppearance = new CGFappearance(ambTable, difTable, specTable, shininessTable);
	wallAppearance->setTexture("wall.png");
	clockAppearance = new CGFappearance(ambTable, difTable, specTable, shininessTable);
	clockAppearance->setTexture("clock.png");

	robotAppearance = new CGFappearance(ambTable, difTable, specTable, shininessTable);

	setUpdatePeriod(100);
}

void LightingScene::display(){

	// ---- BEGIN Background, camera and axis setup

	// Clear image and depth buffer everytime we update the scene
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	// Initialize Model-View matrix as identity (no transformation
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Apply transformations corresponding to the camera position relative to the origin
	CGFscene::activeCamera->applyView();

	if(light0Status==0){
		light0->disable();
	}else{
		light0->enable();
	}
	if(light1Status==0){
		light1->disable();
	}else{
		light1->enable();
	}
	if(light2Status==0){
		light2->disable();
	}else{
		light2->enable();
	}
	if(light3Status==0){
		light3->disable();
	}else{
		light3->enable();
	}
	if(light4Status==0){
		light4->disable();
	}else{
		light4->enable();
	}

	if(robotTexture==0){
		robotAppearance->setTexture("robot1.jpg");
	}else if(robotTexture==1){
		robotAppearance->setTexture("robot2.jpg");
	}else if(robotTexture==2){
		robotAppearance->setTexture("robot3.jpg");
	}else if(robotTexture==3){
		robotAppearance->setTexture("robot4.jpg");
	}else if(robotTexture==4){
		robotAppearance->setTexture("robot5.jpg");
	}

	light0->draw();
	light1->draw();
	light2->draw();
	light3->draw();
	light4->draw();

	// Draw axis
	axis.draw();

	// ---- END Background, camera and axis setup

	// ---- BEGIN Primitive drawing section

	//Robot
	glPushMatrix();
	if(wireframe==1){
		glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
		robot->draw();
	}else{
		robotAppearance->apply();
		robot->draw();
	}
	glPopMatrix();

	// lamp
	glPushMatrix();
	//	glTranslated(4, 0, 0);
	lamp->draw();
	glPopMatrix();

	wallAppearance->apply();
	// cylinder with smooth shading
	glPushMatrix();
	glTranslated(14, 0, 14);
	cyl->draw();
	glPopMatrix();

	/*
	// cylinder with flat shading
	glPushMatrix();
	glTranslated(10, 0, 5);
	cyl_f->draw();
	glPopMatrix();
	*/


	//First Table
	glPushMatrix();
	glTranslated(5,0,8);
	tableAppearance->apply();
	table->draw();
	glPopMatrix();

	//Second Table
	glPushMatrix();
	glTranslated(12,0,8);
	table->draw();
	glPopMatrix();

	//PlaneWall
	wallAppearance->apply();
	glPushMatrix();
	glTranslated(7.5,4,0);
	glRotated(90.0,1,0,0);
	glScaled(15,0.2,8);
	wall->draw();
	glPopMatrix();

	//LeftWall
	glPushMatrix();
	windowAppearance->apply();
	glTranslated(0,4,7.5);
	glRotated(-90.0,0,0,1);
	glScaled(8,0.2,15);
	glRotated(90, 0, 1, 0);
	wall->draw();
	glPopMatrix();




	boardAppearance->apply();
	// Board A
	glPushMatrix();
	glTranslated(4,4,0.2);
	glScaled(BOARD_WIDTH,BOARD_HEIGHT,1);
	glRotated(90.0,1,0,0);
	//materialA->apply();
	boardA->draw();
	glPopMatrix();

	board2Appearance->apply();
	//PlaneB
	glPushMatrix();
	glTranslated(10.5,4,0.2);
	glScaled(BOARD_WIDTH,BOARD_HEIGHT,1);
	glRotated(90.0,1,0,0);
	//materialB->apply();
	boardB->draw();
	glPopMatrix();


	//Floor
	floorAppearance->apply();
	glPushMatrix();
	glTranslated(7.5,0,7.5);
	glScaled(15,0.2,15);
	floor->draw();
	glPopMatrix();

	// clock
	glPushMatrix();
	glTranslated(7.25, 7.5, 0);
	clockAppearance->apply();
	clock->draw();
	glPopMatrix();

	// ---- END Primitive drawing section


	// We have been drawing in a memory area that is not visible - the back buffer, 
	// while the graphics card is showing the contents of another buffer - the front buffer
	// glutSwapBuffers() will swap pointers so that the back buffer becomes the front buffer and vice-versa
	glutSwapBuffers();
}

void LightingScene::moveRobot(int dir){
	robot->move(dir);
}

void LightingScene::rotateRobot(int dir){
	robot->rotate(dir);
}

int LightingScene:: ResetClock(){
	if(clockStatus){
		clockStatus = !clockStatus;
		return 0;
	}
	else{
		clock = new myClock();
		clockStatus = !clockStatus;
		return 1;
	}
}

void LightingScene::update(unsigned long ms){
	if(clockStatus)
		clock->update(ms);
}

LightingScene::~LightingScene() 
{
	delete(light0);
	delete(light1);
	delete(light2);
	delete(light3);
	delete(light4);

	delete(lamp);
	delete(cyl_f);
	delete(cyl);
	delete(table);
	delete(wall);
	delete(boardA);
	delete(boardB);
	delete(materialA);
	delete(materialB);
	delete(boardAppearance);
	delete(board2Appearance);
	delete(windowAppearance);
	delete(floorAppearance);
	delete(wallAppearance);
	delete(floor);
	delete(clock);
	delete(robot);
}