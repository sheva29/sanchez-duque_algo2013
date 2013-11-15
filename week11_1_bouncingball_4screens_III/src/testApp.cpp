#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(0);
    
    mSenderIII.setup("localhost", 8002);
    mReceiver.setup(12345);
    
//    pos = ofVec2f( 0,0);
//    vel = ofVec2f( 5,5);
    
    mass = 20;
    ofSetWindowPosition(0, ofGetWindowHeight());
    
    
    

}

//--------------------------------------------------------------
void testApp::update(){
    
    oscReceiver();
    
    ofxOscMessage m2;
    
    m2.setAddress("/ball/pos");
    m2.addFloatArg(pos.x);
    m2.addFloatArg(pos.y);
    
    mSenderIII.sendMessage( m2 ) ;
    
    
    
}

void testApp::oscReceiver(){
    
    //Receiver
    
    
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
        ofTranslate(0, -ofGetWindowHeight());
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
