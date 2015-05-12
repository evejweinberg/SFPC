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
    
    videoGrabber.initGrabber(320, 240);
    
    colorImg.allocate(videoGrabber.width, videoGrabber.height);
    grayImage.allocate(videoGrabber.width, videoGrabber.height);

aStart.set(ofGetWidth()/2,ofGetHeight()+500);
bEnd.set(ofGetWidth()/2, -1200);
pct = 0;
    
 
   
}



//-----------------------------------------------------------------------
void Balls::update(){
    
   
  
//    pct += 0.001;   // ie: pct = pct + 0.005
//    
//    if (pct > 1){
//        pct = 0;
//    }
    
    videoGrabber.update();
    
    bool bNewFrame = false;
    unsigned char * pixels;
    
    pixels = videoGrabber.getPixels();
    bNewFrame = videoGrabber.isFrameNew();
    
    if (bNewFrame){
        colorImg.setFromPixels(pixels, videoGrabber.width, videoGrabber.height);
        
        grayImage = colorImg;
        grayImage.mirror(false, true);
        
    }
}





//-----------------------------------------------------------------------
void Balls::draw(){

  

    ofSetColor(245);
    ofRect(ofGetWidth()/2,ofGetHeight()/2, 720+80, 720*.75+80);
    
    ofSetHexColor(0xffffff);
    ofSetRectMode (OF_RECTMODE_CENTER);
    grayImage.draw(ofGetWidth()/2,ofGetHeight()/2, 720, 720*.75);
    
    IplImage* eig = cvCreateImage( cvGetSize(grayImage.getCvImage()), 32, 1 );
    IplImage* temp = cvCreateImage( cvGetSize(grayImage.getCvImage()), 32, 1 );
    
    cvReleaseImage( &eig );
    cvReleaseImage( &temp );
    
    grayImage.draw(ofGetWidth()/2,ofGetHeight()/2, 640, 480);


    

    
    
}
