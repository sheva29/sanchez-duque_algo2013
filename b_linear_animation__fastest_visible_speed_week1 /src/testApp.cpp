#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    //Allows clear updating of vertically on the screen
    ofSetVerticalSync(true);
    
  
    
    //Calling the position of the rectangle from the main .cpp file. Because the class is public we can call it here.
//    myRect.pos.x = ofGetWindowWidth() / 2;
//    myRect.pos.y = ofGetWindowHeight() / 2;
    
    myRect.posa.x = 10;
    myRect.posa.y = 100;
    
    myRect.posb.x = 500;
    myRect.posb.y = 540;
    
    myRect.interpolateByPct(0.0f);
    
    pct = 0;
//    ofSetRectMode(OF_RECTMODE_CENTER);
    
    velocity = 800;
    myRect.pos.x = 0;
    myRect.pos.y = 20;
    lastPosTime = 0;
    firstPosTime = 0;
    finalTime = 0;
    
    //The retina display has 110 px/inch. If the size of the screen is 1024px. The distance is 9.30''
    distance = 9.30909090909091;
    squareSpeed = 0;
    

    
  
    
    
    
    
    
    
    

}

//--------------------------------------------------------------
void testApp::update(){

//    myRect.update();
//    pct += 0.001f;
//    if( pct > 1){
//        pct = 0;
//    }
//
//   myRect.interpolateByPct(pct);
    
        
      
    
    if( ofGetElapsedTimef() >= 1){
        
          myRect.pos.x += velocity;
    }
    
    
    
    if(myRect.pos.x >= (ofGetWindowWidth()-10)){
        
        myRect.pos.x = ofGetWindowWidth()-10;
    }
    
    
   
 
    myRect.update();

//    myRect.zenoToPoint(mouseX, mouseY);
}

//--------------------------------------------------------------
void testApp::draw(){
    
   
    ofBackgroundGradient(50, 0);
    myRect.draw();
    
    
    ofSetColor(255);
    
    //Writes the initial time which is zero
//    ofDrawBitmapString(ofToString(firstPosTime), ofPoint(10,10));
    
    //lastPostTime will become the current time when the square has reached its position
    if( myRect.pos.x >= (ofGetWidth() - 10) && lastPosTime == 0){
        
        lastPosTime = ofGetElapsedTimef() - 1;
    
        
    
    }
    //lastPosTime will be drawn at that point where it was checked
//    ofDrawBitmapString( /*ofToString(pct)*/ ofToString(lastPosTime), ofPoint(900, 10));
    
    //Triggers the time after 1 second to see the motion of the square
    if( ofGetElapsedTimef() >= 1 && firstPosTime == 0){
        
        firstPosTime = ofGetElapsedTimef() - 1;
    }
    
    //Compiles the final by substracting initial and last time
    finalTime = lastPosTime -  firstPosTime;
    
    squareSpeed = distance / finalTime;
    
    //Writes the equivalent of last time
    ofDrawBitmapString("Time Traveled = " + ofToString((finalTime)) + "secs" + " At a speed of = " + ofToString(squareSpeed) + " inches/secs " , ofPoint(ofGetWindowWidth()/4, 10));
    
        
    
    

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
