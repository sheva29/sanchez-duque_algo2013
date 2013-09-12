#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    //Allows clear updating of vertically on the screen
    ofSetVerticalSync(true);
    
    //Calling the position of the rectangle from the main .cpp file. Because the class is public we can call it here.
    
    for ( int i =0; i < NUM_CIRCLES; i++){
    
    myRect[i].pos.x = ofGetWindowWidth() / 2;
    myRect[i].pos.y = ofGetWindowHeight() / 2;
    
//    myRect.posa.x = 10;
//    myRect.posa.y = 100;
//    
//    myRect.posb.x = 500;
//    myRect.posb.y = 540;
    
    myRect[i].interpolateByPct(0.0f);
        
        
        
    }
    
    pct = 0;
    
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    

}

//--------------------------------------------------------------
void testApp::update(){
    
    for( int i = 0; i < NUM_CIRCLES; i++){
        myRect[i].update();
    }
    
    pct += 0.001f;
    if( pct > 1){
        pct = 0;
    }
    
    for( int i = 0; i < NUM_CIRCLES; i++){
    
   

   myRect[i].interpolateByPct(pct);
        
    }

//    myRect.zenoToPoint(mouseX, mouseY);
}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    
    for( int i = 0; i < NUM_CIRCLES; i++){
    
    
        myRect[i].draw();
        // Watch out for this cout call - syntax error.
        //cout << myRect[i].draw() << endl;
    }
    
    ofSetColor(255);
    
    ofDrawBitmapString( ofToString(pct), ofPoint(10, 10));

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
    //(float) next to a variables implies that it is being cast as a float
    
    
    pct = (float)  y /  (float) ofGetWindowHeight();
	if (pct < 0) pct = 0;
	if (pct > 1) pct = 1;
    for( int i = 0; i < NUM_CIRCLES; i++){
        myRect[i].interpolateByPct(pct);
    }
    
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
