//
//  Particles.h
//  week5_1_GUI_particles_control
//
//  Created by Mauricio Sanchez Duque on 9/30/13.
//
//

#pragma once
#include "ofMain.h"


class Particles {
    
public:
    
    Particles( ofVec2f position);
    
    void draw();
    void update(ofImage img);
    
    
    float diagonal, tempSize, rectSize, rectSizeMax;
    
    ofColor pixelColor;
    
    ofVec2f pos;
    
    
    
    
    
    
private:
    
    
};
