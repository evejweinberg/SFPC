#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
    
    scenes[0] = new Intro();
    scenes[1] = new RuleOne();
    scenes[2] = new RuleTwo();
    scenes[3] = new RuleThree();
    scenes[4] = new RuleFour();
    scenes[5] = new RuleFive();
    scenes[6] = new RuleSix();
    scenes[7] = new RuleSeven();
    scenes[8] = new RuleEight();
    scenes[9] = new RuleNine();
    scenes[10] = new RuleTen();
    scenes[11] = new Extra();
    scenes[12] = new About();
    
    currentScene = 0;
    
    for (int i = 0; i < 13; i++){
        scenes[i]->setup();
    }
    
    nav.setup();

}

//--------------------------------------------------------------
void ofApp::update(){
    
    scenes[currentScene]->update();
    nav.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    scenes[currentScene]->draw();
    nav.draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == '1') currentScene = 1;
    if (key == '2') currentScene = 2;
    if (key == '3') currentScene = 3;
    if (key == '4') currentScene = 4;
    if (key == '5') currentScene = 5;
    if (key == '6') currentScene = 6;
    if (key == '7') currentScene = 7;
    if (key == '8') currentScene = 8;
    if (key == '9') currentScene = 9;
    if (key == '0') currentScene = 10;
    if (key == 'i') currentScene = 0;
    if (key == 'x') currentScene = 11;
    if (key == 'a') currentScene = 12;

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
