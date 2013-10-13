// Taken from Matt Richard's open processing sketch http://www.openprocessing.org/sketch/1012


#pragma once
#include "ofMain.h"


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
    int yValues_length;
    
    float theta;
    float amplitude;
    float period;
    float dx;
    float yValues[1000];
    
    int coeVariable;
    
    
    //we use a new int to declare the size of our initial yValues


    
    void calculateWave();
    void renderWave();
    
    
		
};
