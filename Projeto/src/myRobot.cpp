#include "myRobot.h"
#include <cmath>
#include <stdio.h>
#define pi acos(-1.0)

myRobot::myRobot(double x, double y, double z, double yOrientation, int stacks) {
	float convertToRadius = pi / 180.0;
	this->x = x;
	this->y = y;
	this->z = z;
	this->yOrientation = yOrientation;
	this->stacks = stacks;
	this->textured = 1;

	float step = 0;
	int dir = 1;
	float xTemp = -0.5;
	float zTemp = 0.5;

	//Square draw points and normal points.
	for (unsigned int i = 0; i <13; i++){
		switch(dir){
		case 1:
			xTemp+=step;
			step = 1.0/3.0;
			xPoints.push_back(xTemp);
			zPoints.push_back(zTemp);
			xBase.push_back(0);
			yBase.push_back(0);
			zBase.push_back(1);
			break;
		case 2:
			zTemp-=step;
			xPoints.push_back(xTemp);
			zPoints.push_back(zTemp);
			xBase.push_back(1);
			yBase.push_back(0);
			zBase.push_back(0);
			break;
		case 3:
			xTemp-=step;
			xPoints.push_back(xTemp);
			zPoints.push_back(zTemp);
			xBase.push_back(0);
			yBase.push_back(0);
			zBase.push_back(-1);
			break;
		case 4:
			zTemp+=step;
			xPoints.push_back(xTemp);
			zPoints.push_back(zTemp);
			xBase.push_back(-1);
			yBase.push_back(0);
			zBase.push_back(0);
			break;
		default:
			break;
		}

		if (i == 3){
			dir++;
			xPoints.push_back(0.5);
			zPoints.push_back(0.5);
			xBase.push_back(1);
			yBase.push_back(0);
			zBase.push_back(0);
		}
		if (i == 6){
			dir++;
			xPoints.push_back(0.5);
			zPoints.push_back(-0.5);
			xBase.push_back(0);
			yBase.push_back(0);
			zBase.push_back(-1);
		}
		if (i == 9){
			dir++;
			xPoints.push_back(-0.5);
			zPoints.push_back(-0.5);
			xBase.push_back(-1);
			yBase.push_back(0);
			zBase.push_back(0);
		}
	}

	//Circule points and normal points.

	step = 0;
	for (unsigned int i = 0; i < 13; i++){
		xCirculePoints.push_back(sin((315+step)*convertToRadius) / 4.0);
		zCirculePoints.push_back(cos((315+step)*convertToRadius) / 4.0);
		xTop.push_back(sin((315+step-100)*convertToRadius) / 4.0);
		yTop.push_back(-0.5);
		zTop.push_back(cos((315+step-100)*convertToRadius) / 4.0);
		if (i == 3 || i == 6 || i == 9){
			xCirculePoints.push_back(sin((315+step)*convertToRadius) / 4.0);
			zCirculePoints.push_back(cos((315+step)*convertToRadius) / 4.0);
			xTop.push_back(sin((315+step-100)*convertToRadius) / 4.0);
			yTop.push_back(-0.5);
			zTop.push_back(cos((315+step-100)*convertToRadius) / 4.0);
		}
		step = step + 30;
	}

	//Distance between the circule points and the square points, to be used in the determination of all the robot points that must be drawn.
	for (unsigned int i = 0; i < 16; i++){
		xDist.push_back((xCirculePoints[i]-xPoints[i]));
		zDist.push_back((zCirculePoints[i]-zPoints[i]));
	}

	//Robot draw points
	for (unsigned int i = 0; i <16; i++){
		vector<double> tempx;
		vector<double> tempz;
		for (int j = 0; j <= stacks; j++){
			tempx.push_back(xPoints[i] + (xDist[i])*j*(1.0/stacks));
			tempz.push_back(zPoints[i] + (zDist[i])*j*(1.0/stacks));
		}
		xDraw.push_back(tempx);
		zDraw.push_back(tempz);
	}
}

/** Moves the robot in the direction specified by the parameter dir.
* If dir is set to 0, the robot will move forward, else he will move backwards.
*/
void myRobot::move(int dir) {
	float convertToRadius = pi / 180.0;
	if (dir == 0) {
		this->z += cos(yOrientation * convertToRadius) * 0.1;
		this->x += sin(yOrientation * convertToRadius) * 0.1;
	} else if (dir == 1) {
		this->z -= cos(yOrientation * convertToRadius) * 0.1;
		this->x -= sin(yOrientation * convertToRadius) * 0.1;
	}
}

/** Rotates the robot in the direction specified by the parameter dir.
* If dir is set to 0, the robot will rotate counter-clockwise, else he will rotate clockwise.
*/
void myRobot::rotate(int dir) {
	if (dir == 0) {
		this->yOrientation += 2.5;
	} else if (dir == 1) {
		this->yOrientation -= 2.5;
	}
}

//Robot draw method
void myRobot::draw() {
	float convertToRadius = pi / 180.0;
	float stepl = 30;

	glDisable(GL_CULL_FACE);

	if(textured == 0){
		glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
	}

	//Robot bottom.
	glPushMatrix();
	glNormal3f(0, 1, 0);
	glTranslated(x, y, z);
	glRotated(yOrientation, 0, 1, 0);
	glBegin(GL_POLYGON);
	glVertex3d(0.5, 0, -0.5);
	glVertex3d(-0.5, 0, -0.5);
	glVertex3d(-0.5, 0, 0.5);
	glVertex3d(0.5, 0, 0.5);
	glEnd(); 

	//Robot top circule.
	glPushMatrix();
	glTranslated(0, y+0.9, 0);
	glBegin(GL_POLYGON);
	for (float i = 15.0; i < 375.0; i = i + (stepl)) {
		glNormal3d(0, 1, 0);
		glVertex3d(sin(i * convertToRadius)/4, 0, cos(i * convertToRadius)/4);
	}
	glEnd();
	glPopMatrix();

	//Draws the robot and sets the normal points and texture coords.

	for (unsigned int i = 0; i < 15; i++){
		glBegin(GL_TRIANGLE_STRIP);
		for (int j = 0; j <=stacks; j++){
			glTexCoord2d(xDraw[i][j] + 0.5, 0.5 - zDraw[i][j]);
			glNormal3d(xDraw[i][j], 0, zDraw[i][j]);
			glVertex3d(xDraw[i][j], (double)j/stacks, zDraw[i][j]);

			glTexCoord2d(xDraw[i+1][j] + 0.5, 0.5 - zDraw[i+1][j]);
			glNormal3d(xDraw[i+1][j], 0, zDraw[i+1][j]);
			glVertex3d(xDraw[i+1][j], (double)j/stacks, zDraw[i+1][j]);

		}
		glEnd();
	}

	glPopMatrix();
	glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
	glEnable(GL_CULL_FACE);
}

/**Alternate from Textured or Wireframe mode in robot, for example,
* if the robot is in Textured mode, running
* this function will set it to Wireframe mode.
*/
void myRobot::changeDrawType()
{
	textured = !textured;
}