#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    Nav.loadImage("Nav.png");
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    
    colors[0].set(224,103,99); //coral
    colors[1].set(140,207,160); //green
    colors[2].set(98,196,215); //teal
    colors[3].set(243,167,153); //salmon
    colors[4].set(236,214,95); //yellow
    colors[5].set(150,107,138); //purple
    colors[6].set(91,116,183); //drkblue
    colors[7].set(224,103,99); //coral
    colors[8].set(140,207,160); //green
    colors[9].set(202,222,111); //lime
    colors[10].set(148,114,101); //lightbroen
    colors[11].set(75,65,42); //drk brown

    

    
    for (int i = 0; i < 250; i++){
        particle myParticle;
      
        myParticle.setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
       
        particles.push_back(myParticle);
    }
    
    bPressed = false;
    
    NF.setup();
    NF.scaleOfField = 0.01;
    Be.loadImage("Rule5_Be.png");
    tobe.loadImage("Rule5_tobe.png");
    FollowMe.loadImage("Rule5_FollowMe.png");
    
    Artw = 198;
    Arth = 46;
    pos.set(300,300);
    vx = ofRandom(-6,6);
    vy = ofRandom(-6,6);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    NF.setTime(ofGetElapsedTimef()*0.1);
    //NF.scaleOfField = ofMap(mouseX, 0,ofGetWidth(),0,0.01);
    
    // on every frame
    // we reset the forces
    // add in any forces on the particle
    // perfom damping and
    // then update
    
    for (int i = 0; i < particles.size(); i++){
        particles[i].resetForce();
    }
    
    
    for (int i = 0; i < particles.size(); i++){
        for (int j = 0; j < i; j++){
            if (!bPressed){
                particles[i].addRepulsionForce(particles[j], 30,1.5);
            } else {
                particles[i].addRepulsionForce(particles[j], 30,0.3);
            }
        }
        
        if (bPressed){
            //particles[i].addAttractionForce(mouseX, mouseY, 2000,0.1);
            ofVec2f frcFromNoise = NF.getNoiseForPosition(particles[i].pos.x, particles[i].pos.y,0.32);
            particles[i].addForce(frcFromNoise.x, frcFromNoise.y);
        } else {
            particles[i].addAttractionForce(mouseX, mouseY, 2000,0.5);
            
        }
    }
    
    for (int i = 0; i < particles.size(); i++){
        particles[i].addDampingForce();
        particles[i].update();
    }
    
    
    
//-------------bounce off the wallls
    
    
    pos.x += vx; // pos x equals pos x + vx
    pos.y += vy; // pox y = pox y + vy
    
    bool bHit = false;
    
    if (pos.x < 0){
        pos.x = 0;
        vx *= -1;
        bHit = true;
    } else if (pos.x > ofGetWidth()-Artw){
        pos.x = ofGetWidth()-Artw;
        vx *= -1;
        bHit = true;
    }
    
    if (pos.y < 0){
        pos.y = 0;
        vy *= -1;
        bHit = true;
    } else if (pos.y > ofGetHeight()-Arth){
        pos.y = ofGetHeight()-Arth;
        vy *= -1;
        bHit = true;
    }
    
//    if (bHit == true){
//        string command = "say ouch &";
//        system(command.c_str());
//    }

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
    

    
    ofSetColor(73,66,54);
    Be.draw(100,10,1189,119);
    tobe.draw(10,750,866,114);
    ofSetColor(255);
    
    
    ofEnableAlphaBlending();
  
    
    for (int i = 0; i < particles.size(); i++){
        ofSetColor(colors[i % 12]);
        particles[i].draw();

        }

    ofSetColor(255);
    FollowMe.draw(pos.x, pos.y, Artw,Arth);
    
        
    ofSetColor(255);
    Nav.draw(0,0,ofGetWidth(),ofGetHeight());
    

}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
    
    
    
}

//--------------------------------------------------------------
void ofApp::keyReleased  (int key){
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    particles.erase(particles.begin());
    particle myParticle;
    myParticle.setInitialCondition(x,y,0,0);
    particles.push_back(myParticle);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
//    bPressed = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(){
    
//    bPressed = false;
}
