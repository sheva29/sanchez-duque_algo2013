#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    ofBackground(0);

}

//--------------------------------------------------------------
void testApp::update(){
    
    
    pos.x = ofRandom(ofGetWindowWidth());
    pos.y = ofRandom(ofGetWindowHeight()-100);
    pos.z = ofRandom(ofGetWindowHeight()-100);
    setVel = ofRandom(5,7.5);
    hue = ofRandom(255);
    
    vector<Fireworks>::iterator it;
    for( it = fireworksList.begin(); it != fireworksList.end(); it++){
        
        (*it).update();
        
        if( (*it).kill() ){
            
            it = fireworksList.erase(it);
        }else{
            
            it++;
        }
    }
    
    for( int i = 0; i < 20; i++){
        
        addFireworks(pos, setVel, hue);
    }
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetRectMode((OF_RECTMODE_CENTER));
    vector<Fireworks>::iterator it;
    for( it = fireworksList.begin(); it != fireworksList.end(); it++){
        
        (*it).draw();
        it++;
    }
    
  

}

void testApp::addFireworks(ofVec3f pos, float setVel, float hue){
    
    Fireworks tmp;
    tmp.setup(pos, setVel, hue);
    fireworksList.push_back(tmp);
    
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
