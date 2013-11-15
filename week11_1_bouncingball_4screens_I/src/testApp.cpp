#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(0);

    mReceiver.setup(8003);
    
    mass = 20;
    ofSetWindowPosition(ofGetWindowWidth(), 0);
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    while( mReceiver.hasWaitingMessages()){
        
        
        ofxOscMessage m;
        mReceiver.getNextMessage(&m);
        
        string addr = m.getAddress();
        
        if ( addr == "/ball/pos"){
            
            float xPos = m.getArgAsFloat(0);
            float yPos = m.getArgAsFloat(1);
            
            pos.set(xPos, yPos);
            
        }
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofPushMatrix();{
        ofTranslate(-ofGetWindowWidth(),0);
        ofCircle( pos, mass);
    }ofPopMatrix();

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
