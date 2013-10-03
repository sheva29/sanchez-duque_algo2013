#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetBackgroundAuto(true);
    
    //Let's do our GUI elements
    
    //We initiate our pointer
    gui = new ofxUICanvas;
    gui->addLabel("Controller");
    gui->addSpacer();
    gui->addButton("makeRound", false, 44,44);
    gui->setColorBack(ofColor(0));
    gui->setWidgetColor(OFX_UI_WIDGET_COLOR_BACK, ofColor(255,100));
    gui->addSlider("particleSize",0, 10,5);
    
    ofAddListener(gui->newGUIEvent, this, &testApp::onGuiEvent);

    gui->loadSettings("guiSettings.xml");

    
    
    
    //Let's work with our image
    bitchPls.loadImage("rdjr.jpg");
    
    int xRes = 50;//*floor( bitchPls.getWidth()  / 8/*/ 20.0 */);
    
    int yRes = 40;//floor( bitchPls.getHeight() / 8/* / 20.0 */ ) ;
    
    for ( int x = 0; x < xRes; x++){
        for( int y = 0; y < yRes; y++){
            
            addParticle(x,y);
            
        }
    }

    
    
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
    
    if( name == "particleSize"){
        
        ofxUISlider *particleSize= (ofxUISlider *)e.widget;
        
        vector < Particles >::iterator it;
        for( it = imgParticles.begin(); it != imgParticles.end(); ++it){
            
            
            
            it->rectSizeMax = particleSize->getScaledValue();
            
            cout << " Got a message!" << name << " - " << particleSize->getValue() << endl;
        }
        
    }
    
    
}
//--------------------------------------------------------------
void testApp::addParticle(float x, float y){
    
    float xPos = (x + 0.5f) * 10.0;
    float yPos = (y + 0.5f) * 10.0;
    
    Particles tmp( ofVec2f( xPos, yPos));
    imgParticles.push_back(tmp);
    
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    for( int i =0; i < imgParticles.size(); i++){
        
        imgParticles[i].update( bitchPls );
    }
    
    
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
