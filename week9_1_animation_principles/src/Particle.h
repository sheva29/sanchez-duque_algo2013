//
//  Particle.h
//  week9_1_animation_principles
//
//  Created by Mauricio Sanchez Duque on 10/28/13.
//
//

#pragma once
#include "ofMain.h"


class Particle {
    
public:
    
    Particle();
    
    void draw();
    void update();
    
    void applyForce(ofVec2f &force);
    
    ofVec2f pos, vel, acc;
    
    float mass, damping, coe, yStreching, xStreching;
    
    ofColor c;
    
    
};
