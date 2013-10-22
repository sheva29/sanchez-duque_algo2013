//
//  FlowField.h
//  week8_1_vectorfield_composition
//
//  Created by Mauricio Sanchez Duque on 10/21/13.
//
//

#pragma once
#include "ofMain.h"

typedef vector<ofVec2f> VectorList;

class FlowField {
public:
    FlowField();
    
    void setup( int width, int height, int res );
    //Sets the vectorfield randomly
    void setRandom( const float &strength = 10.0f);
    //Sets the vector field to Perlin noise
    void setPerlin();
    
    void update();
    void draw();
    
    ofVec2f getForcePostion( ofVec2f pos);
    
    void drawVector( const ofVec3f &start, const ofVec3f &end, float headLength = 0.2f, float headRadius = 0.05f );
    void drawVectorAt( const ofVec2f &vec, const ofVec2f &pos, const float &strength = 10.0 );
    
    void addRepelForce( float x, float y, float radius, float strength );
    void addAttractForce( float x, float y, float radius, float strength );
    void addCircularForce( float x, float y, float radius, float strength );
    
    void addSineForce( float x, float y, float radius, float strength);
    
    void addModularAmplitudeForce( float x, float y, float radius, float strength);
    
    vector<VectorList>  flowList;
    int                 fieldWidth, fieldHeight, resolution;
};
