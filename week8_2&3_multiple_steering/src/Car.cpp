//
//  Car.cpp
//  week8_multiple_steering
//
//  Created by Mauricio Sanchez Duque on 10/27/13.
//
//

#include "Car.h"


Car::Car( ofVec2f _pos, ofVec2f _vel, ofColor _color){
    
    pos.set( _pos);
    vel.set( _vel);
    color.set(_color);
    
    damping = ofVec2f( 0.01f);
    
    maxSpeed = 10.0;
    maxForce = 0.4;
    
    slowDownRadius = 50.0;
    
}


void Car:: applyForce(ofVec2f force){
    
    accel += force;
    accel.limit(5.0);
    
}
void Car::update(){
    
    vel += accel;
    pos += vel;
    
    vel *= 0.97;
    
    accel.set( 0);
    
    
}


void Car::addRepulsionForce(const ofVec2f &fromPos){
    
    ofVec2f diff = pos - fromPos;
    
    float strength = 1 -( diff.length() / 200);
    
    applyForce( diff.normalize() * strength);
    
}


void Car::seek( ofVec2f dest){
    
    ofVec2f desired = dest - pos;
    
    ofVec2f steer = desired - vel;
    
    steer.limit(maxForce);
    
    applyForce( steer);
}

void Car::draw(){
    
    ofPushMatrix();{
        ofSetRectMode(OF_RECTMODE_CENTER);
        
        ofTranslate(pos);
        float rotAmt = atan2( vel.y, vel.x);
        ofRotate( ofRadToDeg(rotAmt) + 90);
        ofRect( 0,0, 20,40 );
        
    }ofPopMatrix();
    
    
}