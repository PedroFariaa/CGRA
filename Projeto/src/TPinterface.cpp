#include "TPinterface.h"
#include "LightingScene.h"

TPinterface::TPinterface(){
	testVar=0;
	int robotTexture=0;
	wire=0;
}


void TPinterface::processKeyboard(unsigned char key, int x, int y){
	// Uncomment below if you would like to process the default keys (e.g. 's' for snapshot, 'Esc' for exiting, ...)
	CGFinterface::processKeyboard(key, x, y);

	//unsigned char LowerKey = tolower(key);
	//switch (LowerKey) {
	switch (key) {
	case 'a':
		// This is an example of accessing the associated scene
		// To test, create the function toggleSomething in your scene to activate/deactivate something
		((LightingScene *) scene)->toggleSomething();
		break;
	case 'i':
		((LightingScene *) scene)->moveRobot(0);
		break;
	case 'j':
		((LightingScene *) scene)->rotateRobot(0);
		break;
	case 'k':
		((LightingScene *) scene)->moveRobot(1);
		break;
	case 'l':
		((LightingScene *) scene)->rotateRobot(1);
		break;
	}
}

void TPinterface::initGUI(){
	/*
	// Check CGFinterface.h and GLUI documentation for the types of controls available
	GLUI_Panel *varPanel= addPanel("Group", 1);
	addSpinnerToPanel(varPanel, "Val 1(interface)", 2, &testVar, 1);

	// You could also pass a reference to a variable from the scene class, if public
	addSpinnerToPanel(varPanel, "Val 2(scene)", 2, &(((LightingScene*) scene)->sceneVar), 2);
	*/
	GLUI_Panel *lightPanel = addPanel("Lights", 1);
	addCheckboxToPanel(lightPanel, "Light 0:", &((LightingScene *) scene)->light0Status, 1);
	addCheckboxToPanel(lightPanel, "Light 1:", &((LightingScene *) scene)->light1Status, 2);
	addCheckboxToPanel(lightPanel, "Light 2:", &((LightingScene *) scene)->light2Status, 3);
	addCheckboxToPanel(lightPanel, "Light 3:", &((LightingScene *) scene)->light3Status, 4);

	addColumn();

	GLUI_Panel *clockPanel = addPanel("Clock", 1);
	GLUI_Button* startClock = addButtonToPanel(clockPanel, "Pause/Reset Clock", 5);

	addColumn();

	GLUI_Panel *robotTexturesPanel = addPanel("Robot Textures",1);
	GLUI_Listbox *robotTextures = addListboxToPanel(robotTexturesPanel, "", &robotTexture, 6);
	robotTextures->add_item(0, "Default Texture");
	robotTextures->add_item(1, "Orange");
	robotTextures->add_item(2, "Blue");
	robotTextures->add_item(3, "Black");
	robotTextures->add_item(4, "Green");

	addColumn();

	GLUI_Panel *wirePanel = addPanel("Drawing Mode", 1);
	GLUI_RadioGroup *wireGroup = addRadioGroupToPanel(wirePanel, &wire, 7);
	GLUI_RadioButton *wireButton = addRadioButtonToGroup(wireGroup, "Textured");
	GLUI_RadioButton *wireButton2 = addRadioButtonToGroup(wireGroup, "WireFrame");

}

void TPinterface::processGUI(GLUI_Control *ctrl)
{
	printf ("GUI control id: %d\n  ",ctrl->user_id);
	switch (ctrl->user_id)
	{
	case 5:
		{
			((LightingScene*) scene)->clockStatus = !((LightingScene*)scene)->clockStatus;
			break;
		}
	case 6:
		{
			((LightingScene*) scene)->robotTexture=robotTexture;
			break;
		}
	case 7:
		{
			((LightingScene*) scene)->wireframe=wire;
			break;
		}
	};
}

