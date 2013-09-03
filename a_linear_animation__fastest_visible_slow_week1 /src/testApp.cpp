#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    //Allows clear updating of vertically on the screen
    ofSetVerticalSync(true);
    
  
    
    //Calling the position of the rectangle from the main .cpp file. Because the class is public we can call it here.
//  myRect.pos.x = ofGetWindowWidth() / 2;
//  myRect.pos.y = ofGetWindowHeight() / 2;
    
    myRect.posa.x = 10;
    myRect.posa.y = 100;
    
    myRect.posb.x = 500;
    myRect.posb.y = 540;
    
    myRect.interpolateByPct(0.0f);
    
    pct = 0;
//  ofSetRectMode(OF_RECTMODE_CENTER);
    
    
    myRect.pos.x = 0;
    myRect.pos.y = 20;
    finalTime = 0;    
    
    //Current resolution of the window in pixels of course.
    windowSize = 1140;
        
    //Window Physical size
    windowSizeInches = 13;
    
    
    //It tells us hoe many inches pixels are per 1 inch
    pixelsInInches = windowSizeInches / windowSize;
    
    //This number decides how many pixels move per frame rate if the frame rate is 60 it will move 60 pixels in one second
    pixelsPerFrameRate = 1;
    
    //It gives me pixels/seconds. It gives us the speed of how many pixels move per second based on the frame rate
    pixelsPerTime = pixelsPerFrameRate * ofGetFrameRate();
    

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
    
     //Here is what we move the square
     myRect.pos.x += pixelsPerFrameRate; 
    
    
    
     if( myRect.pos.x >= (ofGetWindowWidth() - 10)){
        
        myRect.pos.x = ofGetWindowWidth() - 10;
    }  
   
 
    myRect.update();
    
    

//    myRect.zenoToPoint(mouseX, mouseY);
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
   
    ofBackgroundGradient(50, 0);
    myRect.draw();
    
    
    ofSetColor(255);
    
    //If the frame rate is set at 60. 1/60 will tell us how many frames move according to our speed
    timeToMove1Pixel = 1 / pixelsPerTime;
    
    //Distance in inches is a coefficient that allows us to know how many pixels are in the distance
    squareSpeedInInches = pixelsInInches * pixelsPerTime;
    
    //This variable tells us how much time it takes for the sqaure to make it all the way to the end of the screen
    timeToArrive = (pixelsInInches *( ofGetWindowWidth() - myRect.pos.x )/ squareSpeedInInches);
    
        
    //Writes the equivalent of last time
    ofDrawBitmapString("Time Traveled = " + ofToString((finalTime)) + "secs" + " At a speed of = " + ofToString(squareSpeedInInches) + " inches/secs " , ofPoint(ofGetWindowWidth()/4, 10));
    
    
    ofDrawBitmapString("Time to get to the end of the screen = " + ofToString(timeToArrive,2), ofPoint(50, 500));
    

    
    
        

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
