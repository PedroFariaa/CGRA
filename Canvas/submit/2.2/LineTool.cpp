#include "LineTool.h"
#include <cmath>

void LineTool::mousePressed(int x, int y)
{
	// Reset start coordinates and active (current) coordinates
	sx=x;
	sy=y;
	currx=x;
	curry=y;

	// Activate XOR mode with inverted color to enable rubber-banding
	canvas->setXORMode();
	canvas->setColor(255);

	// Draw first line (one pixel)
	drawLine(sx,sy,currx,curry);
}

void LineTool::mouseDragged(int x, int y)
{
	// Redraw previous line (in XOR mode, will invert the color of all pixels, effectively erasing it)
	drawLine(sx,sy,currx,curry);

	// Update current coordinates
	currx=x;
	curry=y;

	// Draw new line
	drawLine(sx,sy,currx,curry);
}

void LineTool::mouseReleased(int x, int y)
{
	// Redraw previous line to erase it
	drawLine(sx,sy,currx,curry);

	// Set normal mode and color to draw fianl line
	canvas->setNormalMode();
	canvas->setColor(0);

	// draw final line
	drawLine(sx,sy,x,y);
}



void LineTool::drawLine(int xi, int yi, int xf, int yf)
{
	// draws a line; 
	// simple flawed version, only draws in quadrants 1 and 4, 
	// and iterates over x, meaning there will be gaps on octants 2 and 7
	// where abs(delta y) > abs(delta x)

	if(xf==xi){
		if(yf>=yi){
			for(int y=yi; y<=yf; y++){
				canvas->setPixel(xi,y);
			}
		}else{
			for(int y=yf; y<=yi; y++){
				canvas->setPixel(xi,y);
			}
		}
	}

	float delta_x = abs(xf-xi);
	float delta_y = abs(yf-yi);

	if(delta_x >=delta_y){
		float m;
		if (xf!=xi)
			m=(float) (yf-yi)/(float)(xf-xi);
		else
			m=0;

		if(xf>=xi){
			for (int x=xi;x<=xf;x++)
				canvas->setPixel(x,yi+(x-xi)*m);
		}else{
			for (int x=xf;x<=xi;x++)
				canvas->setPixel(x,yi+(x-xi)*m);
		}
	}else{
		float m;
		if (yf!=yi)
			m=(float) (xf-xi)/(float)(yf-yi);
		else
			m=0;

		if(yf>=yi){
			for (int y=yi;y<=yf;y++)
				canvas->setPixel(xi+(y-yi)*m,y);
		}else{
			for (int y=yf;y<=yi;y++)
				canvas->setPixel(xi+(y-yi)*m,y);
		}
	}
}