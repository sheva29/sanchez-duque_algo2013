#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    beta = 0;
    betaSpeed = 0.20f;

}

//--------------------------------------------------------------
void testApp::update(){
    
    beta += 0.015f;
   newBeta = beta;
    

}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    for( int x = 0; x <= ofGetWindowWidth(); x += 30){
        
        float y =ofMap(sin(newBeta), -1,1,0, ofGetWindowHeight() /2 );
        ofPoint temp;
        temp.x = x;
        temp.y = y;
        //Store the points in the vector to do something crazy!
        waterPoints.push_back(temp);
        ofCircle(x, y,5,5);
        newBeta += betaSpeed;
    }
    
    ofNoFill();
//    ofBeginShape();{
    
//    for( int i = 0; i < waterPoints.size(); i++){
    
             
//        ofVertex(waterPoints[i].x, waterPoints[i].y);
//        ofLine((waterPoints[i].x-1), (waterPoints[i].y - 1), waterPoints[i].x, waterPoints[i].y);
//        ofCircle( waterPoints[i].x, waterPoints[i].y, 8,8);
        
//    }
//    }ofEndShape();
    

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
