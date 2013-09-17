#pragma once
#include "ofMain.h"

class Ball{

public:

    Ball();
  
    void draw();
    void update();
    
    
    ofVec2f pos;
    float ballSize;
    
};
