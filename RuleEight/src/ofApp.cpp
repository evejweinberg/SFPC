#include "ofApp.h"

void ofApp::drawAnalyze(float xPos, float yPos, float scale){
    
    RuleEightAnalyze.draw(0,0,ofGetWidth(),ofGetHeight());
    
}

//--------------------------------------------------------------
void ofApp::setup(){
    atthesametimebrown.loadImage("atthesametimebrown.png");
    DontTrybrown.loadImage("DontTrybrown.png");
    RuleEightAnalyze.loadImage("RuleEightAnalyze.png");
    theyareblue.loadImage("theyareblue.png");
    theyaretan.loadImage("theyaretan.png");
    salmon.setHsb(0,140,224);
    tan.setHsb(30,58,234); // (x/360*255, x/100*255, x/100*255)
    brown.setHsb(30,96,63);
    sprintf(RuleEightCreate, "CREATE");
    IntroBlack.loadFont("Intro Black.otf", 187); //font size
    
    


}

//--------------------------------------------------------------
void ofApp::update(){
    RuleEightAnalyze.update();
   

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
//    drawAnalyze(0,0,1);
    ofSetColor(salmon);
    IntroBlack.drawString(RuleEightCreate, 205,485);
    ofSetColor(brown);
    atthesametimebrown.draw(490,729-50,543,79);
    DontTrybrown.draw(505,27+50,435,116);
    ofSetColor(0);
    theyaretan.draw(0,245,100,317);
    ofSetColor(tan);
    float shake = ofNoise(200, 0);
    ofRect(0,0,105+shake,ofGetHeight());
    
    theyareblue.draw(0,245,100,317);
    
 //---------this is the mesh to reveal the analyze artwork------------

    cout <<  fabs(ofGetWidth()/2 - mouseX)  << endl;
    
    fromcenterdistance = (fabs(ofGetWidth()/2 - mouseX))/2;

    
    if (mouseX<ofGetWidth()/2){
        leftYTarget = mouseY + fromcenterdistance;
        rightYTarget = mouseY - fromcenterdistance;
    }
    if (mouseX>ofGetWidth()/2){
        rightYTarget = mouseY + fromcenterdistance;
        leftYTarget = mouseY - fromcenterdistance;

    }
    
    RuleEightLeftVertex = 0.95 * RuleEightLeftVertex + 0.05 * (mouseY-100);
    RuleEightRightVertex = 0.95 * RuleEightLeftVertex + 0.05 * (mouseY);
    
    
    ofMesh tempMesh;
    tempMesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    
    tempMesh.addVertex( ofPoint(0, RuleEightLeftVertex+leftYTarget));
    tempMesh.addTexCoord(ofVec2f(0, RuleEightLeftVertex+leftYTarget));
    tempMesh.addColor(255);
    
    tempMesh.addVertex( ofPoint(ofGetWidth(),RuleEightRightVertex+rightYTarget));
    tempMesh.addTexCoord(ofVec2f(ofGetWidth(),RuleEightRightVertex+rightYTarget));
    tempMesh.addColor(255);
    
    tempMesh.addVertex( ofPoint(0,ofGetHeight()));
    tempMesh.addTexCoord(ofVec2f(0, ofGetHeight()));

    tempMesh.addColor(255);
    
    tempMesh.addVertex( ofPoint(ofGetWidth(),ofGetHeight()));
    tempMesh.addTexCoord(ofVec2f(ofGetWidth(), ofGetHeight()));

    tempMesh.addColor(255);
    
    RuleEightAnalyze.bind();
    ofSetColor(255);
    tempMesh.draw();
    RuleEightAnalyze.unbind();
 
    

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
