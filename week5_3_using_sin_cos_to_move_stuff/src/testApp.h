#pragma once

#include "ofMain.h"
//#define yValues_SIZE 8

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
    
    int xSpacing;
    int w;
    
    float theta;
    float amplitude;
    float period;
    float dx;
    float yValues[8];
    
    //we use a new int to declare the size of our initial yValues
    int yValues_SIZE = sizeof(yValues) / sizeof(yValues[0]);

    
    void calculateWave();
    void renderWave();
    
    
		
};
