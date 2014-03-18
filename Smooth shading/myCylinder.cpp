#include "myCylinder.h"
#include <cmath>

#define pi acos(-1.0)

myCylinder::myCylinder(int slices, int stacks/*, bool smooth*/) {

	for(int st=0; st <= stacks; st++){
		for(int slc=0; slc <= slices; slc++){
			glPushMatrix();
			glNormal3f(cos(slc*2*pi/slices)+stacks,0.0, sin(slc*2*pi/slices));
			glRotated(360/slices, 0.0,1.0,0.0);
			glRectf(1.0, 3.0+3.0*stacks, 1.0, 0.5);  
			glPopMatrix();
		}
	}

	
	
	
}
