#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(0);
    ofSetBackgroundAuto(false);
    ofSeedRandom();
    
    
    numberOfAtoms = 6;
    
    //We start the nucleus
    for( int i = 0; i < numberOfAtoms; i++){
        
        Nucleus tmp;
        atoms.push_back(tmp);
        
    }
    


}
//--------------------------------------------------------------
void testApp::update(){
    
    vector< Nucleus>::iterator it;
    for( it = atoms.begin(); it != atoms.end(); it++){
        
         it->update();

    }
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofColor backGround;
    
    backGround.set(0);
    
    ofSetColor(backGround);
    ofRect(0,0, ofGetWindowWidth(), ofGetWindowHeight());
    
    vector < Nucleus>::iterator it;
    for( it = atoms.begin(); it != atoms.end(); it++){
        
        it->draw();
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
