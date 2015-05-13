#include "RuleOne.h"


void RuleOne::setup() {
    
}

void RuleOne::update() {
    
}

void RuleOne::draw() {
    
    for (int i=0; i<100; i++) {
        ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
        ofCircle(ofRandom(800), ofRandom(800), 100);
    }
    ofSetColor(255);
}