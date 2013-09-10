#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
}

//--------------------------------------------------------------
void testApp::update(){
    myBall.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    myBall.draw(myBall.position.x, myBall.position.y);
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
    
    myBall.draw(x,y);

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
    ofVec2f pMouse(ofGetPreviousMouseX(),ofGetPreviousMouseY());
    
    //This is the current position where the ball is
    ofVec2f ballPos(myBall.position.x, myBall.position.y);
    
    //We use the mouse position to use it as a thrower
    mouseX = x;
    mouseY = y;
    
    float newDist = ofDist(ballPos.x,ballPos.y,mouseX,mouseY);
    
    if(newDist < 10){
        
        myBall.position.x = x;
        myBall.position.y = y;
        myBall.velocity.x = x - pMouse.x * .97;
        myBall.velocity.y = y - pMouse.x;
             
        
    }
        
  
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
