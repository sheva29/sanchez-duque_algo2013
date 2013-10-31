#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    
    ofSetVerticalSync(true);
    ofBackground(0);
    ofSeedRandom();
    
    
    particleList = new vector < Particle >;
    
    
    for( int i = 0; i < NUM_OF_PARTICLES; i++){
        
        addParticles();
        
    }
    
    
}
//--------------------------------------------------------------

void testApp::exit(){
    
    delete particleList;
    
}
//--------------------------------------------------------------
void testApp::addParticles(){
    
    Particle tmp;
    particleList->push_back(tmp);
    
}
//--------------------------------------------------------------
void testApp::update(){
    
    vector<Particle>::iterator it = particleList->begin();
    
    ofVec2f gravity = ofVec2f( 0, 0.8);
//    ofVec2f damping = ofVec2f( 0.5, 0);
    
    for(it; it != particleList->end(); ++it){
        
        
       it->applyForce(gravity);
//        it->applyForce(damping);
        
        it->update();
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    
    vector<Particle>::iterator it = particleList->begin();
    vector<Particle>::iterator it2 = particleList->begin() + 3;
    for( it; it != particleList->end(); it++){
        
        
        it->draw();
//        advance(it, 3);
        
        ofDrawBitmapString(ofToString(it2->vel), 20, 20);
        
        
    }
    
    vector<Particle>::iterator p = particleList->begin();
    for( p; p != particleList->end(); p++){
        

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
