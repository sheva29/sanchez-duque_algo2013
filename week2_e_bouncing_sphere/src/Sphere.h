#pragma once
#include"ofMain.h"


class Sphere {  
    public:
    
    Sphere();
    
    void draw();
    void update();
    
    ofVec3f pos;
    
    float cubeSize;
    
    float velX, velY, velZ;
    
  
    private:
};