#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofBackground(0);
    ofSeedRandom();
    ofEnableAlphaBlending();
    
    carList = new vector < Car >;
    dest = new vector < ofVec2f >;
    
    for( int i = 0; i < NUM_OBJECTS; i++){
        
        addCar();
        addDestination();
     
        cout << dest->size() << endl;
    }
    

}
//--------------------------------------------------------------
void testApp::exit(){
    
    delete carList;
    delete dest;
    
}
//--------------------------------------------------------------
void testApp::addCar(){
    
    ofVec2f _pos = ofGetWindowSize()/2;
    ofVec2f _vel = ofVec2f(ofRandom( -5 , 10));
    ofColor _color = ofColor( 255 );
    
    Car tmp( _pos, _vel, _color);
    carList->push_back(tmp);
    
    
}
//--------------------------------------------------------------
void testApp::addDestination(){
    
    ofVec2f _dest =ofVec2f( ofRandomWidth(), ofRandomHeight());
    dest->push_back(_dest);
    
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    vector<Car>::iterator c1;
    for( c1 = carList->begin(); c1 != carList->end(); c1++){
        
        vector<Car>::iterator c2 = c1 +1;
        
        vector < ofVec2f >::iterator d;
        for( d = dest->begin(); d != dest->end(); d++){
            
            c1->seek(*d);
            
            if( c1->pos.distance(c2->pos)){
                
                c1->color = ofColor( 255, 0 ,0);
                c2->color = ofColor( 255, 0 ,0);
                
                c1->addRepulsionForce(c2->pos);
                c2->addRepulsionForce(c1->pos);
                
            }else{
                
                c1->color = ofColor(255);
                c2->color = ofColor(255);
                
                
            }
            
            c1->update();
            
            
//            if( c1->pos.distance( *d ) < 5){
//                
//                d++;
//            }
            
        }
        
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    vector<Car>::iterator it;
    for( it = carList->begin(); it != carList->end(); it++){
        
        vector< ofVec2f >::iterator d;
        for( d = dest->begin(); d != dest->end(); d++){
            
            ofSetColor( it->color);
            ofCircle( *d, 4);
        }
        
        
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
