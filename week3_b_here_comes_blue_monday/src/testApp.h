#pragma once

#include "ofMain.h"
#include "Ball.h"
//Plays our entire song
typedef struct{
    
    ofSoundPlayer song;
    
    void setup(){
        song.loadSound("blue_monday.mp3");
        song.setVolume(1.0f);
        
    }
    void update(){
        
         ofSoundUpdate();
    }
    void draw(){
         song.play();
    }
    
}blueMonday;

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
    
    blueMonday blueMondays;    
    
    vector <Ball> _1Beat;
    vector <Ball> _2Beat;
    vector <Ball> _3Beat;
    
    float songLength;
    bool _click, _ballSizeChecker;
    
    int _1BeatBalls = 2;
    float sinOftime, sinTimeCo;
    
    
    int _2BeatBalls = 6, newBallSize;
    float sinOfTime2, sinTimeCo2;
    
    float savedTime, ballSpacing, ballSpacing2, ballSpacing3;
    
    int _3BeatBalls = 2;
    float sinOftime3, sinTimeCo3;
    
    

		
};
