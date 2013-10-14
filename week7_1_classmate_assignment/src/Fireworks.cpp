//
//  Fireworks.cpp
//  week7_1_classmate_assignment
//
//  Created by Mauricio Sanchez Duque on 10/13/13.
//
//

#include "Fireworks.h"


void Fireworks::setup( ofVec3f _pos, float setVel, float hue){
   
    size =ofRandom(3,6);
    pos = _pos;
    vel.x = ofRandom(-setVel, setVel);
    vel.y = ofRandom(-setVel, setVel+2);
    vel.z = ofRandom(-setVel, setVel+4);
    acc.y = -0.5f;
    age = 0;
    life = ofRandom(50, 600);
    c.setHsb(hue+ofRandom(-20.0, 20.0), 255, 255);
    
    
    
}


void Fireworks::update(){
    
    float pct = 1.0-(float)age/(float)life;
    
    size *= pct;
    vel += acc;
    pos += vel;
    vel *= 0.98;
    age++;

    
}


void Fireworks::draw(){
    
    
    
   
    ofPushMatrix();{
        
       
        ofTranslate(pos.x,pos.y,pos.z);
        ofSetColor( c, 150);
        ofDrawSphere(0,0,0, size);
        
        
    }ofPopMatrix();
    
    
    
    
    
}

bool Fireworks::kill(){
    
    if( age >=life){
        
        return true;
        
    }else{
        
        return false;
    }
    
    
}


