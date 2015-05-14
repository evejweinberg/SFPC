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
    
    Cloud () {
        cloud.loadImage("cloud.png");
//        cloud.pos(100,100);
    };
    
    void update(){
        cloud.update();
//        if (cloud.x > ofGetWidth()+214){ //trying to say that if it goes off screen, write a new one
//            cloud.x = -214;
//           
//        }
    };
    
    void draw() {
        for (int i = 0; i <6; i++){
            for (int j = 0; j <6; j++){
        ofSetColor(192,223,228); //light blue
        cloud.draw(i*500+ofGetElapsedTimef()*50,j*500,214,91); //animate clouds on X here
        }
        }
     
        
    };
    
    ofImage cloud;
     ofPoint pos;
    
    };
#endif /* defined(__RuleNine__Cloud__) */
