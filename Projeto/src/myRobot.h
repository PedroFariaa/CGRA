#ifndef MYROBOT_H
#define MYROBOT_H

#include "CGFobject.h"
#include <vector>
#include <stdio.h>

using namespace std;

class myRobot: public CGFobject {
	double x;
	double y;
	double z;
	double yOrientation;
	int stacks;
	bool textured;
	vector<double> xPoints;
	vector<double> zPoints;
	vector<double> xDist;
	vector<double> zDist;
	vector<double> xCirculePoints;
	vector<double> zCirculePoints;
	vector< vector<double> > xDraw;
	vector< vector<double> > zDraw;
	vector<double> xBase;
	vector<double> yBase;
	vector<double> zBase;
	vector<double> xTop;
	vector<double> yTop;
	vector<double> zTop;
	vector<double> xNormal;
	vector<double> yNormal;
	vector<double> zNormal;

public:
	myRobot(double x, double y, double z, double yOrientation, int stacks);
	void move(int dir);
	void rotate(int dir);
	void draw();
	void changeDrawType();
};

#endif