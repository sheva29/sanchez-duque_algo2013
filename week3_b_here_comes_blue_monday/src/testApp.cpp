#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofBackground(0);
    ofSeedRandom();
    //We load our song
    blueMondays.setup();
    _ballSizeChecker = true;
    
    
    //We start some variables
    //The song lasts 4:30 minutes which is the equivalent of 270 seconds. We store that value in a variable
    
    
    savedTime = 0;
    
    sinTimeCo = 2 * PI;
    sinTimeCo2 =  PI;
    sinTimeCo3 = 2 * PI;
    
    
    
    //We add the first set of balls to our vector
    for( int i = 0; i < _1BeatBalls; i++){
        
     
        Ball newBall;
         _1Beat.push_back(newBall);
        //we want to start on the left. the minus is due to the translate 
        _1Beat[i].ballSize = ofRandom( 5, 10 );
        //We want to draw our balls with 50 pixels spacing from each other
        ballSpacing = ((ofGetWindowWidth()/3) / _1BeatBalls) - _1Beat[i].ballSize ;
        _1Beat[0].pos.x = -(ofGetWindowWidth()/2) + (ofGetWindowWidth()/40);
        //Set the position of the other balls in respect to the one before plus the spacing
        _1Beat[i].pos.x = _1Beat[i - 1].pos.x + ballSpacing;        
       
    }
    
    
    //We add our second set of balls to our vector
    for( int i = 0; i < _2BeatBalls; i++){
        
        Ball newBall2;
        _2Beat.push_back(newBall2);
        _2Beat[i].ballSize = ofRandom( 5 , 30 );
        ballSpacing2 = ( ofGetWindowWidth()/3)/ _2BeatBalls;
        _2Beat[0].pos.x = -( ofGetWindowWidth()/ 8 );
        _2Beat[i].pos.x = _2Beat[i - 1].pos.x + ballSpacing2;
       
        
        
    }
    
    //We add our third set of balls to our vector
    for (int i = 0; i < _3BeatBalls; i++){
        
        Ball newBall;
        _3Beat.push_back(newBall);
        _3Beat[i].ballSize = ofRandom( 5, 10);
        ballSpacing3 = ((ofGetWindowWidth()/3) / _1BeatBalls) - _1Beat[i].ballSize ;
        _3Beat[0].pos.x = (ofGetWindowWidth()/5);
        _3Beat[i].pos.x = _3Beat[i - 1].pos.x + ballSpacing3;
        _3Beat[i].pos.y = -(ofGetWindowHeight()/2) + 20;
        
        
    }
    
   
}

