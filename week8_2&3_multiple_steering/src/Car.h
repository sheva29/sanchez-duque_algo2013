//
//  Car.h
//  week8_multiple_steering
//
//  Created by Mauricio Sanchez Duque on 10/27/13.
//
//

#pragma once
#include "ofMain.h"

class Car{
    
public:
    
    Car( ofVec2f _pos, ofVec2f _vel, ofColor _color);
    
    void draw();
    void update();
   
    void applyForce( ofVec2f force );
    void addRepulsionForce( const ofVec2f &fromPos);
    void seek( ofVec2f dest);
    
    float maxSpeed, maxForce, slowDownRadius;
    
    ofVec2f pos, vel, accel, damping;
    
    ofColor color;

};
