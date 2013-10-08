//
//  Particle.h
//  week6_1_forces_solitaire_effect
//
//  Created by Mauricio Sanchez Duque on 10/6/13.
//
//

#pragma once
#include "ofMain.h"

class Particle {
    
public:
    
    Particle( ofVec2f position );
    ofVec2f pos, vel, acc;
    
    float mass, _size;
    
    void applyForce( ofVec2f force);
    void update();
    void draw();
    
    ofColor particleColor;
    float h, s, b, a;

    
    
};
