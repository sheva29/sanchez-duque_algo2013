//
//  FlowField.h
//  week7_2_3_vector_fields_settings
//
//  Created by Mauricio Sanchez Duque on 10/13/13.
//
//

#pragma once
#include "ofMain.h"

typedef vector<ofVec2f> VectorList;

class FlowField {
public:
    FlowField();
    
    void setup( int width, int height, int res );
    void setSingleDirection();
    void setRandom();
    void setPerlin();
    void setAm();
    void setModularAm();
    void setSin();
    
    
    void draw();
    
    void drawVector( const ofVec3f &start, const ofVec3f &end, float headLength = 0.2f, float headRadius = 0.05f );
    void drawVectorAt( const ofVec2f &vec, const ofVec2f &pos );
    
    vector<VectorList>  flowList;
    int                 fieldWidth, fieldHeight, resolution;
};
