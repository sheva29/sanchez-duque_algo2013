#include "Particle.h"


Particle::Particle(){
    
    mass = .5;
    massCoe = 50;
    
    damping = ofRandom( 0.9999998, 0.98);
    
//    c.setHsb(ofRandom(255), 255, 255);

    yStreching = 0;
    xStreching = 0;
    
}

void Particle::applyForce( ofVec2f force){
    
    acc += ( force / mass);
    ;
}

void Particle::update(){
    
    dir = vel.normalized();
    
    
    
    vel += ( acc * 0.05);
    pos += vel;
    
    //We want the speed to start slowing down fradually
    vel *= damping;
    
    acc.set(0);
    
 
    float angle = atan2( vel.x, vel.y);
    hue = ofMap( angle , -PI,PI, 0 , 255);
    
//    atan(vel.x / vel.x);
    
    
    if( pos.x < 10){
        
        vel.x = -vel.x;
        
    }
    
    if ( pos.x > ofGetWindowWidth() - 10){
        
        vel.x = -vel.x;
    }
    
    if( pos.y < 10 ){
        
        vel.y = -vel.y;
    }
    
    if ( pos.y > ofGetWindowHeight() - 10){
        
        vel.y = -vel.y;
        
    }
    
    yStreching = ofMap(vel.y, -2, 2, 1.0f, 1.1);
    
    xStreching = ofMap(vel.x, -2, 2, 1.0f, 1.1);
    
   
    
}

void Particle::draw(){
    
    
    //Assigned the position to the direction which equals the direction of the velocity, the particles strech in the right direction when moving towards one of the side of the screen
    
    float angle = dir.length();
    
    
    c.setHsb(hue, 255, 255);
    ofSetColor(c);
//    ofSetColor( (ofRandom(255)), (ofRandom(255)), ofRandom(255));
    
    ofPushMatrix();{
        
        ofTranslate( pos);
        ofRotate (  angle );
        ofEllipse( 0, 0, (mass * massCoe) * xStreching, (mass * massCoe) * yStreching);
        
    }ofPopMatrix();
  
    
    
}