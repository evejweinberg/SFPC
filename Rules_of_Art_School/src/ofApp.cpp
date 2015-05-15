#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
    
    scenes.push_back(new Intro());
    scenes[0]->enable();
    
    scenes.push_back(new RuleOne());
    scenes.push_back(new RuleTwo());
    scenes.push_back(new RuleThree());
    scenes.push_back(new RuleFour());
    scenes.push_back(new RuleFive());
    scenes.push_back(new RuleSix());
    scenes.push_back(new RuleSeven());
    scenes.push_back(new RuleEight());
    scenes.push_back(new RuleNine());
    scenes.push_back(new RuleTen());
    scenes.push_back(new Extra());
    scenes.push_back(new About());
    

    
    for (int i = 0; i < scenes.size(); i++){
        scenes[i]->setup();
    }
    
    nav.setup();

}


void ofApp::enableScene(int index) {
    
    for (int i = 0; i < scenes.size(); i++){
        if(i==index) {
            scenes[i]->enable();
        } else {
            scenes[i]->disable();
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i = 0; i < scenes.size(); i++){
        if(scenes[i]->isEnabled()) {
            scenes[i]->update();
        }
    }
    
    nav.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i = 0; i < scenes.size(); i++){
        if(scenes[i]->isEnabled()) {
            ofPushStyle();
            ofPushMatrix();
            scenes[i]->draw();
            ofPopMatrix();
            ofPopStyle();
        }
    }
    
    nav.draw();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    for (int i = 0; i < scenes.size(); i++){
        if(scenes[i]->isEnabled()) scenes[i]->keyPressed(key);
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    for (int i = 0; i < scenes.size(); i++){
        if(scenes[i]->isEnabled()) scenes[i]->keyReleased(key);
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    for (int i = 0; i < scenes.size(); i++){
        if(scenes[i]->isEnabled()) scenes[i]->mouseMoved(x,y);
    }
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    for (int i = 0; i < scenes.size(); i++){
        if(scenes[i]->isEnabled()) scenes[i]->mouseDragged(x,y,button);
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    for (int i = 0; i < scenes.size(); i++){
        if(scenes[i]->isEnabled()) scenes[i]->mousePressed(x,y,button);
    }
    
    nav.mousePressed(x,y,button);
    enableScene(nav.setActiveScene);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    for (int i = 0; i < scenes.size(); i++){
        if(scenes[i]->isEnabled()) scenes[i]->mouseReleased(x,y,button);
    }
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
