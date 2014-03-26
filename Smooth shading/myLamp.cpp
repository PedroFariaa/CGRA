#include "myLamp.h"
#include <cmath>

myLamp::myLamp(int slices, int stacks) {
	this->slices=slices;
	this->stacks=stacks;	
}



void myLamp::draw(){	
	for (int slc =0; slc<slices;slc++)
		for(int st=0; st<stacks; st++){
				glBegin(GL_QUADS);
					glNormal3f(cos(2*acos(-1.0)/slices*slc)*cos(2*acos(-1.0)/slices*st), st*cos(2*acos(-1.0)/slices*st), sin(2*acos(-1.0)/slices*slc)*cos(2*acos(-1.0)/slices*st));
					glVertex3f(cos(2*acos(-1.0)/slices*slc)*cos(2*acos(-1.0)/slices*st),st*cos(2*acos(-1.0)/slices*st),sin(2*acos(-1.0)/slices*slc)*cos(2*acos(-1.0)/slices*st));
					glVertex3f(cos(2*acos(-1.0)/slices*slc)*cos(2*acos(-1.0)/slices*st), st*cos(2*acos(-1.0)/slices*st),sin(2*acos(-1.0)/slices*slc)*cos(2*acos(-1.0)/slices*st));
					
					glNormal3f(cos(2*acos(-1.0)/slices*slc)*cos(2*acos(-1.0)/slices*(st+1)), (st+1)*cos(2*acos(-1.0)/slices*(st+1)), sin(2*acos(-1.0)/slices*slc)*cos(2*acos(-1.0)/slices*(st+1)));
					glVertex3f(cos(2*acos(-1.0)/slices*(slc+1))*cos(2*acos(-1.0)/slices*(st+1)),(st+1)*cos(2*acos(-1.0)/slices*(st+1)),sin(2*acos(-1.0)/slices*(slc+1))*cos(2*acos(-1.0)/slices*(st+1)));
					glVertex3f(cos(2*acos(-1.0)/slices*(slc+1))*cos(2*acos(-1.0)/slices*(st+1)),(st+1)*cos(2*acos(-1.0)/slices*(st+1)),sin(2*acos(-1.0)/slices*(slc+1))*cos(2*acos(-1.0)/slices*(st+1)));
				glEnd();
			
		}
}
