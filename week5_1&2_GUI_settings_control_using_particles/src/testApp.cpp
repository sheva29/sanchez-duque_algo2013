#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetBackgroundAuto(true);
    ofEnableAlphaBlending();
  
 
    //Let's do our GUI elements
    
    //We initiate our pointer
    gui = new ofxUICanvas;
    gui->addLabel("Controller");
    gui->addSpacer();
    gui->addToggle("Shape", false);
    //We give the GUI background a bit of transparency
    gui->setColorBack(ofColor(0, 50));
    gui->setWidgetColor(OFX_UI_WIDGET_COLOR_BACK, ofColor(0));
    //This one controls the size of my particles
    gui->addSlider("particleSize",0, 10,2);
    
    //This one controls the rotation on my particles
    gui->addSlider("particleAngle",0,45,1);
    
    ofAddListener(gui->newGUIEvent, this, &testApp::onGuiEvent);

    gui->loadSettings("guiSettings.xml");
    
    
    //Let's work with our image
    
    bitchPls.loadImage("rdjr.jpg");
    
    int xRes = floor( bitchPls.getWidth()  / 20.0 );
    int yRes = floor( bitchPls.getHeight() /  20.0 );
    
    for ( int x = 0; x < xRes; x++){
        for( int y = 0; y < yRes; y++){
            
            addParticle(x,y);
            
        }
    }
    
    ofPopMatrix();
    
    

    
    
}

//--------------------------------------------------------------
void testApp::exit(){
    
    gui->saveSettings("guiSetting.xml");
    delete gui;
    
}

//--------------------------------------------------------------
void testApp::onGuiEvent(ofxUIEventArgs &e){
    
    string name = e.widget->getName();
    int kind = e.widget->getKind();
    
    if( name == "Shape"){
        
        
        ofxUIButton*shape = ( ofxUIButton *)e.widget;
        cout << name << "\t value: " << shape->getValue() << endl;
        
        vector< Particles >::iterator p;
        for( p = imgParticles.begin(); p != imgParticles.end(); p++){
            
            p->_drawingCir = shape->getValue();
            
            
            
        }
    }else if( name == "particleSize"){
        
        ofxUISlider *particleSize = (ofxUISlider *)e.widget;
        
     
        vector < Particles >::iterator it;
        for( it = imgParticles.begin(); it != imgParticles.end(); ++it){
            
            //Here we assigned our value to the  size slider
            it->rectSizeMax = particleSize->getScaledValue();
            
          //  cout << " Got a message!" << name << " - " << particleSize->getValue() << endl;
        }
        
    }else if( name =="particleAngle"){
        
        
        ofxUISlider *particleAngle = ( ofxUISlider *)e.widget;
        
     
        for( int i = 0; i < imgParticles.size(); ++i){
            
            imgParticles[i]._angle = particleAngle->getScaledValue();
            
        }
        
    }
   
    
    
}
//--------------------------------------------------------------
void testApp::addParticle(float x, float y){
    
//    float xPos = (x + 0.5f) * 10.0;
//    float yPos = (y + 0.5f) * 10.0;
    
    //We multiply the position based on how many times we divded the length so that it fits
    float xPos = x * 20;
    float yPos = y * 20;
    
    Particles tmp( ofVec2f( xPos, yPos));
    imgParticles.push_back(tmp);
    
    
}

//--------------------------------------------------------------
void testApp::update(){
   
    vector< Particles >::iterator it;
    for( it = imgParticles.begin(); it != imgParticles.end(); ++it){
        
        (*it).update(bitchPls);
    }
    
    
//    for( int i =0; i < imgParticles.size(); i++){
//        
//        imgParticles[i].update( bitchPls/*, rectMax*/ );
//    }
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    //    for( vector<Particles>::iterator it = imgParticles.begin(); it < imgParticles.end(); it++){
    //
    //        (*it).draw(bitchPls);
    //    }
    
    //
    
    vector<Particles>::iterator it;
    for( it = imgParticles.begin(); it != imgParticles.end(); ++it){
            
//            ofRotate(45);
            it->draw();
        
        
    }

    
//    for( int i = 0; i < imgParticles.size(); i++){
//        
//        imgParticles[i].draw();
//    }

    
    
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
