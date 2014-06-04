#include "RectTool.h"

void RectTool::mousePressed(int x, int y)
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
	drawRect(sx,sy,currx,curry);
}

void RectTool::mouseDragged(int x, int y)
{
	// Redraw previous line (in XOR mode, will invert the color of all pixels, effectively erasing it)
	drawRect(sx,sy,currx,curry);

	// Update current coordinates
	currx=x;
	curry=y;

	// Draw new line
	drawRect(sx,sy,currx,curry);
}

void RectTool::mouseReleased(int x, int y)
{
	// Redraw previous line to erase it
	drawRect(sx,sy,currx,curry);

	// Set normal mode and color to draw fianl line
	canvas->setNormalMode();
	canvas->setColor(0);

	// draw final line
	drawRect(sx,sy,x,y);
}



void RectTool::drawRect(int xi, int yi, int xf, int yf){
	if(xf>=xi){
		for (int x=xi;x<=xf;x++){
			canvas->setPixel(x, yf);
			canvas->setPixel(x, yi);
		}
	}else{
		for (int x=xf;x<=xi;x++){
			canvas->setPixel(x, yf);
			canvas->setPixel(x, yi);
		}
	}

	if(yf>=yi){
		for (int y=yi;y<=yf;y++){
			canvas->setPixel(xi, y);
			canvas->setPixel(xf, y);
		}
	}else{
		for (int y=yf;y<=yi;y++){
			canvas->setPixel(xi, y);
			canvas->setPixel(xf, y);
		}
	}
}