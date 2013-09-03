#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    //Allows clear updating of vertically on the screen
    ofSetVerticalSync(true);
    
    //Calling the position of the rectangle from the main .cpp file. Because the class is public we can call it here.
    myRect.pos.x = ofGetWindowWidth() / 2;
    myRect.pos.y = ofGetWindowHeight() / 2;
    
    myRect.posa.x = 10;
    myRect.posa.y = 100;
    
    myRect.posb.x = 500;
    myRect.posb.y = 540;
    
    myRect.interpolateByPct(0.0f);
    
    pct = 0;
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    for( int i = 0; i < numRectangles; i++){
        
        Rectangle myRect;
        myRects.push_back(myRect);
        
    }
    

}

//--------------------------------------------------------------
void testApp::update(){


 
    
        myRects[0].zenoToPoint(mouseX, mouseY);
    
    
    

    for( int i = 1; i < myRects.size(); i++){
        
        myRects[i].zenoToPoint(myRects[i - 1].pos.x, myRects[i - 1].pos.y);
        
//        myRects[i].zenoToPoint(mouseX+i*10, mouseY-i*10);
//        myRects[i].zenoToPoint(myRects[i-1].pos.x,myRects[i-1].pos.y);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
//    myRect.draw();
    
    
    for( int i = 0; i < myRects.size(); i++){
        
        myRects[i].draw();
        
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
    float pct = (float)y / (float)ofGetWindowHeight();
//    myRect.interpolateByPct(pct);
    
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
