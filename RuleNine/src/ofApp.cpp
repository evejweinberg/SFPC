#include "ofApp.h"
#include "ofxImageSequence.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
   
    Nav.loadImage("Nav.png");

    
    cloud.loadImage("cloud.png");
    Mate.loadImage("Mate.png");
    CompyFlip.loadMovie("CompyFlipBW.mov");
    CompyFlip.setLoopState(OF_LOOP_NORMAL);
    CompyFlip.play();
    
    videoGrabber.initGrabber(320, 240);
    
    colorImg.allocate(videoGrabber.width, videoGrabber.height);
    grayImage.allocate(videoGrabber.width, videoGrabber.height);

}

//--------------------------------------------------------------
void ofApp::update(){
    

     CompyFlip.update();
    
    ofBackground(100,100,100);
    
    videoGrabber.update();
    
    bool bNewFrame = false;
    unsigned char * pixels;
    
    pixels = videoGrabber.getPixels();
    bNewFrame = videoGrabber.isFrameNew();
    
    if (bNewFrame){
        colorImg.setFromPixels(pixels, videoGrabber.width, videoGrabber.height);
        
        grayImage = colorImg;
        grayImage.mirror(false, true);
    }

}

//--------------------------------------------------------------
void ofApp::draw(){

    

    
    //    //BG------white paper with light blue gridded lines--------------------
        ofBackground(255);
        ofSetColor( ofColor::lightBlue);
        ofSetLineWidth(1);
        for (int i = 0; i < ofGetWidth(); i = i + 20){
            ofLine(i,0,i, ofGetHeight());
            }
    
        for (int i = 0; i < ofGetHeight(); i = i + 20){
            ofLine(0, i, ofGetWidth(), i);
            }
    

    
    for (int k = 0; k < 10; k ++) {
        for (int j = 0; j < 700; j ++) {
            
            ofSetColor(255);
            
            CompyFlip.draw((j*500)-900,500*k,300,304);
            
            Mate.draw((j*500)-750,600*k+300,245/1.7,450/1.7);
            
            if (j % 2 == 0){
                ofSetColor(192,223,228);
                cloud.draw((70*ofGetElapsedTimef())+(j*500)-1000,600*k,214,91);
            } else {
                ofSetColor(192,223,228);
                cloud.draw((70*ofGetElapsedTimef())+(j*500)-1000,600*k+300,214,91);
                ofSetColor(255);
                
            }
        }
    }
    
    ofSetHexColor(0xffffff);
    
    grayImage.draw(400, 200,400,400);
    
    IplImage* eig = cvCreateImage( cvGetSize(grayImage.getCvImage()), 32, 1 );
    IplImage* temp = cvCreateImage( cvGetSize(grayImage.getCvImage()), 32, 1 );
    
    cvReleaseImage( &eig );
    cvReleaseImage( &temp );
    
    grayImage.draw(400, 200,400,400);
    
    
    for (int i=400; i<grayImage.width; i++){
        for (int j=200; j< grayImage.height; j++){
            float brightness = myColor.getBrightness(); // get the brightness of the color
            float length = ofMap(brightness,0,255,1,12);
            if (brightness >=0 && brightness < 40){
                colorvar = ofColor :: darkTurquoise;
            } else if (brightness >= 40 && brightness < 69 ){
                colorvar = ofColor :: cornflowerBlue;
            } else if (brightness >= 69 && brightness <= 70 ){
                colorvar = ofColor :: coral;
            } else if (brightness > 70 && brightness <=120){
                colorvar = ofColor :: aqua;
            } else if (brightness > 120 && brightness <=200){
                colorvar = ofColor :: cyan;
            } else if (brightness > 200 && brightness <215){
                colorvar = ofColor :: lawnGreen;
            } else if (brightness > 215 && brightness <255){
                colorvar = ofColor :: yellow;
            } else if (brightness == 255){
                colorvar = ofColor :: pink;
                
            }
        }
    }



    ofSetColor(255);
    Nav.draw(0,0,ofGetWidth(), ofGetHeight());


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
