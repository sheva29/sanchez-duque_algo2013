#pragma once

#include "ofMain.h"

class Ball {
  public:
    Ball();

    void update();
    void draw(float posX, float posY);

    ofPoint position;
    ofVec2f velocity, gravity;
};