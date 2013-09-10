#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    
    ofSetBackgroundAuto(false);
    for( int i= 0; i < 20; i++){
        //My new element added to my vector
        Rectangle tmpRect(mouseX,mouseY);
        myRects.push_back( tmpRect);
        //After pushing_back our vector we start calling the properties of it such as pos.
                          myRects[i].pos.x = ofRandomWidth();
        myRects[i].pos.y = ofRandomHeight();
        myRects[i].rectSize = ofRandom(5,60);
        
    }

}

//--------------------------------------------------------------
void testApp::update(){

//    myRect.zenoToPoint( mousePosition.x, mousePosition.y);
    
    for ( int i = 0; i < myRects.size(); i++){
        if( i ==0){
        myRects[i].zenoToPoint(mousePosition.x, mousePosition.y);
            
        }else{
            myRects[i].zenoToPoint(myRects[i-1].pos.x, myRects[i -1].pos.y);
            
        }
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){

    ofSetRectMode(OF_RECTMODE_CORNER);
    
    ofEnableAlphaBlending();
//    ofBackground(100,100,100,255.0 * 0.1);
    ofColor semiTransparent( 100, 100, 100, 255.0*0.05);
    ofSetColor( semiTransparent);
    ofRect(0,0, ofGetWindowWidth(), ofGetWindowHeight());
    
     
    for ( int i = 0; i < myRects.size(); i++){
    
        myRects[i].draw(myRects[i].rectSize, myRects[i].rectSize);
    }
    
    
    //When drawing a sphere because of the nature of the shape, squares don't have  a Z axis there for show as with no fill.
//    ofSetColor(180);
//    ofNoFill();
//    ofDrawSphere(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth());
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
    mousePosition.x = x;
    mousePosition.y = y;
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
//    Rectangle newRect(mouseX,mouseY);
//    myRects.push_back(newRect);
//    cout << myRects <<endl;
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