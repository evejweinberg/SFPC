#include "ofApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void ofApp::setup(){
    salmon.setHsb(0,140,224);
    tan.setHsb(30,58,234); // (x/360*255, x/100*255, x/100*255)
    brown.setHsb(30,96,63);
    yellow.setHsb(34,150,234);
    green.setHsb(49,127,219);
    royal.setHsb(157,127,181);
    blue.setHsb(133,138,214);
    pink.setHsb(4,43,237);
    sprintf(WORK, "WORK");
    IntroBlackLrg.loadFont("Intro Black.otf", 70); //font size
    sprintf(ThereisOnly, "THE ONLY RULE IS");
    IntroBlack.loadFont("Intro Black.otf", 50); //font size
  
    
    scribbles.loadMovie("ScribblesonWhite.mov");
    scribbles.setLoopState(OF_LOOP_NORMAL);
    scribbles.play();
    
    videoone.loadMovie("RuleSevenVideoOne.mov");
    videoone.setLoopState(OF_LOOP_NORMAL);
    videoone.play();
    
    videotwo.loadMovie("RuleSevenVideoTwo.mov");
    videotwo.setLoopState(OF_LOOP_NORMAL);
    videotwo.play();
    
    
    videothree.loadMovie("RuleSevenVideoThree.mov");
    videothree.setLoopState(OF_LOOP_NORMAL);
    videothree.play();
    
    videofour.loadMovie("RuleSevenVideoFour.mov");
    videofour.setLoopState(OF_LOOP_NORMAL);
    videofour.play();
    
    videofive.loadMovie("RuleSevenVideoFive.mov");
    videofive.setLoopState(OF_LOOP_NORMAL);
    videofive.play();
    
    videosix.loadMovie("RuleSevenVideoSix.mov");
    videosix.setLoopState(OF_LOOP_NORMAL);
    videosix.play();

    
    allofthetime.loadImage("allofthetime.png");
    arrow.loadImage("arrow.png");
    RuleSevenBG.loadImage("RuleSevenBG.png");
    ifyouwork.loadImage("ifyouwork.png");
    itwilllead.loadImage("itwilllead.png");
    itspeople.loadImage("itspeople.png");
    tosomething.loadImage("toSomething.png");
    whoeventually.loadImage("whoeventually2.png");
    
 



}

//--------------------------------------------------------------
void ofApp::update(){
    
    scribbles.update();
    videoone.update();
    videotwo.update();
    videothree.update();
    videofour.update();
    videofive.update();
    videosix.update();
    


}

