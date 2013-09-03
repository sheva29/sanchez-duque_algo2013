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
    
  
    //t=This will allows us to change rectangle position by just clicking.
    if(posChange == true){
        
        posa.x = ofGetMouseX();
        posa.y = ofGetMouseY();
        
    }else if( posChange == false){
        
        posb.x = ofGetMouseX();
        posb.y = ofGetMouseY();
    }
    

    
    
}

void Rectangle::draw(){
    
    ofEnableAlphaBlending();    
    ofSetColor(255, 0, 250, 255);
    
    
    ofRect(pos.x,pos.y, 10 , 10);
    
}

void Rectangle::zenoToPoint(float catchX, float catchY){
    
    float catchUpSpeed = 0.03f;
    
    pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
    pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
    
    
}

