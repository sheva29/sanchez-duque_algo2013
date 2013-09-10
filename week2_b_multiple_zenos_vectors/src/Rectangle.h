#pragma once 

#include "ofMain.h"

class Rectangle {
  public:
    Rectangle();
    
    void xenoToPoint(ofVec2f _mousePos, float _accelCoe);
    void draw();
    
    ofVec2f pos, mousePos;
    ofVec2f accel, velocity;
    
    
};