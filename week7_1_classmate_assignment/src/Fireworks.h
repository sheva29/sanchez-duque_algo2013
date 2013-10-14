//
//  Fireworks.h
//  week7_1_classmate_assignment
//
//  Created by Mauricio Sanchez Duque on 10/13/13.
//
//

#pragma once
#include "ofMain.h"

class Fireworks{
    
public:
    
    void setup( ofVec3f _pos, float setVel, float hue);
    
    void update();
    void draw();
    
    bool kill();
    
    ofVec3f pos, vel, acc;
    float age, life, size;
    ofColor c;
    
    
    
    
};
