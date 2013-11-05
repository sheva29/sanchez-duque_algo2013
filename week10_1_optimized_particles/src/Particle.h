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
    
    float hue;
};
