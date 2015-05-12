//
//  Balls.cpp
//  ImageLoadingOne
//
//  Created by Eve Weinberg on 4/28/15.
//
//

#include "Balls.h"


//-----------------------------------------------------------------------
void Balls::setup(){

aStart.set(ofGetWidth()/2,ofGetHeight()+500);
bEnd.set(ofGetWidth()/2, -1200);
pct = 0;
    
    cloud.loadImage("cloud.png");
    Mate.loadImage("Mate.png");
    
    ofSetFrameRate(24);

    CompyFlip.loadMovie("CompyFlipBW.mov");
    CompyFlip.setLoopState(OF_LOOP_NORMAL);
    CompyFlip.play();
   
}



//-----------------------------------------------------------------------
void Balls::update(){
    
    CompyFlip.update();
  
    pct += 0.001;   // ie: pct = pct + 0.005
    
    if (pct > 1){
        pct = 0;
    }
}





//-----------------------------------------------------------------------
void Balls::draw(){

  
//
    for (int k = 0; k < 10; k ++) {
    for (int j = 0; j < 700; j ++) {

          ofSetColor(255);
// ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
        CompyFlip.draw((j*500)-900,500*k,300,304);
//        ofDisableBlendMode();
//        ofRectMode(OF_RECTMODE_CENTER);
        ofPushMatrix();
        
//        ofRotate(10);
        Mate.draw((j*500)-750,600*k+300,245/1.7,450/1.7);
        ofPopMatrix();
        ofRectMode(OF_RECTMODE_CORNER);

        if (j % 2 == 0){
            ofSetColor(192,223,228);
            cloud.draw((70*ofGetElapsedTimef())+(j*500)-1000,600*k,214,91);
        } else {
            ofSetColor(192,223,228);
            cloud.draw((70*ofGetElapsedTimef())+(j*500)-1000,600*k+300,214,91);
            ofSetColor(255);
            
        }
    }
    }
//
 

    

    
    
}
