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
    
    
    IntroBlack.loadFont("Intro Black.otf", 52); //font size
    
    string name;
    ofxPanel WAVE;
    
   
    
    for (int i = 0; i < 8; i++){
        name = "WAVE_" + ofToString(i);
        panels[i].setup(name, "settings" + ofToString(i) + ".xml", ofGetWidth()-230, 150*i);
        panels[i].add(peaks[i].set("Number of Peaks",50, 0, 100));
        panels[i].add(amplitude[i].set("Amplitude",0.01f, 0.01f, 0.2f));
        panels[i].add(radius[i].set("Radius", 150.0, 20, 300));
        panels[i].add(noiseModFactor[i].set("Noise", 0.0, 0.0, 5.0));
        panels[i].add(velocity[i].set("Velocity", 0.1f, 0.01f, 1.0f));
        panels[i].add(LineWeight[i].set("Line Weight", 2, 2, 50));
        
//        if (panels[i].y > 600){
//               panels[i].setup(name, "settings" + ofToString(i) + ".xml", ofGetWidth()-430, 150*i);
//        }
    }
    
    
    ofBackground(0);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    //BG------white paper with light blue gridded lines--------------------
    ofBackground(255);
    ofSetColor( ofColor::lightBlue);
    ofSetLineWidth(1);
    for (int i = 0; i < ofGetWidth(); i = i + 20){
        ofLine(i,0,i, ofGetHeight());
        
    }
    
    for (int i = 0; i < ofGetHeight(); i = i + 20){
        ofLine(0, i, ofGetWidth(), i);
    }
    
    //------------------- start drawing ------------------------------------
    
    ofNoFill();
    
    float resolution = 1000;
    ofPushMatrix();
     ofTranslate(500,450);
    
    for (int j = 0; j < 8; j++) {
        ofSetLineWidth(6);
        
        ofBeginShape();
         ofSetColor(colors[j]);
       
        for(int i=0; i<=resolution; i++) {
            
            float t = i/resolution;
            
            float xraw = sin(t*TWO_PI);
            float yraw = cos(t*TWO_PI);
            
            float displaceNoiseMod = ofNoise(xraw+ofGetElapsedTimef(), yraw+ofGetElapsedTimef()) * radius[j];
            displaceNoiseMod*=noiseModFactor[j].get();
            
            float wave = (displaceNoiseMod+radius[j]) * amplitude[j] * sin(t*TWO_PI*peaks[j] + ofGetFrameNum()*velocity[j])  ;
            
            float x = (radius[j]+wave) * xraw;
            float y = (radius[j]+wave) * yraw;
            
            ofCurveVertex(x, y);
            
        }
         ofEndShape();
    }
    
        ofPopMatrix();

        for (int i = 0; i < 8; i++){
            panels[i].draw();
        }
        

    
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

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
