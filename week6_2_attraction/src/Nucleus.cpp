//
//  Nucleus.cpp
//  week6_2_attraction
//
//  Created by Mauricio Sanchez Duque on 10/8/13.
//
//

#include "Nucleus.h"



Nucleus::Nucleus(){
    
    
    red.setHsb(ofRandom(0,20), 255, 255, 100);
    pos = ofVec2f(ofRandom(ofGetWindowWidth()), ofRandom(ofGetWindowHeight()));
    vel.set(ofRandom(3));
    mass = ofRandom(0,10);
    
    
    numberOfProtons = 2;
    for ( int i = 0; i < numberOfProtons; i++){
        
        Mover tmp;
        particles.push_back(tmp);
        
    }
    
}

ofVec2f Nucleus::attract( Mover p){
    
    
    ofVec2f forceDir = pos - p.pos;
    float dist = forceDir.length();
    forceDir.normalize();
    
    
    //Don't use parenthesis in the division * (dist / dist).
    float pullStrength = ( G * mass * p.mass) / dist * dist;
    
    forceDir *= pullStrength;
    
    return forceDir ;
    
}

void Nucleus::applyForce(ofVec2f force){
    
    acc +=( force / mass);
}


void Nucleus::update(){
    
    
    vector < Mover >::iterator it;
    for(it = particles.begin(); it != particles.end(); it++){
        
        ofVec2f pull = attract(*it);
        it->applyForce(pull);
        it->update();
        (*it).update();
        
    }
    
    vel += acc;
    pos += vel;
    
    acc.set(0);
    
    
    if( pos.x < mass*10 || pos.x > ofGetWindowWidth() - mass*10){
        
        vel.x = -vel.x;
    }
    
    if( pos.y < mass*10 || pos.y > ofGetWindowHeight() - mass*10){
        
        vel.y = -vel.y;
    }
    
}



void Nucleus::draw(){
    
    
    vector< Mover>::iterator it;
    for( it = particles.begin(); it != particles.end(); it++){
        
        (*it).draw();
        
    }
    
    ofSetColor(red);
    ofCircle(pos, mass*10);
    
    
}

