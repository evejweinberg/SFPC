#include "ofApp.h"

//-----------------HI------------------------------------------------------



void ofApp::drawaPolkaDotO(float xPos, float yPos, float scale){
    }

//--------------------------------------------------------------
void ofApp::setup(){
    
    ConsiderFull.loadImage("ConsiderFull.png");
    Everything.loadImage("Everything.png");
    tobe.loadImage("tobe.png");
    an.loadImage("an.png");
    Experiment.loadImage("Experiment.png");
    InstA.loadImage("Inst3.png");
    Nav.loadImage("Nav.png");
    
    colors[0].set(224,103,99); //coral
    colors[1].set(140,207,160); //green
    colors[2].set(98,196,215); //teal
    colors[3].set(243,167,153); //salmon
    colors[4].set(236,214,95); //yellow
    colors[5].set(150,107,138); //purple
    colors[6].set(91,116,183); //drkblue
    colors[7].set(148,114,101); // lightbrown
    colors[8].set(200,221,109); //lime
    

    
    string name;
    for (int i = 0; i < ARTWORKTOTAL; i++){
        name = "RuleFour_LikeThis" + ofToString(i) + ".png";
        LikeThis[i].loadImage(name);
        cout << name << endl;
        }
    
    allBallsDropping.resize(10);
    for (int i = 0; i < allBallsDropping.size(); i++) {
        allBallsDropping[i].artwork = &LikeThis[(int)ofRandom(ARTWORKTOTAL)]; //choose random artwork, from the pointer in the balldrop header. The ball has a pointer to an image in the LikeThisArray
        allBallsDropping[i].col = colors[(int)ofRandom(9)]; //grabbing the colors
        allBallsDropping[i].pos = ofPoint(ofRandom(0,ofGetWidth()),ofRandom(0, ofGetHeight())); //first time we call the balls
    }

    Myradius=1.0;

}

//--------------------------------------------------------------
void ofApp::update(){

    ofSetCircleResolution(50);

    
    for (int i = 0; i < allBallsDropping.size(); i++) {
        allBallsDropping[i].update();
        allBallsDropping[i].radius = Myradius;
        

    }


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
    

    //-----------------------bg ball drops----------------------------------------------------------------------

     ofSetColor(255);
     InstA.draw(545,317);
    
    for (int i = 0; i < allBallsDropping.size(); i++) { //drawing all the balls, every frame
        allBallsDropping[i].draw();
    }
    
    ofSetColor(73,66,54); //brown
    ConsiderFull.draw(320,100);


    ofSetColor(255);
   
    
    Nav.draw(0,0);
    
}


void ofApp::drawGradient() {

}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key=='s') 
    {
        
        Myradius -= 0.1; //Myradius is defined in header, instantiated in setup to 1
       
        
            }
    
    if(key=='l')
    {
        
        Myradius += 0.1;

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
    
    for (int i = 0; i < allBallsDropping.size(); i++) {
        if(allBallsDropping[i].mousePressed(x, y, button)) {
            
            BallDrop ball; //instantiating a new variable 'ba'' of the type 'balldrop'

            ball.artwork = &LikeThis[(int)ofRandom(ARTWORKTOTAL)];
            ball.col = colors[(int)ofRandom(9)];
            
            ball.pos.set(ofRandom(0,ofGetWidth()), ofRandom(-ball.radius, -ball.radius*10)); //also draw a new ball up top
            
            allBallsDropping.push_back(ball); //add it to the vector of all the balls, push a new element into the vector from the back of it

            
        }
    }
    

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
