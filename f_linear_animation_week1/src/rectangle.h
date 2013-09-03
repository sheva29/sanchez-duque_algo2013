//
//  rectangle.h
//  linear_animation
//
//  Created by Mauricio Sanchez Duque on 8/27/13.
//
//

#pragma once

#include "ofMain.h"

class Rectangle {

    //Allows people to use this variable in other classes
public:
    
    Rectangle();
    
    void update();
    void draw();
    
    void interpolateByPct( float myPct );
    
    void zenoToPoint( float catchX, float catchY );
    
    ofPoint pos;    
    

};
