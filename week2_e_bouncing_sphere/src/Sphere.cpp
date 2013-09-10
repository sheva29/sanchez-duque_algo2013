#include "Sphere.h"

Sphere::Sphere(){
    
    //Allocates a random value for more than one variable
    ofSeedRandom();
    
    //the cube's side
    pos.x = ofGetWindowHeight()/2;
    pos.y = ofGetWindowHeight()/2;
    pos.z = ofGetWindowHeight()/2;
    
    velX = ofRandom(0.5f,1.0f);
    velY = ofRandom(0.5f,1.0f);
    velZ = ofRandom(0.5f,1.0f);
    
    cubeSize = ofGetWindowHeight()/2;
    ofSetRectMode( OF_RECTMODE_CENTER );
    
}

void Sphere::update(){
    
    pos.x += velX *10.0f;
    pos.y += velY *10.0f;
    pos.z += velZ *10.0f;
    
    if(pos.x  < 0 || pos.x > cubeSize  ){
        
        velX = -velX;
    }
    
    if(pos.y  < 0 || pos.y  > cubeSize ){
        
        velY = -velY;
    }
    
    if(pos.z < 0 || pos.z > cubeSize  ){
        
        velZ = -velZ;
    }
}


void Sphere::draw(){
    
    ofNoFill();
    ofSetColor(0 , 255 * (pos.x/ofGetWindowWidth()) , 0,50);
    ofSetLineWidth(2);
    ofDrawBox(cubeSize/2,cubeSize/2,cubeSize/2,cubeSize);
    
    ofFill();
    ofSetColor(255,0,0);
    ofDrawSphere(pos.x, pos.y, pos.z,20);
    
    
    

    
}

