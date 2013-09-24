//Taken from 

#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofEnableSmoothing();
    ofSetVerticalSync(true);
    ofSetBackgroundAuto(false);
    ofSeedRandom();
    period = 10000;
    rStart = 30 + ofRandom(60);
    numberOfPoints = 512;
    _size = 4;
//    for( int i = 0; i <)

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------

void testApp::SetPointsColor(float theColor){
    
    float timeCoefficient = sin(ofGetElapsedTimeMillis() / period);
    
    int _red = sin(theColor * 127 + 128);
    int _green = sin(theColor + (2 * timeCoefficient) * PI/3) * 127 + 128;
    int _blue = sin(theColor + (4 * timeCoefficient) * PI/2) * 127 + 128;
    ofSetColor(_blue);
    
}
//--------------------------------------------------------------
void testApp::draw(){
    
    //ofBackground(0);
    
    float n = ofGetElapsedTimeMillis()/ period + rStart;
    float rad = ofGetWindowWidth() * 0.97f/2;
    _start = ofGetWindowSize()/2;
    for( int i = 0; i < numberOfPoints; i++){
        //Determines the speed and number of branches created by the balls.
        float alpha = (i * 2 * PI / numberOfPoints) * 3;
        SetPointsColor(n + alpha);
        float r = rad * -sin( n * alpha / 6);
        //Changes the position based on the angle using cos and sine
        pos.x = _start.x + cos(alpha) * r * 2;
        pos.y = _start.y + sin(alpha) * r * 2;
        //We draw our circle
        ofCircle(pos, _size);
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
