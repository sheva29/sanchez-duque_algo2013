//
//  Particle.cpp
//  week9_1_animation_principles
//
//  Created by Mauricio Sanchez Duque on 10/28/13.
//
//

#include "Particle.h"


Particle::Particle(){
    
    pos = ofVec2f( ofGetWindowSize()/2);
    
    vel = ofVec2f( ofRandom(-2,2 ), ofRandom(-2, 2));
    
    mass = 1;
    
    damping = 0.9999999;
    
    coe = 20;
    
    yStreching = 0;
    
    c.setHsb(ofRandom(255), 255, 255);
    
    
    
}

void Particle::applyForce( ofVec2f &force){
    
    acc += ( force / mass);
    
    
}


void Particle::update(){
    
    vel += acc;
    pos += vel;
    vel *= damping;
    
    
    if( pos.x < (mass * coe) / 2 ){
        
        vel.x = -vel.x;
        //This makes sure that if there's no velocity X the ball remains inside the window on the left side
        pos.x = coe / 2;
        
    }else if(pos.x > (ofGetWindowWidth() -(coe/2))){
        
        vel.x = -vel.x;
        //This makes sure that if there's no velocity X the ball remains inside the window on the right side
        pos.x = ofGetWindowWidth() - (coe /2);
        
        
    }
    
    if( pos.y < (mass * coe/ 2)){
        
        vel.y = -vel.y;
        //This one makes sure that if there's no velocity on Y, the ball stays inside the window at the top
        pos.y =  coe / 2;
        
    }else if(pos.y > (ofGetWindowHeight() - (coe / 2))){
        
         vel.y = -vel.y;
        //This one makes sure that if there's no velocity on Y, the ball stays inside the window at the bottom
         pos.y = ofGetWindowHeight() - ( coe / 2);
        
    }
    
    //This will affect the size of the ball based on its velocity
    yStreching = ofMap(vel.y, -2, 2, 1.0f, 1.1);
    
    xStreching = ofMap(vel.x, -2, 2, 1.0f, 1.1);
    
    
    acc.set(0);
}

void Particle::draw(){
    
    ofSetColor(c);
    //When using yStrech as a positive number it was giving me the opposite effect.
    ofEllipse(pos.x, pos.y, (mass * coe) * xStreching, (mass * coe) * (-yStreching));
    
    
}