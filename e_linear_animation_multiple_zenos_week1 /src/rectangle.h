//
//  rectangle.h
//  linear_animation
//
//  Created by Mauricio Sanchez Duque on 8/27/13.
//
//

#pragma once

#include "ofMain.h"
#define NUM_RECTS 30
#define COLOR_RANGE 255


class Rectangle {

    //Allows people to use this variable in other classes
public:
    
    Rectangle();
    
    void update();
    void draw();
    void setup();
    
    
    
    void zenoToPoint( float catchX, float catchY );
    
    ofPoint pos;    
    //Allows to move the rectangle from one position to the other one. Use comas to have several variables in one object.
    
    float rectSize[NUM_RECTS];
    float colorR[COLOR_RANGE];
    float colorG[COLOR_RANGE];
    float colorB[COLOR_RANGE];
    
    float catchUpSpeed[NUM_RECTS];
 
    
 
    
};
 