//--------------------------------------------------------------
void ofApp::draw(){
    float iywmove = 10*ofGetElapsedTimef();
    ofSetColor(green);
    ofRect(30,110,350,200);
    ofSetColor(tan);
    ofRect(990,340,350,200);
    ofSetColor(blue);
    ofRect(690,560,340,200);
    ofSetColor(royal);
    ofRect(370,340,350,200);
    ofSetColor(salmon);
    ofRect(690,110,340,200);
    ofSetColor(pink);
    ofRect(30,560,340,200);
    
    ofSetColor(brown);
    ifyouwork.draw(64,160,627/2.5,177/2.5 );
    itwilllead.draw(780,140,221/2,305/2);
    allofthetime.draw(85,605,383/2,231/2);
    itspeople.draw(1035,345,530/2.2,392/2.2);
    tosomething.draw(410,365,368/2,270/2);
    whoeventually.draw(715,570,530/2.05,392/2.05);

    ofSetColor(255);
    videoone.draw(350,110,350,200); //illustrator
    videotwo.draw(350,750,350,200); //OF forum
    videothree.draw(680,340,350,200);
    videofour.draw(340,540,330,200);
    videofive.draw(40,340,330,200);
    videosix.draw(1000,110,330,200); //taeyoon Goldberg
    
//    cout >> pos[x] >> endl;
    
    ofSetColor(255);
    RuleSevenBG.draw(0,0,ofGetWidth(),ofGetHeight());
    

    
//    //-----------blob-------------------------
//    ofSetColor(255,0,127);
//    
//    ofBeginShape();
//    for (int i = 0; i < 100; i++){
//        
//        //float add = ofNoise(sin((i/100.0)*TWO_PI), ofGetElapsedTimef());  // symetrical
//        
//        float add = ofNoise(i/20.0f, ofGetElapsedTimef() * 3 * (float)mouseX / (float)ofGetWidth());
//        
//        ofVertex(	00 + (200 + 100 * add) * cos((i/100.0)*TWO_PI),
//                 100 + (200 + 100 * add) * sin((i/100.0)*TWO_PI));
//    }
//    
//    ofEndShape();

    
    // --------------------mesh circle that follows mouse---------------
    ofSetColor(255);
    ofMesh tempMesh;
    tempMesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
    float x = mouseX-PI;
    float y = mouseY-PI;
    float r = 200;
    
    float scale =  1; //ofMap( sin(ofGetElapsedTimef()), -1, 1, 0.4, 3);
    
//    tempMesh.addVertex( ofPoint(x,y));
//    tempMesh.addTexCoord(ofPoint(x,y) * scale+ ofPoint(mouseX, mouseY));
//    
//    
//    for (int i = 0; i < 100; i++){
//        
//        float angle = ofMap(i, 0, 100-1, 0, TWO_PI);
//        
//        ofPoint pos;
//        pos.x = x + r * cos(angle);
//        pos.y = y + r * sin(angle);
//        
//        tempMesh.addVertex(pos);
//        tempMesh.addTexCoord(pos);
//        
//    }
//    
//    scribbles.getTextureReference().bind();
//    tempMesh.draw();
//    scribbles.getTextureReference().unbind(); //bind this movie to the mesh
    
    
    
    ofPushMatrix();
    ofTranslate(-100,0);
    ofSetColor(brown);
    IntroBlack.drawString(ThereisOnly, mouseX-100,mouseY+25);
   
    IntroBlackLrg.drawString(WORK, mouseX+100,mouseY+100);
   
    ofPopMatrix();
    
    
    
    
    ofSetLineWidth(3);
    ofSetColor(255,0,0);
    TS.draw(videoone.getPosition());
    for (int i = 0; i < strokes.size(); i++){
        strokes[i].draw(videoone.getPosition());
    }
    
    ofPushMatrix();
    ofTranslate(0, 70);
//    ofDrawBitmapStringHighlight("press spacebar to clear", ofPoint(videoone.getWidth() + 250, 50), ofColor::magenta, ofColor::white);
    ofDrawBitmapStringHighlight("press + to increase video speed", ofPoint(videoone.getWidth() + 200, ofGetHeight()-160), ofColor::magenta, ofColor::white);
    ofDrawBitmapStringHighlight("press - to increase video speed", ofPoint(videoone.getWidth() + 200, ofGetHeight()-130), ofColor::magenta, ofColor::white);
    ofDrawBitmapStringHighlight("video speed: " + ofToString(videoone.getSpeed(), 3), ofPoint(videoone.getWidth() + 250, ofGetHeight()-100), ofColor::magenta, ofColor::white);
    
    ofPopMatrix();
    
   



}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == ' '){
        strokes.clear();
        TS.pts.clear();
    }
    
    
    if (key == '+'){
        videoone.setSpeed(videoone.getSpeed()+0.1);
        videotwo.setSpeed(videotwo.getSpeed()+0.1);
        videothree.setSpeed(videothree.getSpeed()+0.1);
        videofour.setSpeed(videofour.getSpeed()+0.1);
        videofive.setSpeed(videofive.getSpeed()+0.1);
        videosix.setSpeed(videofive.getSpeed()+0.1);
    }
    
    if (key == '-'){
        videoone.setSpeed(videoone.getSpeed()-0.1);
        videotwo.setSpeed(videotwo.getSpeed()-0.1);
        videothree.setSpeed(videothree.getSpeed()-0.1);
        videofour.setSpeed(videofour.getSpeed()-0.1);
        videofive.setSpeed(videofive.getSpeed()-0.1);
        videosix.setSpeed(videofive.getSpeed()-0.1);
    }

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
