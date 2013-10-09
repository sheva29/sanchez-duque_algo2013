//
//  Nucleus.h
//  week6_2_attraction
//
//  Created by Mauricio Sanchez Duque on 10/8/13.
//
//

#pragma once
#include "ofMain.h"
#include "Mover.h"

class Nucleus {
    
public:
    
    Nucleus();
    void draw();
    void update();
    void applyForce(ofVec2f force);
    
    ofVec2f attract ( Mover p);
    
    ofVec2f pos ,vel,  acc;
    float mass;
    ofColor red;
    
    static const float G = 1.0;
    
    vector < Mover > particles;
    
    int numberOfProtons;
    
    

    
private:   
    
};
