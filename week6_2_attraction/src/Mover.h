//
//  Mover.h
//  week6_2_attraction
//
//  Created by Mauricio Sanchez Duque on 10/7/13.
//
//

#pragma once
#include "ofMain.h"


class Mover {
    
public:
    
    Mover();
    
    void applyForce( ofVec2f force);
    
    void update();
    void draw();
    
    ofVec2f pos, vel, acc;
    
    float mass;
  
    
    ofColor h;
    
    static const float G = 1.0;
    
    
private:
    
    
};
