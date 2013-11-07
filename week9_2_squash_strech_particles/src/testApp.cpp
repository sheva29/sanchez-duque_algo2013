#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(0);
    ofSeedRandom();
    
    myField = new FlowField;
    
    particleList = new vector< Particle>;
    
    particleList->clear();
    
    
    myField->setup(ofGetWindowWidth(), ofGetWindowHeight(), 20 );
    
    vectField = false;
    
    for( int i = 0; i < NUM_OF_PARTICLES; i++){
        
        addParticle();
    }
    
    
}

//--------------------------------------------------------------

void testApp::exit(){
    
    delete myField;
    delete particleList;
    
    
}

void testApp::addParticle(){
    
    Particle  tmp;
    tmp.pos = ofVec2f( ofRandomWidth(), ofRandomHeight());
    particleList->push_back(tmp);
    
    
    
}
void testApp::update(){
    
    myField->update();
    
    
    vector< Particle>::iterator it;
    for( it = particleList->begin(); it != particleList->end(); it++){
        
        it->applyForce(myField->getForcePostion(it->pos) * 0.005);
        it->update();
        
        if( it->pos.x < 0 ){
            
            it->pos.x = ofGetWindowWidth();
            
        
        }
        
        if( it->pos.x > ofGetWindowWidth() ){
            
            it->pos.x = 0;
        }
        
        
        if( it->pos.y < 0){
            
            it->pos.y = ofGetWindowHeight();
        }
        
        if( it->pos.y > ofGetWindowHeight()){
            
            it->pos.y = 0;
        }
    }
    
    
    
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    
    if( vectField){
        
        myField->draw();
        
    }
    
    vector< Particle >::iterator it;
    for ( it = particleList->begin(); it != particleList->end(); it++){
        
        it->draw();
    }
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    if( key == '1'){
        
        myField->setPerlin();
    }
    
    if( key == '2'){
        
        myField->setRandom();
    }
    
    if ( key == '3'){
        
        myField->setAM();
    }
    
    if(  key == '4'){
        
        myField->setInWardForce();
    }
    
    if( key == '5'){
        
        myField->setOutWardForce();
    }
    
    if( key == 'F' || key == 'f'){
        
        vectField = !vectField;
    }
    
    if( key =='r' || key == 'R'){
        
        setup();
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
    
    if( button == OF_MOUSE_BUTTON_1){
        
        //Use different type of forces
        //        myField->addRepelForce(x, y, 200, 2.0);
        
        //Given in class
        //        myField->addCircularForce(x, y, 300, 2.0);
        
        //Sine force
        myField->addSineForce(x, y, 150, 2.0);
        
        //Amplitude Modulation
        //        myField->addModularAmplitudeForce(x, y, 200, 2.0);
        
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
