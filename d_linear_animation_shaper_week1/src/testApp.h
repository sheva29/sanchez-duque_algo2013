//Declares all variables and functions once
#pragma once

//Includes an external file called ofMain.h
#include "ofMain.h"
//Includes the head of the class
#include "rectangle.h"
#define NUM_CIRCLES 20

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
    
        Rectangle myRect[NUM_CIRCLES];
        float pct;
		
};
