#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    //Allows clear updating of vertically on the screen
    ofSetVerticalSync(true);
    ofSetRectMode(OF_RECTMODE_CENTER);

    
    myRect.pos.x = ofRandom(0, ofGetWindowWidth());
    myRect.pos.y = ofRandom(0, ofGetWindowHeight());
    

                     
    
  
    

}

//--------------------------------------------------------------
void testApp::update(){
    
    
    
    if(myRect.posChange == true){
        
        mousePos.x = myRect.posa.x;
        mousePos.y = myRect.posa.y;
        
        
        
    }else if( myRect.posChange == false){
        
        mousePos.x = myRect.posb.x;
        mousePos.y = myRect.posb.y;
        
    }

   myRect.zenoToPoint(mousePos.x , mousePos.y);
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
   
    ofBackgroundGradient(50, 0);
    
    
    
    ofSetColor(255);
    ofSetLineWidth(2);
    ofLine(mousePos.x, mousePos.y, myRect.pos.x, myRect.pos.y);
    myRect.draw();
    

    

    
    
        

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
    
    myRect.posChange = !myRect.posChange;
    posChange = !posChange;
    myRect.update();
    

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
