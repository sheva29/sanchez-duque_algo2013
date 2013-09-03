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
    
    for ( int i = 0 ; i < NUM_RECTS; i++){
        
        rectSize[i] = ofRandom(10 , 50);
    }
    
    for ( int i = 0 ; i < COLOR_RANGE; i++){
        
        colorR[i] = ofRandom(0 , 255);
        colorG[i] = ofRandom(0 , 255);
        colorB[i] = ofRandom(0 , 255);
    }
    
    for ( int i = 0; i < NUM_RECTS; i++){
        
        pos[i] = ofRandom(0, ofGetWindowHeight());
        
    }
    
    for ( int i = 0; i < NUM_RECTS; i++){
        
        catchUpSpeed[i] = ofRandom(0.03f, 0.1f);
        
    }
}



void Rectangle::update(){
    
//    pos.x = pos.x + ofRandom(-1,1);
//    pos.y = pos.y + ofRandom(-5, 5);
    
    
}

void Rectangle::draw(){
    
    for ( int i = 0; i < NUM_RECTS; i++){
    
    ofEnableAlphaBlending();    
    ofSetColor(colorR[i],colorG[i], colorB[i], 255*0.5);
    
    
    ofRect(pos[i], pos[i], rectSize[i] , rectSize[i]);
    }
}

void Rectangle::zenoToPoint(float catchX, float catchY){
    

    
    
}

