//
//  Circles.cpp
//  week5_3_using_sin_cos_move_stuff
//
//  Created by Mauricio Sanchez Duque on 10/11/13.
//
//

#include "Circles.h"


Circles::Circles(){
    
    
    xSpacing = 8;
    w = ofGetWindowWidth() + 16;
    
    theta = 0.0f;
    amplitude = 175.0f;
    period = 500.0f;
    dx = (TWO_PI / period) * xSpacing;
    yValues_length = w/xSpacing;

    
    
    cout << yValues << endl;
    
    coeVariable = 1;
    
    
    
}

void Circles::update(){
    

    calculateWave();
}


void Circles::draw(){
    
    
    renderWave();
//    ofDrawBitmapString(ofToString(coeVariable), 100, 100);
    
}

void Circles::calculateWave(){
    
    theta += 0.02f;
    
    float x = theta;
    for( int i = 0; i < yValues_length; i++){
        
        yValues[i] = sin(x) * amplitude;
        x += dx;
        
        cout << " This is the value of yValues: " << yValues[i] << endl;
        
    }
    
    
}

void Circles::renderWave(){
    
    
    for( int x = 0; x < yValues_length; x++){       
        
        ofEllipse( x * xSpacing, ofGetWindowHeight()/2 + yValues[x], yValues[(x + x) % coeVariable ] , yValues[(x + x + x)  % coeVariable]);
    }
    
    
    
}