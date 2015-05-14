#include "ofApp.h"
#include "ofxImageSequence.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    type.loadImage("Rule9_type.png");
    Nav.loadImage("Nav.png");
    frame.loadImage("frame.png");
    Mate.loadImage("Mate.png");
    CompyFlip.loadMovie("CompyFlipBW.mov");
    CompyFlip.setLoopState(OF_LOOP_NORMAL);
    CompyFlip.play();
    
    videoGrabber.initGrabber(320, 240);
    
    colorImg.allocate(videoGrabber.width, videoGrabber.height);
    grayImage.allocate(videoGrabber.width, videoGrabber.height);
    CompyImages.loadSequence("CompyAlpha/CompyAlpha_", "png", 0, 33, 5);
    CompyImages.preloadAllFrames();

    allClouds.resize(10);
    for (int i = 0; i < allClouds.size(); i++) {
        allClouds[i].pos = ofPoint(i*500,i*500); //first time we call the balls
    }
 
}

//--------------------------------------------------------------
void ofApp::update(){
    

    CompyFlip.update();
    for (int i = 0; i < allClouds.size(); i++) {
        allClouds[i].update();
        
    }

    
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

    

    
    ////BG------white paper with light blue gridded lines--------------------
        ofBackground(255);
        ofSetColor( ofColor::lightBlue);
        ofSetLineWidth(1);
        for (int i = 0; i < ofGetWidth(); i = i + 20){
            ofLine(i,0,i, ofGetHeight());
            }
    
        for (int i = 0; i < ofGetHeight(); i = i + 20){
            ofLine(0, i, ofGetWidth(), i);
            }
    
    ofSetColor(255);
    frame.draw(380,220);
    ofSetColor(73,66,54);
    type.draw(500,105);

  

    
    for (int k = 0; k < 2; k ++) {
        for (int j = 0; j < 5; j ++) {
            
           ofSetColor(255);
            CompyImages.getFrameForTime(ofGetElapsedTimef())->draw((j*800)-680,630*k-20,270,271); //the frame and the current frame
            ofPushMatrix();
            ofPushStyle();
            ofRectMode(OF_RECTMODE_CENTER);
            ofRotate(50*TWO_PI*ofGetElapsedTimef());
            Mate.draw(j*400,k*400+250,245/2,450/2); //about to switch him into his own class
            ofPopMatrix();
            ofPopStyle();
            
            }
        }
    
    


    ofSetColor(200, 200, 200);
    int videowidth = 630;
    int videoheight = 342;
    grayImage.draw(400, 240,videowidth,videoheight);
    
    IplImage* eig = cvCreateImage( cvGetSize(grayImage.getCvImage()), 32, 1 );
    IplImage* temp = cvCreateImage( cvGetSize(grayImage.getCvImage()), 32, 1 );
    
    cvReleaseImage( &eig );
    cvReleaseImage( &temp );
    
    grayImage.draw(400, 240,videowidth,videoheight);
    
    //id like to tint the video but not sure how
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

    for (int i = 0; i < allClouds.size(); i++) { //drawing all the balls, every frame
        allClouds[i].draw();
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
