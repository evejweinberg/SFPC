#include "ofApp.h"

static string voices[24] = {"Agnes", "Albert", "Alex", "Bad News", "Bahh", "Bells", "Boing", "Bruce", "Bubbles", "Cellos", "Deranged", "Fred", "Good News", "Hysterical", "Junior", "Kathy", "Pipe Organ", "Princess", "Ralph", "Trinoids", "Vicki", "Victoria", "Whisper", "Zarvox"};

//--------------------------------------------------------------
void ofApp::setup(){
    
    IntroBlack.loadFont("Intro Black.otf", 32); //font size
//    ofBackgroundHex(0xff72a1);
    ofSetFrameRate(12);
    
    nextLetterTime = ofGetElapsedTimef();
    lineCount      = 0;
    letterCount    = 0;
    
    // this is our buffer to stroe the text data
    ofBuffer buffer = ofBufferFromFile("Nothing.txt");
    
    if(buffer.size()) {
        
        // we now keep grabbing the next line
        // until we reach the end of the file
        while(buffer.isLastLine() == false) {
            
            // move on to the next line
            string line = buffer.getNextLine();
            
            // copy the line to draw later
            // make sure its not a empty line
            if(line.empty() == false) {
                seussLines.push_back(line);
            }
            
            // print out the line
            cout << line << endl;
            
        }
        
    }
    
    voice = "Agnes";
    bRandomVoice = false;
    
    // load the lyrics from a text file and split them
    // up in to a vector of strings
    string lyrics = ofBufferFromFile("Nothing.txt").getText();
    step = 0;
    words = ofSplitString(lyrics, " ");
    
    // we are running the systems commands
    // in a sperate thread so that it does
    // not block the drawing
    startThread();



}

//--------------------------------------------------------------
void ofApp::threadedFunction() {
    
    while (isThreadRunning()) {
        
        
        // call the system command say
        
#ifdef TARGET_OSX
        string cmd = "say -v "+voice+" "+words[step]+" ";   // create the command
        system(cmd.c_str());
#endif
#ifdef TARGET_WIN32
        string cmd = "data\\SayStatic.exe "+words[step];   // create the command
        cout << cmd << endl;
        system(cmd.c_str());
#endif
        
        
        
        // step to the next word
        step ++;
        step %= words.size();
        
        // slowdown boy
        ofSleepMillis(10);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // get a random voice
    if(bRandomVoice) {
        voice = voices[(int)ofRandom(24)];
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

    
    int strWidth = (seussLines[lineCount].length()*25) ;
    // x and y for the drawing
    float x = (ofGetWidth()-strWidth)/2;
    float y = ofGetHeight()/2;
  
    // we are slowy grabbing part of the line
    string typedLine = seussLines[lineCount].substr(0, letterCount);
    
    ofSetColor(243,167,153);
    ofRect(x-10, y-30, strWidth, 55);
    ofSetColor(255);
    IntroBlack.drawString(typedLine, x+4, y+11);
    
    
    // this is our timer for grabbing the next letter
    float time = ofGetElapsedTimeMillis() - nextLetterTime;
    
    if(time > 9) {
        
        // increment the letter count until
        // we reach the end of the line
        if(letterCount < (int)seussLines[lineCount].size()) {
            
            // move on to the next letter
            letterCount ++;
            
            // store time for next letter type
            nextLetterTime = ofGetElapsedTimeMillis();
            
        }
        else {
            
            // wait just a flash then move on
            // to the next line...
            if(time > 300) {
                
                nextLetterTime = ofGetElapsedTimeMillis();
                letterCount = 0;
                lineCount ++;
                lineCount %= seussLines.size();
            }
            
        }
    }


}

//--------------------------------------------------------------
void ofApp::exit() {
    // stop the thread on exit
    waitForThread(true);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == 'r') {
        bRandomVoice = !bRandomVoice;
    }
    
    if(key == ' ') {
        voice = voices[(int)ofRandom(24)];
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
