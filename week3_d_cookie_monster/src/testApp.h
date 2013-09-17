#pragma once

#include "ofMain.h"
#include "Cookie Monster.h"
#include "Cookie.h"

//Here we draw the eyes for the cookie monster
typedef struct {
    
    ofPoint pos, mousePos;
    float angle;
    
    
    void draw(){
        
        ofPushMatrix();{
            
            ofTranslate( pos );
            
            float dx = mousePos.x - pos.x;
            float dy = mousePos.y - pos.y;
            
            angle = atan2( dy, dx) ;
            
            ofRotate( ofRadToDeg(angle) );
            
            ofSetColor( 0 );
            ofFill();
            ofCircle( 0, 14, 14);
            
        }ofPopMatrix();
    }
    
//We call it eyeBall
} eyeBall;

typedef struct{
    
    ofSoundPlayer song;
    
    void setup(){
        
        song.loadSound("cookie_sound.mp3");
        song.setVolume(1.0f);
    }
    
    void update(){
        ofSoundUpdate();
        
    }
    
    void draw(){
        
        song.play();
    }
    
    
    
}cookieSound;


class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    cookieMonster newCookieMonster;
    float _accelCoe;
    eyeBall leftEye, rightEye;
    
    cookie newCookie;
    ofPoint newCookiePos;
    
    cookieSound _sound;
    float newDis;
    bool cookieSound;
		
};
