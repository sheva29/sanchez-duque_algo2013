#pragma once

#include <csignal>
#include "ofMain.h"

class Circles{
    
public:
    
    Circles();
    
    void draw();
    void update();
    void calculateWave();
    void renderWave();
    
    int xSpacing;
    int w;
    int yValues_length;
    
    float theta;
    float amplitude;
    float period;
    float dx;
    float yValues[1000];
    
    int coeVariable;
    
};
