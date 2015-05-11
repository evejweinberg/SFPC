#include "ofApp.h"

//-----------------HI------------------------------------------------------

void ofApp::drawHI(float xPos, float yPos, float scale){
    
    ofPushMatrix(); // we're going to push this thing
    ofTranslate(xPos, yPos); // push it this far. Why is this a variable and not a fixed number?
    ofScale(scale, scale); //scale it this much
    ofNoFill();
    ofSetColor(myOutlines);
    ofSetLineWidth(MyOutlineWidth);
    
    //-----------------h------------------------
    ofBeginShape();
    ofVertex(0,0);
    ofVertex(30, 0);
    ofVertex(30+(Mousereact/2.5),40);
    ofVertex(70+(Mousereact/2.5),40);
    ofVertex(70,0);
    ofVertex(100,0);
    ofVertex(100+Mousereact,100); // moved Mousereact parameters to update. Was this a good idea?
    ofVertex(70+Mousereact,100);
    ofVertex(70+(Mousereact/2),60);
    ofVertex(30+(Mousereact/2),60);
    ofVertex(30+Mousereact,100);
    ofVertex(0+Mousereact,100);
    ofVertex(0,0);
    ofEndShape();
    
    ofPushMatrix();
    ofTranslate(110, 0);
    ofBeginShape();
    ofVertex(0,0);
    ofVertex(30, 0);
    ofVertex(30+Mousereact,100);
    ofVertex(0+Mousereact,100);
    ofVertex(0,0);
    ofEndShape();
    ofPopMatrix();
    ofPopMatrix();
}

// ------------------- draw a circle with pink polka dots inside
void ofApp::drawaPolkaDotO(float xPos, float yPos, float scale){
    
    ofPushMatrix(); // we're going to push this thing
    ofTranslate(xPos, yPos); // push it this far. Why is this a variable and not a fixed number?
    ofScale(scale, scale); //scale it this much
    float CircCenterBX, CircCenterBY, CircRadius;
    CircCenterBX = 0;
    CircCenterBY = 0;
    CircRadius = 100; // why am i defining this here?
    ofSetColor(myOutlines);
    ofNoFill();
    ofSetLineWidth(6);
    ofCircle(CircCenterBX,CircCenterBY,CircRadius); // centerx, centery, radius - this is drawing the black outline to be at 0,0,100 radius
    ofSetColor(yellow); //now i'm doing the polka dots
    ofFill();
    float circleX = CircCenterBY;
    float circleY = CircCenterBX;
    float circleRadius = CircRadius;
    for (int i = -circleRadius; i < circleRadius; i = i + 20)
    { //scoot it over 20 each time
        for (int k = -circleRadius; k < circleRadius; k = k + 20)
        { //scoot it over 20 each time
            float distance = ofDist(CircCenterBX, CircCenterBY, i, k);
            if (distance < circleRadius-4){
                if ((k/20) % 2 == 0) {     // is k even or not ?
                    ofCircle(k,i,4);
                } else {
                    ofCircle(k,i + 10,4);
                }
            }
        }
    }
    
    ofPopMatrix(); //now we're done, reset coordinates to normal
    
}

//--------------------------------------------------------------
void ofApp::setup(){
    
    Consider.loadImage("Consider.png");
    Everything.loadImage("Everything.png");
    tobe.loadImage("tobe.png");
    an.loadImage("an.png");
    Experiment.loadImage("Experiment.png");
    
//    for (int i = 0; i < 2; i++){
//        LT[i].loadimage("RuleFour_LikeThis"(i) + ".png");
//    }
    
    LT1.loadImage("RuleFOur_LikeThis1.png");
    
    colors[0].set(224,103,99); //coral
    colors[1].set(140,207,160); //green
    colors[2].set(98,196,215); //teal
    colors[3].set(243,167,153); //salmon
    colors[4].set(236,214,95); //yellow
    colors[5].set(150,107,138); //purple
    colors[6].set(91,116,183); //drkblue
    colors[7].set(148,114,101); // lightbrown
    colors[8].set(200,221,109); //lime
    
    imggrad.allocate(800 ,800,OF_IMAGE_COLOR);
    drawGradient();
    
    ofSetLineWidth(2);
    last = ofGetElapsedTimeMillis();
    col.setHsb(0,255,255);
    yellow.setHex(0xF9FF4B);
    Myradius=10;

}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetFrameRate(60);
    ofSetCircleResolution(50);
    //    Tweenzor::update(ofGetElapsedTimeMillis());
    
    float skewFactor = .1;
    Mousereact = ((ofGetWidth()/2) - mouseX) * skewFactor;
    ofMap(mouseX, 0, ofGetWidth(), -5, 5);   // true = stay in range of 0-1 // float value, float inputMin, float inputMax, float outputMin, float outputMax)


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
    
    ofFill();
    ofSetColor(MedAqua);
    if (ofGetElapsedTimef() <= 10){
        ofTriangle(10*ofGetElapsedTimef(),100,10*ofGetElapsedTimef()+50,150,10*ofGetElapsedTimef(),200);
    }
    
  
    //-----------mesh------square--------slowly---------dropping-----------------------------------------------------
    ofPushMatrix();
    //  ofRotate(2*ofGetElapsedTimef());
    ofTranslate(-200, -600+2*ofGetElapsedTimef());
    ofScale(7,7);
    
    ofMesh tempMesh;
    tempMesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    
    tempMesh.addVertex( ofPoint(100,100));
    tempMesh.addColor(Gold);
    
    tempMesh.addVertex( ofPoint(200,100));
    tempMesh.addColor(Gold);
    
    tempMesh.addVertex( ofPoint(100,200));
    tempMesh.addColor(Aqua);
    
    tempMesh.addVertex( ofPoint(200,200));
    tempMesh.addColor(Aqua);
    
    tempMesh.draw();
    ofPopMatrix();

    //-----------------------bg ball drops----------------------------------------------------------------------
    ofSetColor(col);
    if(ofGetElapsedTimeMillis() - last > 50)
        col.setHue(counter % 256); // what does the division sign do?
    counter ++;
    last = ofGetElapsedTimeMillis();
    ofFill();
    float rando = ofRandom(0, 100); // random number from 0 to 100
    
    for (int l = 0; l<30; l++) {
        for (int m = 0; m<10; m++) {
            ofCircle(500*m,-1000+20*ofGetElapsedTimef()+(l*500),Myradius*2);
        }
    }
    
    for (int n = 0; n<30; n++) {
        for (int nb = 0; nb<10; nb++) {
            ofCircle(250+500*nb,-250+20*ofGetElapsedTimef()+(n*500),Myradius);
        }
    }

    ofPushMatrix();
    ofTranslate(400, 200);
    drawaPolkaDotO(750, 50, 0.5);
    drawHI(270, 00, 1);
    
    ofPopMatrix();

    ofSetColor(ofRandom(0,100),ofRandom(0,140), ofRandom(0,190));
    Consider.draw(100,100,200,78);
    Everything.draw(200, 300, 205,90);
    tobe.draw(400,500,140,70);
    an.draw(600,600,70,40);
    Experiment.draw(800,700,210,80);
         
    
    
}

// -----------------------------------------what is this?
void ofApp::drawGradient() {
    for (int x=0; x<200; x++) {
        for (int y=0; y<300; y++) {
            imggrad.setColor(x, y, ofColor::fromHsb(255, y, 255));
        }
    }
    imggrad.update();
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key==119) // 'w' key
    {
        Myradius--;
    }
    
    if(key=='a')
    {
        Myradius++;
    }
    if(key=='m')
    {
    
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
