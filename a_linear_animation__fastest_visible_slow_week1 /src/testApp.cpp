#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    //Allows clear updating of vertically on the screen
    ofSetVerticalSync(true);   
    
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
    pixelsPerFrameRate = 0.002f;
    
    //It gives me pixels/seconds. It gives us the speed of how many pixels move per second based on the frame rate
    pixelsPerTime = pixelsPerFrameRate * ofGetFrameRate();
    

}

//--------------------------------------------------------------
void testApp::update(){


     myRect.pos.x += pixelsPerFrameRate; 
    
    
    
     if( myRect.pos.x >= (ofGetWindowWidth() - 10)){
        
        myRect.pos.x = ofGetWindowWidth() - 10;
    }  
   
 
    myRect.update();
    
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
    
    
    ofDrawBitmapString("Time to get to the end of the screen = " + ofToString((timeToArrive / 60),2) + "Minutes", ofPoint(50, 500));       

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
