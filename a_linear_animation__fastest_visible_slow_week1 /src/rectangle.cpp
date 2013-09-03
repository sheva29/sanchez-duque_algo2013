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
      
}

void Rectangle::update(){
    
//    pos.x = pos.x + ofRandom(-1,1);
//    pos.y = pos.y + ofRandom(-5, 5);
    
    velocity = 290;
    

    
    
}

void Rectangle::draw(){
    
    ofEnableAlphaBlending();    
    ofSetColor(255, 0, 250, 255);
    
    
    ofRect(pos.x,pos.y, 10 , 10);
    
}

//void Rectangle::zenoToPoint(float catchX, float catchY){
//    
//    float catchUpSpeed = 0.03f;
//    
//    pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
//    pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
//    
//    
//}

void Rectangle::interpolateByPct( float myPct ) {
    
    
//    powf(2, 3) = 8

    pct = myPct;
    pct = powf(myPct, 4);
    
    pos.x = (1 - pct) * posa.x + pct * posb.x;
    pos.y = (1 - pct) * posa.x + pct * posb.y;
    
    
}