#include "myCylinder.h"
#include <cmath>

#define pi acos(-1.0)

myCylinder::myCylinder(int slices, int stacks, bool smooth) {

	this->slices=slices;
	this->stacks=stacks;
	this->smooth=smooth;	
}

void myCylinder:: draw(){
	for(int st=0; st < stacks; st++){
		for(int slc=0; slc < slices; slc++){
			glBegin(GL_QUADS);
			if(!smooth){
				glNormal3d(cos((2*pi/slices)*slc), st, sin((2*pi/slices)*slc));
				glTexCoord2d(cos((2*pi/slices)*slc), sin((2*pi/slices)*slc));
				glVertex3d(cos((2*pi/slices)*slc), st, sin((2*pi/slices)*slc));
				glTexCoord2d(cos((2*pi/slices)*slc), sin((2*pi/slices)*slc));
				glVertex3d(cos((2*pi/slices)*slc), st+1, sin((2*pi/slices)*slc));

				glNormal3d(cos((2*pi/slices)*slc), st+1, sin((2*pi/slices)*slc));
				glTexCoord2d(cos((2*pi/slices)*(slc+1)), sin((2*pi/slices)*(slc+1)));
				glVertex3d(cos((2*pi/slices)*(slc+1)), st+1, sin((2*pi/slices)*(slc+1)));
				glTexCoord2d(cos((2*pi/slices)*(slc+1)), sin((2*pi/slices)*(slc+1)));
				glVertex3d(cos((2*pi/slices)*(slc+1)), st, sin((2*pi/slices)*(slc+1)));
			}
			else{
				glNormal3d(cos((2*pi/slices)*slc), st, sin((2*pi/slices)*slc));
				glTexCoord2d(cos((2*pi/slices)*slc), sin((2*pi/slices)*slc));
				glVertex3d(cos((2*pi/slices)*slc), st, sin((2*pi/slices)*slc));
				glTexCoord2d(cos((2*pi/slices)*slc), sin((2*pi/slices)*slc));
				glVertex3d(cos((2*pi/slices)*slc), st+1, sin((2*pi/slices)*slc));

				glNormal3d(cos((2*pi/slices)*slc), st+1, sin((2*pi/slices)*slc));
				glTexCoord2d(cos((2*pi/slices)*(slc+1)), sin((2*pi/slices)*(slc+1)));
				glVertex3d(cos((2*pi/slices)*(slc+1)), st+1, sin((2*pi/slices)*(slc+1)));
				glTexCoord2d(cos((2*pi/slices)*(slc+1)), sin((2*pi/slices)*(slc+1)));
				glVertex3d(cos((2*pi/slices)*(slc+1)), st, sin((2*pi/slices)*(slc+1)));
			}
			glEnd();
		}
	}
		glBegin(GL_POLYGON);
			for(int slc=slices; slc>0; slc--){
				glNormal3d(0,1,0);

				glTexCoord2d((cos((2*pi/slices)*slc)/2)+0.5, (sin((2*pi/slices)*slc)/2)+0.5);
				glVertex3d(cos((2*pi/slices)*slc), stacks, sin((2*pi/slices)*slc));
			}
		glEnd();
}