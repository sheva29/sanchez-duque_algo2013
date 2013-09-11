#pragma once

#include "ofMain.h"

//struct as a mini class
typedef struct {
    
    float timePct; // pct is based on movie position;
    ofPoint pos; // position of the point in x and y
    
} timePoint;

class timeStroke {
public:
    void addPoint(float pct, ofPoint pos){
        //We create a new variable of our struct. And we assign them to our variables int he constructor and add them to our vector
        timePoint temp;
        temp.timePct = pct;
        temp.pos = pos;
        pts.push_back(temp);
    }
    
    void draw(float pct){
        
        if (pts.size() > 0){
            for (int i = 0; i < pts.size()-1; i++){
                if (pts[i].timePct < pct && pts[i+1].timePct < pct){
                    ofLine(pts[i].pos, pts[i+1].pos);
                }
            }
        }
    }
    
    vector < timePoint > pts;
    
};

class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    
    ofVideoPlayer video;
    
    //This class takes our little struct called timePoint. and then a TS class is created
    timeStroke TS;
    vector < timeStroke > strokes;
    
    
};
