#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    art.loadImage("Spot01_13.jpg");
    art.setImageType(OF_IMAGE_GRAYSCALE);
    
    STD.loadMovie("Save The Date-HD.mp4");
    STD.setLoopState(OF_LOOP_NORMAL);
    STD.play();

    ofBackground(0,0,0);
    ofSetCircleResolution(100);
    Balls.setup();
    


}

//--------------------------------------------------------------
void ofApp::update(){
    STD.update();
    Balls.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetRectMode (OF_RECTMODE_CENTER);
    Balls.draw();
  
    ofImage screen;
    screen.grabScreen(0, 0, ofGetWidth(), ofGetHeight());

    ofClear(0,0,0);
    

    
    for (int i=0; i<screen.width; i+=20){
        for (int j=0; j< screen.height; j+=20){
            ofColor myColor = screen.getColor(i,j); //get the color of every 10 pixels
            float brightness = myColor.getBrightness(); // get the brightness of the color
            float length = ofMap(brightness,0,255,3,200);
            if (brightness > 40){
            ofSetColor(0,255,0,  ofMap(brightness, 0, 255, 255, mouseX));
            } else if (brightness <=40){
                ofSetColor(255,0,0,  ofMap(brightness, 0, 255, 255, mouseX));
        }
            float angle = ofMap(brightness,0,255,0, 200); //90 degrees
            float size = ofMap(brightness,0,255, 10, 2);
            ofPushMatrix();
            ofTranslate (i,j);
            ofRotateZ(angle);
            ofRect(0,0,length,2);
            ofPopMatrix();
        }
    }
//-----importing a video---------
//    for (int i=0; i<STD.width; i+=20){
//        for (int j=0; j< STD.height; j+=20){
//            ofColor myColor = STD.getPixelsRef().getColor(i,j); //get the color of every 10 pixels
//            float brightness = myColor.r; // get the brightness of the color
//            
//            ofSetColor(255,255,255,  ofMap(brightness, 0, 255, 255, mouseX));
//            float angle = ofMap(brightness,0,255,0, 180); //90 degrees
//            float size = ofMap(brightness,0,255, 10, 2);
//            ofPushMatrix();
//            ofTranslate (i,j);
//            ofRotateZ(angle);
//            ofRect(0,0,20,2);
//            ofPopMatrix();
//        }
//    }


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
