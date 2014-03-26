#ifndef MY_LAMP
#define MY_LAMP

#include "CGF/CGFobject.h"

class myLamp : public CGFobject {
private:
	int slices;
	int stacks;
	bool smooth;
public:
	myLamp(int slices, int stacks);
	void draw();
};



#endif
