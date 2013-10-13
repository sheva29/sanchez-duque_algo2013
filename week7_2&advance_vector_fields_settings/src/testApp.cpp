#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    
    gui = new ofxUICanvas();
    gui->setPosition(785, 25);
    gui->setHeight(160);
    
    //Here we create an array on names to pass and then we add it
     string names[6] = { "Single Direction", "Random Direction", "Perlin Noise", "Amplitude Modulation", "Amplitude Modulation II", "Sine"};
    //We use assign to pass the array and its size
    vectorNames.assign(names, names+6);
    
    
    gui->addLabel("Vector Settings");
        gui->addSpacer();
    //We initialize our radio
    gui->addRadio("Vector Settings", vectorNames);
    
    gui->setColorBack(ofColor(255,100));
    gui->setWidgetColor(OFX_UI_WIDGET_COLOR_BACK, ofColor(0,100));
    
    ofAddListener(gui->newGUIEvent, this, &testApp::guiEvent);
    
    gui->loadSettings("guiSettings.xml");
    
    
    
    myField.setup( ofGetWindowWidth(), ofGetWindowHeight(), 15 );
    
   
    
    

}

void testApp::exit(){
    
   delete gui;
}

void testApp::guiEvent(ofxUIEventArgs &e){
    
    string name = e.widget->getName();
    int kind = e.widget->getKind();
    
    if (kind == OFX_UI_WIDGET_TOGGLE) {
        
        ofxUIToggle *settings = ( ofxUIToggle *)e.widget;
        
        
        
        
        cout << name << " value: " << settings->getValue() << endl;
    }
    
    
    
}

//--------------------------------------------------------------
void testApp::update(){
    

    
    
}

//--------------------------------------------------------------
void testApp::draw(){

    ofBackgroundGradient(0, 50, OF_GRADIENT_LINEAR);
    myField.draw();


}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    if( key == '0'){
        
        myField.setSingleDirection();
    
    }else if ( key == '1'){
       
        myField.setRandom();
    
    }else if ( key == '2'){
     
        myField.setPerlin();
        
    }else if ( key == '3'){
        
        myField.setAm();
    }else if ( key == '4'){
        
        myField.setModularAm();
    }else if ( key == '5'){
        
        myField.setSin();
        
    }
    

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
