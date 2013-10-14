#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    //We set our canvas
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    ofSetBackgroundAuto(false);
    ofBackground(0);
    
    backC = 0;

}

//--------------------------------------------------------------
void testApp::update(){
    
    
    pos.x = ofRandom(ofGetWindowWidth());
    pos.y = ofRandom(ofGetWindowHeight()-100);
    pos.z = ofRandom(ofGetWindowHeight()-100);
    setVel = ofRandom(5,7.5);
    hue = ofRandom(255);
   
    vector<Fireworks>::iterator it;
    for( vector<Fireworks>::iterator it = fireworksList.begin(); it != fireworksList.end(); it++){
        //Apply all the physics we wrote in our class
        (*it).update();
        
        //if our particle dies we reset it.
        if( (*it).kill() ){
            
            (*it).setup(pos, setVel, hue);
            
        }
    }
    
    
    //Here we control the amout of fireworks that we want to have on the screen, we don't let it grow beyond 500 so that it does not slow down
    if (fireworksList.size() < 500){
        for( int i = 0; i < 1; i++){
            pos.x = ofRandom(500);
            pos.y = ofRandom(400);
            pos.z = ofRandom(400);
            setVel = ofRandom(5,7.5);
            hue = ofRandom(255);
            addFireworks(pos, setVel, hue);
        }
    }
    
    //We push the cam away from the canvas a bit to have a big picture of it
    camView.setDistance(1000);
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    //Use a camera to see it from different angles
    camView.begin();
    
    //We draw a gigantic box to content our particles and create the effect
    ofSetRectMode((OF_RECTMODE_CENTER));
    ofEnableAlphaBlending();
    ofSetColor( backC , 30);
    ofDrawBox(0,0,0,4000);
    
    //Draw our fireworks
    vector<Fireworks>::iterator it ;
    for(it = fireworksList.begin(); it != fireworksList.end(); it++){
        
        it->draw();
        
    }
    
    camView.end();
    
  

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
