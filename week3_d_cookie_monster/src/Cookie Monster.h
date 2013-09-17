#pragma once
#include "ofMain.h"

class cookieMonster {
  
public:
    
    cookieMonster();
    
    void draw();
    void zenoToCookie(ofVec2f _mousePos, float _accelCoe);
    
    ofVec2f vel, acce, pos, mousePos;
    
    ofImage _cookieMonster;
    

    
    
    
};
