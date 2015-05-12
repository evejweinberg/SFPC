

#ifndef __ImageLoadingOne__CCPix1__
#define __ImageLoadingOne__CCPix1__

#include "ofMain.h"

#include <stdio.h>





class CCPix2 {
    
public:
    void setup();
    void update();
    void draw(int size, ofColor colorvarB);
    
    
    ofPoint centerx;
    ofPoint centery;
    ofColor color;
    ofImage cloud;
    
    ofBlendMode blendMode;
    float pct;
    
};


#endif /* defined(__ImageLoadingOne__Balls__) */