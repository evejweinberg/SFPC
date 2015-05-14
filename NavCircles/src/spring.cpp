#include "spring.h"

//---------------------------------------------------------------------
spring::spring(){
	particleA = NULL;
	particleB = NULL;
}

//---------------------------------------------------------------------
void spring::update(){
	if ((particleA == NULL) || (particleB == NULL)){ //what do double pipes mean
		return;
	}
	
	ofVec2f pta = particleA->pos; //stores a 2 dimentional vector
	ofVec2f ptb = particleB->pos;
	
	float theirDistance = (pta - ptb).length(); //find the length of the fistance from pta to ptb
	float springForce = (springiness * (distance - theirDistance));
	ofVec2f frcToAdd = (pta-ptb).normalized() * springForce;
	
	particleA->addForce(frcToAdd.x, frcToAdd.y);
	particleB->addForce(-frcToAdd.x, -frcToAdd.y);
}


//---------------------------------------------------------------------
void spring::draw(){
	
    if ((particleA == NULL) || (particleB == NULL)){ //what do double pipes mean
		return;
	}
	
	ofLine(particleA->pos.x, particleA->pos.y, particleB->pos.x, particleB->pos.y); //if...draw a line, no balls are drawn here
}