//
//  Balls.h
//  ImageLoadingOne
//
//  Created by Eve Weinberg on 4/28/15.
//
//

#ifndef __ImageLoadingOne__Balls__
#define __ImageLoadingOne__Balls__
#include "ofMain.h"
#include "ofxOpenCv.h"

#include <stdio.h>


class Balls {
    
public:
    void setup();
    void update();
    void draw();


    ofPoint aStart;
    ofPoint bEnd;
    ofColor color;
   

    float pct;
    ofBlendMode blendMode;
    
    ofVideoGrabber		videoGrabber;
    
    ofxCvColorImage		colorImg;
    
    ofxCvGrayscaleImage 	grayImage;


};


#endif /* defined(__ImageLoadingOne__Balls__) */
