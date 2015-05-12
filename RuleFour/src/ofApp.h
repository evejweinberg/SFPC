#pragma once

#include "ofMain.h"
#include "BallDrop.h"

#define ARTWORKTOTAL 8

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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void drawHI(float xPos, float yPos, float scale);
        void drawPinkPolkaCircle(float xPos, float yPos, float scale);
        void drawaPolkaDotO(float xPos, float yPos, float scale);
        void drawGradient();
    
    ofImage Consider, Everything, tobe, an, Experiment, InstA;
    ofImage imggrad;
    ofColor col;
    ofColor color;
    
    int Mousereact;
    float MyOutlineWidth = 4;
    unsigned long last;
    int counter;
    float Myradius;
    
    ofColor salmon;
    ofColor tan;
    ofColor yellow;
    ofColor brown;
    ofColor green;
    ofColor royal;
    ofColor blue;
    ofColor pink;
    ofColor myOutlines = ofColor :: black;
    ofColor myPurple = ofColor :: crimson;
    ofColor Pink = ofColor :: hotPink;
    ofColor Blue = ofColor :: skyBlue;
    ofColor Aqua = ofColor :: aquamarine;
    ofColor MedAqua = ofColor :: mediumAquaMarine;
    ofColor Salmon = ofColor :: salmon;
    ofColor Gold = ofColor :: gold;
    
    ofColor colors[9];
    vector <BallDrop> allBallsDropping;
    
    ofImage LikeThis[ARTWORKTOTAL];
    string str = "LikeThis";
   
		
};
