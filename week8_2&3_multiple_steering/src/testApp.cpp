#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofBackground(0);
    ofSeedRandom();
    ofEnableAlphaBlending();
    
    carList = new vector < Car >;
    
    
    for( int i = 0; i < NUM_OBJECTS; i++){
        
        addCar();
    }
    

}
//--------------------------------------------------------------
void testApp::exit(){
    
    delete carList;
    
}
//--------------------------------------------------------------
void testApp::addCar(){
    
    ofVec2f _pos = ofGetWindowSize()/2;
    ofVec2f _vel = ofVec2f(ofRandom( -5 , 10));
    ofColor _color;
    _color.setHsb(ofRandom(255), 255, 255);
    ofVec2f _dest =ofVec2f( ofRandom( ofGetWindowWidth()), ofRandom( ofGetWindowHeight()));
    
    Car tmp( _pos, _vel, _color, _dest);
    carList->push_back(tmp);    
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    vector<Car>::iterator c1;
    vector<Car>::iterator c3 = carList->begin();
    std::advance(c3, 4);
    for( c1 = carList->begin(); c1 != carList->end(); c1++, c3++){
        
        c1->seek(c1->dest);
        
        vector<Car>::iterator c2 = c1 + 1;
        
        if( c1->pos.distance(c2->pos) < 100){
            
            
//            c1->color = ofColor( 255,0,0);
//            c2->color =ofColor( 255,0,0);
            
            c1->addRepulsionForce(c2->pos);
            c2->addRepulsionForce(c1->pos);
            
            
        }else{
            
//            c1->color = ofColor(255);
//            c2->color = ofColor(255);
            
           
        }
        
        if(c1->pos.distance(c1->dest) < 5){
            
            c1->dest = ofVec2f( ofRandom( ofGetWindowWidth()), ofRandom(ofGetWindowHeight()));
            
            
        }
        
        c1->update();
        
        
        
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    vector <Car>::iterator it;
    for( it = carList->begin(); it != carList->end(); it++){
        
        ofSetColor(it->color);
        ofCircle(it->dest, 1.5);
        
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
