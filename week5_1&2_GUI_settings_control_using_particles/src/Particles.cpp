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
//    _drawingCir = false;
    
}


void Particles::update(ofImage img){
    
    
    //Uncomment if you want to have some particles dancing. It might get super slow though.
    //    pos.x = ofRandom(0, ofGetWindowWidth());
    //    pos.y = ofRandom(0, ofGetWindowHeight());
    
    diagonal = ofDist( 0, 0 , ofGetWindowWidth(), ofGetWindowHeight());
    
    tempSize = ofDist(ofGetMouseX(), ofGetMouseY(), pos.x, pos.y);
    

    rectSize = ofMap( tempSize, 0, diagonal, 0, rectSizeMax);
    
    pixelColor = img.getColor(pos.x,pos.y);
    
    
    
}

void Particles::draw(){
    
    
    //Eventhough the variables are inside the loop we don't have to get int i involved, Why?
    
    //We take the color from our picture for our squares based on their position    
    
    ofSetColor(pixelColor);
    
    //Here we want to move the origin to the position where we are drawing our square so the rotate on their a
    ofPushMatrix();{
        //We want to draw our squares at the  new origin. All of them
        ofTranslate(pos);
//        ofSetRectMode(OF_RECTMODE_CENTER);
        ofRotate(_angle);
        
        //Here we will decide to whether or not we want to draw circles or squares. _drawinCir will be passed to the GUI events function.
        if( _drawingCir == false){
            
             ofRect(0, 0, rectSize, rectSize);          
            
            
        }else if(_drawingCir == true){
            
            ofCircle(0,0, rectSize);
            
            
        }
       
    }ofPopMatrix();
    
    
    
    
    
}