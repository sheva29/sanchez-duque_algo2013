#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofEnableAlphaBlending();
    ofBackgroundGradient(255, 30);
    
    newCookieMonster.pos = ofGetWindowSize()/2;
    
    newCookieMonster.vel.x = ofRandom(3);
    newCookieMonster.vel.y = ofRandom(3);
    
    _accelCoe = 0.008f;
    
    _sound.setup();
    
    cookieSound = true;
    
    
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    newCookieMonster.mousePos.x = mouseX;
    newCookieMonster.mousePos.y = mouseY;
    
    ofPoint _mousePos( mouseX, mouseY);
    leftEye.mousePos = _mousePos;
    leftEye.pos.x = newCookieMonster.pos.x + 85;
    leftEye.pos.y = newCookieMonster.pos.y + 36;
    
    rightEye.pos.x = newCookieMonster.pos.x + 137;
    rightEye.pos.y = newCookieMonster.pos.y + 40;
    
    newCookieMonster.zenoToCookie(newCookieMonster.mousePos, _accelCoe);
    _sound.update();
    
     newDis = ofDist(newCookieMonster.pos.x, newCookieMonster.pos.y, newCookiePos.x, newCookiePos.y);
    

    
        if (newDis <= 50){
            
            _sound.draw();
            cookieSound = false;
        }
    

    

}

//--------------------------------------------------------------
void testApp::draw(){
    
   
 
    
    ofNoFill();
    ofEnableAlphaBlending();
    ofSetColor(255, 255, 255, 255);
    newCookieMonster.draw();
    
    
    newCookiePos.x = mouseX - (newCookie._cookie.getWidth()/2);
    newCookiePos.y = mouseY - ( newCookie._cookie.getHeight()/2);
    

    newCookie.draw(newCookiePos);
    newCookie._cookie.resize(100, 100);
    
    ofSetRectMode(OF_RECTMODE_CORNER);
    leftEye.draw();
    rightEye.draw();
    

    
  

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
