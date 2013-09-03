//
//  rectangle.cpp
//  linear_animation
//
//  Created by Mauricio Sanchez Duque on 8/27/13.
//
//

#include "rectangle.h"

//Constructor
Rectangle::Rectangle(){    
      
}

void Rectangle::update(){
        
    
}

void Rectangle::draw(){
    
    ofEnableAlphaBlending();    
    ofSetColor(255, 0, 250, 255*0.5);
    
    
    ofRect(pos.x,pos.y, 10 , 10);
    
}

void Rectangle::zenoToPoint(float catchX, float catchY){
    
    float catchUpSpeed = 0.03f;
    
    pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
    pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
    
    
}

