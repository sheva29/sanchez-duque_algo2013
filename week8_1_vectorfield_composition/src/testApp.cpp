#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    myField = new FlowField;
    
   
    myField->setup(ofGetWindowWidth(), ofGetWindowHeight(), 20 );
   
    
    ofBackground(0);

}

//--------------------------------------------------------------

void testApp::exit(){
    
    delete myField;
    
}
void testApp::update(){

    myField->update();
}

//--------------------------------------------------------------
void testApp::draw(){

    
    myField->draw();
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
    
    if( button == OF_MOUSE_BUTTON_1){
        
        //Use different type of forces
//        myField->addRepelForce(x, y, 200, 2.0);
        
        //Given in class
//        myField->addCircularForce(x, y, 300, 2.0);
       
        //Sine force
//        myField->addSineForce(x, y, 150, 2.0);
        
        //Amplitude Modulation
        myField->addModularAmplitudeForce(x, y, 200, 2.0);
        
    }else{
        myField->addAttractForce(x, y, 100, 2.0);
        
    }

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
