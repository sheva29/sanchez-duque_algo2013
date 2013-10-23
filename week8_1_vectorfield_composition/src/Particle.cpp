//
//  Particle.cpp
//  week8_1_vectorfield_composition
//
//  Created by Mauricio Sanchez Duque on 10/22/13.
//
//

#include "Particle.h"


Particle::Particle(){
    
    mass = .5;
    
    damping = ofRandom( 0.9999998, 0.98);
    
}

void Particle::applyForce( ofVec2f force){
    
    acc += ( force / mass);
    ;
}

void Particle::update(){
    
    vel += ( acc * 0.05);
    pos += vel;
    
    //We want the speed to start slowing down fradually
    vel *= damping;
    
    acc.set(0);
    
    
}

void Particle::draw(){
    
    
    ofSetColor( (ofRandom(255)), (ofRandom(255)), ofRandom(255));
    ofCircle( pos, mass * 3);
    
    
}