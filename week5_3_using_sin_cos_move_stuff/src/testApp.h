#pragma once



#include "ofMain.h"
#include "ofxUI.h"
#include "Circles.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void exit();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        void guiEvent( ofxUIEventArgs &e);
    
        ofxUICanvas *gui;
    
    vector < Circles > circleList;
    
    int numberOfCircles;
    
    ofColor backColCoe;
    int _trails;
    
    int _red, _green, _blue;
    
    
    
		
};
