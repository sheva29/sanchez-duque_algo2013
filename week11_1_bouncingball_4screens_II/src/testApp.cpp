#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(0);
    
    mSender.setup("127.0.0.1",12345);
//    mReceiver.setup(8001);
    
    pos = ofVec2f( 20,150);
    vel = ofVec2f( 5,5);
    
    mass = 20;
    
    ofSetWindowPosition(0,0);
    
    
    

}

//--------------------------------------------------------------
void testApp::update(){
    
    pos += vel;
    
    if( pos.x < mass){
        
        vel.x = -vel.x;
    }
    
    if( pos. x > (2 * ofGetWindowWidth() ) - mass){
        
        vel.x = -vel.x;
    }
    
    if( pos.y < mass){
        
        vel.y = - vel.y;
    }
    
    if( pos.y > ( 2 * ofGetWindowHeight() ) - mass){
        
        vel.y = -vel.y;
    }
    
    //Sender
  
    oscSender();


}

void testApp::oscSender(){
    
    ofxOscMessage m2;
    
    m2.setAddress("/ball/pos");
    m2.addFloatArg(pos.x);
    m2.addFloatArg(pos.y);
    
    mSender.sendMessage( m2 ) ;
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofCircle( pos, mass);

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
