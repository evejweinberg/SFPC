#pragma once

#include "ofMain.h"
#include "RuleOne.h"
#include "RuleTwo.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		
    
   
    ofColor colors[11];
    
    
    char eventString[255];  // when do i use these floats?
    char eventStringB[255];  // when do i use these floats?
    char timeString[255];   // whats a char?
    
    unsigned long last;
    int counter;
    int Myradius;
   
  
    string str = "icon";
    ofImage icon[3];
    ofPoint pos;
   
    
    ofImage Nav;
    
    ofTrueTypeFont IntroBlack;
   
    
    
    int rule;
  
    RuleOne r1;
    RuleTwo r2;
    

		
};
