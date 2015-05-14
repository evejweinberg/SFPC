#include "ofMain.h"
#include "RuleFive.h"
//#include "RuleFiveGlutWindow.h"

//========================================================================
int main( ){
//    RuleFiveGlutWindow window;
	ofSetupOpenGL(1400,875,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new RuleFive());

}