//--------------------------------------------------------------
void testApp::update(){

     songLength = ofGetElapsedTimef() - savedTime;

    
    if (_click == true){
        
      
        blueMondays.update();
        
        
///////////First ball movement////////////////////////////////
        
        for( int i = 0; i < _1Beat.size(); i++){
        
            sinOftime = sin(ofGetElapsedTimef() * sinTimeCo);
            _1Beat[i].pos.y = ofMap(sinOftime, -1,  1, 0 , -(ofGetWindowHeight()/2 + 20));
        }
        
    
        if ( songLength >= 33) {
            
            for (int i = 0; i < _1Beat.size(); i++){
                
                _1Beat[i].pos.y = 0;
            }
            
        }
        
        if ( songLength >= 37.25) {
            
            for (int i = 0; i < _1Beat.size(); i++){
                
                sinOftime = sin(ofGetElapsedTimef() * sinTimeCo);
                _1Beat[i].pos.y = ofMap(sinOftime, -1,  1, 0 , -(ofGetWindowHeight()/2 + 20));
            }
            
        }
    
//////////End of First Ball //////////////////////////////////

//////////Second balls Movement///////////////////////////////
        
        //Second balls intro
        if ( songLength >= 1.2){
            
            
            
            for( int i = 0; i < _2Beat.size(); i++){
                
                
                sinOfTime2 = sin( (ofGetElapsedTimef() * sinTimeCo) * 6);
                _2Beat[i].pos.y = ofMap( sinOfTime2, -1, 1, 0, ofGetWindowWidth() / 2);
                
                
            }
        }      
        
        
        if( songLength >= 4){
            
            
            for( int i = 0; i < _2Beat.size(); i++){
                 _2Beat[i].pos.y = 0;
            }
        }
        
        if( songLength >= 5){
            
            
            for( int i = 0; i < _2Beat.size(); i++){
                sinOfTime2 = sin( (ofGetElapsedTimef() * sinTimeCo) * 6);
                _2Beat[i].pos.y = ofMap( sinOfTime2, -1, 1, 0, ofGetWindowWidth() / 2);
            }
        }
        
        if( songLength >= 7.8){
            
            
            for( int i = 0; i < _2Beat.size(); i++){
                _2Beat[i].pos.y = 0;
            }
        }
        
        if( songLength >= 8.8){
            
            
            for( int i = 0; i < _2Beat.size(); i++){
                sinOfTime2 = sin( (ofGetElapsedTimef() * sinTimeCo) * 6);
                _2Beat[i].pos.y = ofMap( sinOfTime2, -1, 1, 0, ofGetWindowWidth() / 2);
            }
        }
        
        if( songLength >= 11.5){
            
            
            for( int i = 0; i < _2Beat.size(); i++){
                _2Beat[i].pos.y = 0;
            }
        }
        
        if( songLength >= 12.2){
            
            
            for( int i = 0; i < _2Beat.size(); i++){
                sinOfTime2 = sin( (ofGetElapsedTimef() * sinTimeCo + PI) * 6);
                _2Beat[i].pos.y = ofMap( sinOfTime2, -1, 1, 0, ofGetWindowWidth() / 2);
            }
        }
        
        if( songLength >= 15.2){
            
            
            for( int i = 0; i < _2Beat.size(); i++){
                _2Beat[i].pos.y = 0;
            }
        }
        
        if( songLength >= 16){
            
            
            for( int i = 0; i < _2Beat.size(); i++){
                sinOfTime2 = sin( (ofGetElapsedTimef() * sinTimeCo) * 6);
                _2Beat[i].pos.y = ofMap( sinOfTime2, -1, 1, 0, ofGetWindowWidth() / 2);
            }
        }
        
        if( songLength >= 19){
            
            
            for( int i = 0; i < _2Beat.size(); i++){
                _2Beat[i].pos.y = 0;
              
            }
        }
        
        if( songLength >= 19.3f){
            
            
            for( int i = 0; i < _2Beat.size(); i++){
                              
                _2Beat[i].pos.x += ofRandom(-5,5);
                _2Beat[i].pos.y += ofRandom(-5,5);
            }
        }
        
        if( songLength >= 33.0f){
            
            if( _ballSizeChecker == true){
            
                newBallSize = 1500;
                for ( int i = 0; i < _2Beat.size(); i++){
                
                    sinOfTime2 = sin( ofGetElapsedTimef() + (PI /2) );
                    _2Beat[i].ballSize = ofMap( sinOfTime2, -1, 1, 0, 2000
                    );
                
                    if( _2Beat[i].ballSize >= 1500 & _ballSizeChecker == true){
                        
                        _2Beat[i].ballSize = newBallSize;
                        //We turned our boolean to false so it stops running ofMap. Since we assigned the new value to newBallSize _2Beat[i] becomes the new static value 1500.
                        _ballSizeChecker = false;
                    }
                }
            }
        }
        
   
        
        
////////////////////////End of Ball2 ///////////////////////
        
///////////////////////Start of Balls3 /////////////////////
        
        for( int i = 0; i < _3Beat.size(); i++){
            
            sinOftime3 = sin(ofGetElapsedTimef() * sinTimeCo3 );
            _3Beat[i].pos.y = ofMap(sinOftime3, -1,  1, -((ofGetWindowHeight()/2) + 20), 0 );
        }
        
        if ( songLength >= 33) {
            
            for (int i = 0; i < _3Beat.size(); i++){
                
                _3Beat[i].pos.y = -(ofGetWindowHeight()/2) + 20;
            }
            
        }
        
        if ( songLength >= 37.25) {
            
            for (int i = 0; i < _3Beat.size(); i++){
                
                sinOftime3 = sin(ofGetElapsedTimef() * sinTimeCo3);
                _3Beat[i].pos.y = ofMap(sinOftime3, -1,  1, -(ofGetWindowHeight()/2 + 20), 0);
            }
            
        }
/////////////////////End of Ball 3/////////////////////////
    
    }//End of the _click statement
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    
    
    ofPushMatrix();{
        
        ofTranslate(ofGetWindowSize()/2);
        
        for( int i = 0; i < _1Beat.size(); i++){
        
        
            
            ofCircle(_1Beat[i].pos , _1Beat[i].ballSize );
            
    }
        
        for( int i = 0; i < _2Beat.size(); i++){            
            
            ofCircle(_2Beat[i].pos, _2Beat[i].ballSize);
        }
        
        for( int i = 0; i < _3Beat.size(); i++){
            
            ofCircle(_3Beat[i].pos, _3Beat[i].ballSize);
        }
   
    }ofPopMatrix(); 
    
    
    ofDrawBitmapString(ofToString(songLength), ofPoint(100,ofGetWindowHeight() * 0.8f));
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

    //Starts the song
    _click = !_click;
    blueMondays.draw();
    //Stores the new time for our timer.
    savedTime = ofGetElapsedTimef();
    
   

    
  
    
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
