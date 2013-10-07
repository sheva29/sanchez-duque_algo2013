#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofSetVerticalSync(true);
    ofSetBackgroundAuto(false);
    ofSeedRandom();
    ofBackground(0);
    
    pos = ofPoint(900, 100);
    
 
    for( int i = 0; i < 20; i++){
        addParticle();
    }
}
//--------------------------------------------------------------
void testApp::addParticle(){
    
    
    pos = ofVec2f(ofRandom( -5, 5), ofRandom( -5, 5));
    Particle p(pos);
    particleGroup.push_back(p);
    
}
//--------------------------------------------------------------
void testApp::update(){
    
    ofVec2f gravity( 0.0 , 2);
    ofVec2f wind( 0.1, 0.0);
    
    vector < Particle >::iterator it;
    for( it = particleGroup.begin(); it != particleGroup.end(); ++it){
        
        it->applyForce(gravity);
        it->applyForce(wind);
        
        it->update();
    }

}

//--------------------------------------------------------------
void testApp::draw(){

    for( int i = 0; i < particleGroup.size(); i++){
        
        particleGroup[i].draw();
    }
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
