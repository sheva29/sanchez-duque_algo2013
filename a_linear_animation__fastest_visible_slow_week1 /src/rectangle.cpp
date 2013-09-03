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
    
    pct = 34;
    velocity = 290;
      
}

void Rectangle::update(){ 
    
}

void Rectangle::draw(){
    
    ofEnableAlphaBlending();    
    ofSetColor(255, 0, 250, 255);
    
    
    ofRect(pos.x,pos.y, 10 , 10);
    
}


