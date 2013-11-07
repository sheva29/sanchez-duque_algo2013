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
    
    
    if( pos.x < 0){
        
        pos.x = ofGetWindowWidth();
        
    }
    
    if ( pos.x > ofGetWindowWidth() - 10){
        
        pos.x = 0;
    }
    
    if( pos.y < 0 ){
        
        pos.y = ofGetWindowHeight();
    }
    
    if ( pos.y > ofGetWindowHeight()){
        
        pos.y = 0;
        
    }
    
    //Add true at the end of the ofMap to clamp it! Thanks Jennifer :)
    yStreching = ofMap(vel.length(), 0, 2, 1.0, 2.0, true);

    cout << yStreching << endl;

    
}

void Particle::draw(){
    
    
    //Assigned the position to the direction which equals the direction of the velocity, the particles strech in the right direction when moving towards one of the side of the screen
    
    float angle = atan2(vel.x, vel.y);
    angle = ofMap(angle, -PI, PI, 0, 360);
    
    
    
    c.setHsb(hue, 255, 255);
    ofSetColor(c);
//    ofSetColor( (ofRandom(255)), (ofRandom(255)), ofRandom(255));
    
    ofPushMatrix();{
        
        ofTranslate( pos);
        ofRotate (  -angle );
        ofEllipse( 0, 0, (mass * massCoe), (mass * massCoe) * yStreching);
        
    }ofPopMatrix();
  
    
    
}