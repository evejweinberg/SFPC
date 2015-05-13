#include "RuleTwo.h"


void RuleTwo::setup() {
    
}

void RuleTwo::update() {
    
}

void RuleTwo::draw() {

    for (int i=0; i<100; i++) {
        ofSetColor(ofRandom(255));
        ofRect(ofRandom(800), ofRandom(800), 100, 40);
    }
    ofSetColor(255);
}