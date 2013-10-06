#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
//    ofSetBackgroundAuto(false);
    
    xSpacing = 8;
    w = ofGetWindowWidth() + 16;
    
    theta = 0.0f;
    amplitude = 175.0f;
    period = 500.0f;
    dx = (TWO_PI / period) * xSpacing;
    yValues[w/xSpacing];
    
    cout << sizeof(yValues) << endl;
    cout << yValues_SIZE << endl;

    
    
}

//--------------------------------------------------------------
void testApp::calculateWave(){
    
    theta += 0.02f;
    
    float x = theta;
    for( int i = 0; i < yValues_SIZE ; i++){
        
        yValues[i] = sin(x) * amplitude;
        x += dx;
//        cout << " This is the value of yValues: " << yValues[i] << endl;
    }
    
}
//--------------------------------------------------------------
void testApp::renderWave(){
    
    for( int x = 0; x < yValues_SIZE; x++){
      
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofNoFill();
        ofEllipse( x * xSpacing, ofGetWindowWidth()/2 + yValues[x], yValues[(x + x) % 77] , yValues[(x + x + x) % 77]);
    }
    
    
}
//--------------------------------------------------------------
void testApp::update(){

     calculateWave();
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
   
   renderWave();

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
