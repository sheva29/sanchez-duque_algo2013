//Taken from Jia Xu's exercise Fire works https://github.com/xuj428/algo2013_xujia/tree/master/week%204/Firework2

#pragma once

#include "ofMain.h"
#include "Fireworks.h"


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
    void addFireworks(ofVec3f pos, float setVel, float hue);
    
    vector <Fireworks> fireworksList;
    
    ofVec3f pos;
    float setVel;
    float hue;
    ofColor backC;
    
    ofEasyCam camView;
		
};
