//
//  Cloud.h
//  RuleNine
//
//  Created by Eve Weinberg on 5/13/15.
//
//

#ifndef __RuleNine__Cloud__
#define __RuleNine__Cloud__

#include <stdio.h>
#include "ofMain.h"


class Cloud {
    
public:
    
    void setup(){
        cloud.loadImage("cloud.png");
    };
    
    void update(){
        cloud.update();
    };
    
    void draw() {
        for (int i = 0; i <6; i++){
        ofSetColor(192,223,228); //light blue
        cloud.draw(i*500,i*500,214,91);
        }
        
    };
    
    ofImage cloud;
     ofPoint pos;
    
    };
#endif /* defined(__RuleNine__Cloud__) */
