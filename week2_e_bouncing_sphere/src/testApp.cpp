#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){
  

    
    sphere.update();
   
  

}

//--------------------------------------------------------------
void testApp::draw(){

 
    

   
    
    camView.begin();
    ofPushMatrix();
    
    ofTranslate(ofGetWindowWidth()/4,ofGetWindowHeight()/4,ofGetWindowHeight()/2);
    
    camView.enableOrtho();
    
   
    
    sphere.draw();

  
    
    camView.end();
    ofPopMatrix();
    
//    ofDrawBitmapString(ofToString(camView.getGlobalOrientation()), ofPoint(60,20));

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

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