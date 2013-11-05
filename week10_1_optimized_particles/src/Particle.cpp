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
    
        //I did this assuming that the length would give me the direction. But I realized this will give me a bigger number
    float angle = atan2(vel.x, vel.y);
    hue = ofMap( angle , 0 ,PI, 0 , 255);
    
    if( hue == 0){
        
        pos = ofVec2f( ofRandom( ofGetWindowWidth()), ofRandom( ofGetWindowHeight()));
    }
    
//    atan(vel.x / vel.x);    
    
    
}

void Particle::draw(){
    
    
//    ofDrawBitmapString(ofToString(colorAngle), 20,20);
    c.set(hue, 0, 0);
    ofSetColor(c);
//    ofSetColor( (ofRandom(255)), (ofRandom(255)), ofRandom(255));
    
    
    ofCircle( pos, mass * 2);
    
    
}