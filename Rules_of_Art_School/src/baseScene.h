//
////this indef/define part was automatically generated
//
//#ifndef __Rules_of_Art_School__baseScene__
//#define __Rules_of_Art_School__baseScene__
//
//#include <stdio.h>
//
//
//
//#endif




//this indef/define I copy/pasted from Zach's algo/week9 example

#ifndef _BASE_SCENE
#define _BASE_SCENE


#include "ofMain.h"

// 'vurtual void' is telling the compiler that anything subclassing this class shoud always have this function
class baseScene {
    
    
public:
    
    virtual void setup();
    virtual void update();
    virtual void draw();
    
    virtual void keyPressed(int key);
    virtual void keyReleased(int key);
    virtual void mouseMoved(int x, int y );
    virtual void mouseDragged(int x, int y, int button);
    virtual void mousePressed(int x, int y, int button);
    virtual void mouseReleased(int x, int y, int button);
    virtual void windowResized(int w, int h);
    virtual void dragEvent(ofDragInfo dragInfo);
    virtual void gotMessage(ofMessage msg);
    
    
};



#endif