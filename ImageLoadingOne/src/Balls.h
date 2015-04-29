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

#include <stdio.h>


class Balls {
    
public:
    void setup();
    void update();
    void draw();


    ofPoint aStart;
    ofPoint bEnd;
    ofColor color;
//    ofImage cloud;

    float pct;
    
    Balls(); //constructor ??

};


#endif /* defined(__ImageLoadingOne__Balls__) */
