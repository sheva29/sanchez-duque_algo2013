//
//  Particles.cpp
//  week5_1_GUI_particles_control
//
//  Created by Mauricio Sanchez Duque on 9/30/13.
//
//

#include "Particles.h"


Particles::Particles(ofVec2f position){
    
    
    pos = position;
    diagonal = 0;
    tempSize = 0;
    rectSize = 0;
    
}


void Particles::update(ofImage img){
    
    
    
    //    pos.x = ofRandom(0, ofGetWindowWidth());
    //    pos.y = ofRandom(0, ofGetWindowHeight());
    
    diagonal = ofDist( 0, 0 , ofGetWindowWidth(), ofGetWindowHeight());
    
    tempSize = ofDist(ofGetMouseX(), ofGetMouseY(), pos.x, pos.y);
    
    rectSizeMax = 1;
    rectSize = ofMap( tempSize, 0, diagonal, 0, rectSizeMax);
    
    pixelColor = img.getColor(pos.x,pos.y);
    
    
    
}

void Particles::draw(){
    
    
    
    
    
    //Eventhough the variables are inside the loop we don't have to get int i involved, Why?
    
    
    ofSetColor(pixelColor);
    ofRect(pos.x, pos.y, rectSize, rectSize);
    
    
    
    
    
}