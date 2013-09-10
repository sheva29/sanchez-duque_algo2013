//
//  Rectangle.h
//  emptyExample
//
//  Created by Mauricio Sanchez Duque on 9/3/13.
//
//

#pragma once
#include "ofMain.h"

class Rectangle {
public:
    Rectangle(float posX, float posY);
    
    void zenoToPoint( float catchX, float catchY);
    void draw(float sizeX, float sizeY);
        
    ofPoint pos;
    ofPoint targetPos;
    
    float catchUpSpeed, rectSize;
    
};