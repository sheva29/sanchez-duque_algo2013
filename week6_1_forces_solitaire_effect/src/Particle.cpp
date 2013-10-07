//
//  Particle.cpp
//  week6_1_forces_solitaire_effect
//
//  Created by Mauricio Sanchez Duque on 10/6/13.
//
//

#include "Particle.h"



Particle::Particle( ofVec2f position){
    
    pos = position;
    mass = 1.0;
    _size = ofRandom(5,20);
    h = ofRandom( 0, 255);
    s = ofRandom( 0, 255);
    b = ofRandom( 0, 255);
    a = ofRandom( 0, 100);
    
    particleColor.setHsb(h, s, b, a );
    ofSetColor(particleColor);
    
}

void Particle::applyForce(ofVec2f force){
    
    acc += ( force/ mass);
    
}

void Particle::update(){
    
    vel += acc;
    pos += vel;
    
    if ( pos.x < 0 || pos.x > ofGetWindowWidth()){
        
        vel.x = -vel.x;
    }
    
    if( pos.y < 0 || pos.y > ofGetWindowHeight()){
        
        vel.y = -vel.y;
    }
    
    acc.set(0);
}


void Particle::draw(){
    
   
//    ofSetColor(h);
    
    ofCircle( pos, _size);
    
}