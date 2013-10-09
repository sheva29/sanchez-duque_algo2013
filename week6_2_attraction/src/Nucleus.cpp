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
    mass = ofRandom(3,5);
    
    //This starts the number electrons around our nucleus. And yes! protons are in the same number as electrons on an atomic particle
    numberOfProtons = 2;
    
    //We start the particle revolving around our nucleus
    for ( int i = 0; i < numberOfProtons; i++){
        
        Mover tmp;
        particles.push_back(tmp);
        
    }
    
}

//This force will determine how our revolving will behave
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
    
    //This is where the magic happens. So
    vector < Mover >::iterator it;
    for(it = particles.begin(); it != particles.end(); it++){
        
        //This is the forced casted from the result of the particles taht are attracted to the nucleus
        ofVec2f pull = attract(*it);
        //Here we cast that force to apply it to the electrons
        it->applyForce(pull);
        it->update();
       
        
    }
    
    vel += acc;
    pos += vel;
    
    //Happened to turn this off and seems to work. I forgot why the acceleration gets set to zero.
//    acc.set(0);
    
    
    //This rules here are for the atom to bounce on the screen
    if( pos.x < mass*10 || pos.x > ofGetWindowWidth() - mass*10){
        
        vel.x = -vel.x;
    }
    
    if( pos.y < mass*10 || pos.y > ofGetWindowHeight() - mass*10){
        
        vel.y = -vel.y;
    }
    
}



void Nucleus::draw(){
    
    //We finally draw our nucleus with our electrons
    vector< Mover>::iterator it;
    for( it = particles.begin(); it != particles.end(); it++){
        
        (*it).draw();
        
    }
    
    ofSetColor(red);
    ofCircle(pos, mass*10);
    
    
}

