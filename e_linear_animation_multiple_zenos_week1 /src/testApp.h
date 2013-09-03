//Declares all variables and functions once
#pragma once

//Includes an external file called ofMain.h
#include "ofMain.h"
//Includes the head of the class
#include "rectangle.h"
#define NUM_RECTS 30
#define COLOR_RANGE 255

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void zenoToPoint(float catchX, float catchY);

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        
        float rectSize[NUM_RECTS];
    
        float colorR[COLOR_RANGE];
        float colorG[COLOR_RANGE];
        float colorB[COLOR_RANGE];
    
        float catchUpSpeed[NUM_RECTS], posX[NUM_RECTS], posY[NUM_RECTS];
    
 
		
};
