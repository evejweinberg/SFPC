

#include "CCPix1.h"
#include "Balls.h"

//-----------------------------------------------------------------------
void CCPix1::setup(){
//    centerx = ;
//    centery = ;

}



//-----------------------------------------------------------------------
void CCPix1::update(){
    
}





//-----------------------------------------------------------------------
void CCPix1::draw(int size, ofColor colorvarB){
//    ofSetRectMode (OF_RECTMODE_CENTER);
   
    
    ofSetColor(0);
    ofPushMatrix();
    ofRotate(0);
    ofRect(0,0,size,size);
    ofSetColor(colorvarB);
    ofRect(0,0,size-1,size-1);
//    blendMode = OF_BLENDMODE_MULTIPLY;
    ofSetColor(100,100,100,50);
     ofCircle(0,0,size/2,size/2);
    ofPopMatrix();
}