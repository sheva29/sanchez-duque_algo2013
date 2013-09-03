#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    //Allows clear updating of vertically on the screen
    ofSetVerticalSync(true);
    

    ofSetRectMode(OF_RECTMODE_CENTER);
    
    for ( int i = 0 ; i < NUM_RECTS; i++){
        
        rectSize[i] = ofRandom(10 , 50);
    }
    
    for ( int i = 0 ; i < COLOR_RANGE; i++){
        
        colorR[i] = ofRandom(0 , 255);
        colorG[i] = ofRandom(0 , 255);
        colorB[i] = ofRandom(0 , 255);
    }
    
    for ( int i = 0; i < NUM_RECTS; i++){
        
        posX[i] = ofRandom(0, ofGetWindowHeight());
        
    }
    
    for ( int i = 0; i < NUM_RECTS; i++){
        
        catchUpSpeed[i] = ofRandom(0.002f, 0.03f);
        
    }
    

}

//--------------------------------------------------------------
void testApp::update(){
    
    float catchX = mouseX;
    float catchY = mouseY;
    
    for ( int i = 0 ; i < NUM_RECTS; i++){
        
        posX[i]= catchUpSpeed[i] * catchX + (1 - catchUpSpeed[i]) * posX[i];
        
        posY[i] = catchUpSpeed[i] * catchY + ( 1 - catchUpSpeed[i]) * posY[i];
        
    }


}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackgroundGradient(255, 200);
    
    for ( int i = 0 ; i < NUM_RECTS; i++){
        
        ofEnableAlphaBlending();
        ofSetColor(colorR[i],colorG[i], colorB[i], 255*0.5);
        
        
        ofRect(posX[i], posY[i], rectSize[i] , rectSize[i]);
        
    }
    
    

}

//--------------------------------------------------------------
void testApp::zenoToPoint(float catchX, float catchY){
    

    
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
