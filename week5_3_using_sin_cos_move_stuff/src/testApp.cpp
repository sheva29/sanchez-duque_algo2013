#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();
    
    
    gui = new ofxUICanvas;
    gui->addLabel("Circles Controlers");
    gui->addSpacer();
    gui->addSlider("Circles Coefficient", 1, 40, 1);
    gui->addSlider("Circles Trail",0, 100, 10);
    gui->addSlider("Red", 0, 255, 20);
    gui->addSlider("Green", 0, 255, 20);
    gui->addSlider("Blue", 0, 255, 20);

    
    gui->setColorBack(ofColor(10,50));
    gui->setWidgetColor(OFX_UI_WIDGET_COLOR_BACK, ofColor(200));
    
    
    
    ofAddListener(gui->newGUIEvent, this, &testApp::guiEvent);
    
    
    
    backColCoe = 255;
    numberOfCircles = 1;
    
    
    for( int i = 0; i < numberOfCircles; i++){
        
        Circles tmp;
        circleList.push_back(tmp);
    }
    
}
//--------------------------------------------------------------
void testApp::exit(){
    
    delete gui;
    
}
//--------------------------------------------------------------
void testApp::guiEvent(ofxUIEventArgs &e){
    
    string name = e.widget->getName();
    int kind = e.widget->getKind();
    
    if (name == "Circles Coefficient"){
        
        
        ofxUISlider *coe = ( ofxUISlider*)e.widget;
        
        vector<Circles>::iterator it;
        for( it = circleList.begin(); it != circleList.end(); it++){
            
            it->coeVariable = coe->getScaledValue();
            
        }
        
    }else if (name == "Circles Trail"){
        
        ofxUISlider *trails = (ofxUISlider *)e.widget;
        
        _trails = trails->getScaledValue();
        
    }else if (name == "Red"){
        
        ofxUISlider *red = (ofxUISlider *)e.widget;
        
        _red = red->getScaledValue();
    
    }else if (name == "Green"){
        
        ofxUISlider *green = (ofxUISlider *)e.widget;
        
        _green = green->getScaledValue();
    }
    else if (name == "Blue"){
        
        ofxUISlider *blue = (ofxUISlider *)e.widget;
        
        _blue = blue->getScaledValue();
    }
    
    
}

void testApp::update(){
    
    
    
    
    vector<Circles>::iterator it;
    for( it = circleList.begin(); it != circleList.end(); ++it){
        
        
        it->update();
        
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofEnableAlphaBlending();
    ofFill();
    ofSetColor(backColCoe, _trails);
    ofSetRectMode(OF_RECTMODE_CORNER);
    
    ofRect(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    
    
    vector<Circles>::iterator it;
    for( it = circleList.begin(); it != circleList.end(); ++it){
        
        
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofSetColor(_red, _green,_blue);
        ofNoFill();
        it->draw();
        
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
