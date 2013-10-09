//
//  Mover.cpp
//  week6_2_attraction
//
//  Created by Mauricio Sanchez Duque on 10/7/13.
//
//

#include "Mover.h"


Mover::Mover(){
    
    //We initiate our variables
    mass = 1.0;
    h.setHsb(ofRandom(255), 255, 255);
    pos.set(ofRandom(ofGetWindowWidth()/2), ofRandom(ofGetWindowHeight()/2));
    vel = ofVec2f(0,3);
    mass = ofRandom(0 , 5);
    
}

void Mover::applyForce(ofVec2f force){
    
    acc +=( force / mass);
}

void Mover::update(){
    
    vel += acc;
    pos += vel;
    
    acc.set(0);
    
}


void Mover::draw(){
    
    ofSetColor(h);
    ofCircle(pos,mass*2);
  
    
}