//
//  Rectangle.cpp
//  emptyExample
//
//  Created by Mauricio Sanchez Duque on 9/3/13.
//
//

#include "Rectangle.h"

Rectangle::Rectangle(float posX, float posY){
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    catchUpSpeed = 0.03;
    
    pos.x = posX;
    pos.y = posY;
}
void Rectangle::zenoToPoint(float catchX,float catchY){
    
    pos.x = catchUpSpeed * catchX + (1 - catchUpSpeed) * pos.x;
    
    pos.y = catchUpSpeed * catchY + (1 - catchUpSpeed) * pos.y;
    
    
}


void Rectangle::draw(float sizeX, float sizeY){
    
    float mousePos = ofGetMouseX();
    
    //Since we are controlling the color from here. If we call the Rectangle draw class in our main cpp
    float pct = ofMap(mousePos, 0, ofGetWidth(), 0,1,true);  // true = clamp, 0 to 1
    
    ofColor temp;
    temp.setHsb( pct * 255,255,255);
    
    ofSetColor(temp.r, temp.g, temp.b);
   
    ofRect(pos.x,pos.y,sizeX,sizeY);
    
}