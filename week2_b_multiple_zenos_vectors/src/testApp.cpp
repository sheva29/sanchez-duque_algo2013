#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    //We set the size of our vector to 5
    for( int i=0; i<5; i++ ){
        
        Rectangle myRect;
        rectList.push_back( myRect);
        
        
        
        
    }
    
    for( int i = 0; i < 5; i++){
        
        accelCoe[i] = ofRandom(0.001f,0.005f);
    }
}

//--------------------------------------------------------------
void testApp::update(){

//    if( rectList.size() ){
//        rectList[0].xenoToPoint(mouseX, mouseY);
//    }
    
    
    for( int i=0; i<rectList.size(); i++ ){
        
        rectList[i].mousePos.x = mouseX;
        rectList[i].mousePos.y = mouseY;
        
        
        if( i==0 ){
            rectList[i].xenoToPoint(rectList[i].mousePos ,accelCoe[i] );
        }else{
            rectList[i].xenoToPoint(rectList[i - 1].mousePos, accelCoe[i]);
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    for( int i=0; i<rectList.size(); i++ ){
        rectList[i].draw();
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
