#pragma once
#include "ofMain.h"

class Particle {
    
public:
    
    Particle();
    
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f acc;
    ofVec2f dir;
    float mass;
    float massCoe;
    float damping;
    float xStreching, yStreching;
    
    void applyForce( ofVec2f force);
    void update();
    void draw();
    
    ofColor c;
    
    float hue;
};
