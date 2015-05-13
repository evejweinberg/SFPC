#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    colors[0].set(224,103,99); //coral
    colors[1].set(140,207,160); //green
    colors[2].set(98,196,215); //teal
    colors[3].set(243,167,153); //salmon
    colors[4].set(236,214,95); //yellow
    colors[5].set(150,107,138); //purple
    colors[6].set(91,116,183); //drkblue
    colors[7].set(200,221,109); //lime
    colors[8].set(211,137,104); // sunburn
    colors[9].set(224,103,99); //pinkagain
    colors[10].set(85,85,140); //reallydarkblue
    
    
    IntroBlack.loadFont("Intro Black.otf", 15);
    
    string name;
    for (int i = 0; i < 3; i++){
        name = "icons-0" + ofToString(i) + ".png";
        icon[i].loadImage(name);
        cout << name << endl;
    }
    
    Nav.loadImage("Nav.png");

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    int navcirc;
    int circlesTotal = 13;
    float radius = 15;
    
    for (navcirc = 0; navcirc < circlesTotal; navcirc++) {
        ofSetColor(colors[navcirc]);
        pos.set(ofGetWidth()-37,-100+ofGetHeight()-50*navcirc);
                if (navcirc > 10){
            colors[navcirc] = colors[navcirc % 10];
        }

        if (pos.distance(ofPoint(mouseX,mouseY)) < radius){
            radius = 25;
        } else {
            radius = 15;
        }
        
        //mousePress action here?
        
        ofCircle(pos,radius);
        int currentCircle = circlesTotal - navcirc;
        
        
        ofPushMatrix();
        
        
        ofTranslate(ofGetWidth()-37, -93+ofGetHeight());
        ofSetColor(73,66,54); //brown
        if (navcirc > 1 && navcirc < 12) {
            
            int swidth = IntroBlack.stringWidth(ofToString(currentCircle-1));
            IntroBlack.drawString(ofToString(currentCircle-1), -swidth/2, -50*navcirc);
            
        }
        
        ofPopMatrix();

        
    }


    icon[1].draw(ofGetWidth()-47, ofGetHeight()-709); //house
    icon[0].draw(ofGetWidth()-47, ofGetHeight()-109); //?
    icon[2].draw(ofGetWidth()-47, ofGetHeight()-158); // +
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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

