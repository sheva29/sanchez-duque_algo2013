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
    
//    c.setHsb(ofRandom(255), 255, 255);
    
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
    
    //We create a new vector to store the direction
    
    ofVec2f prePos;
    
    //We get the length to store our vector in a float. O - 1
    prePos = vel.normalized();
    
    //I did this assuming that the length would give me the direction. But I realized this will give me a bigger number
    float angle = atan2( vel.x, vel.y);
    hue = ofMap( angle , -PI,PI, 0 , 255);
    
//    atan(vel.x / vel.x);
    
    
    
    
    
}

void Particle::draw(){
    
    
//    ofDrawBitmapString(ofToString(colorAngle), 20,20);
    c.setHsb(hue, 255, 255);
    ofSetColor(c);
//    ofSetColor( (ofRandom(255)), (ofRandom(255)), ofRandom(255));
    ofCircle( pos, mass * 3);
    
    
}