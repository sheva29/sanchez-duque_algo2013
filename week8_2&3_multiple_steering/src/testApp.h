#pragma once

#include "ofMain.h"
#include "Car.h"
#define NUM_OBJECTS 1000

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void exit();
        void addCar();
        
    
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    vector < Car > *carList;
    
    
   
    
    
		
};
