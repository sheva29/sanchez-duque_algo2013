//
//  Particle.h
//  week8_1_vectorfield_composition
//
//  Created by Mauricio Sanchez Duque on 10/22/13.
//
//

#pragma once
#include "ofMain.h"

class Particle {
    
public:
    
    Particle();
    
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f acc;
    float mass;
    float damping;
    
    void applyForce( ofVec2f force);
    void update();
    void draw();
    
    ofColor c;
};
