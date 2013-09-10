#include "Rectangle.h"

Rectangle::Rectangle() {
    ofRectMode( OF_RECTMODE_CENTER );
    
    //This is the starting position of our squares.
    pos =ofGetWindowSize() / 2;
    
    //We want to have several values for our velocity so we set them to random.
    velocity.x = ofRandom(-3.0, 3.0);
    velocity.y = ofRandom(-3.0, 3.0);    
    
    
}

void Rectangle::xenoToPoint(ofVec2f _mousePos, float _accelCoe){

  
    //Here is where the magic starts to happen. Our acceleration will start decreasing based on the position of the squares the closer it gets the slower the acceleration goes. Now since we are going to have squares also following each other. We need to set a coefficient of acceleration(_accelCoe) that will allow us to give each square a random acceleration. We also need it cause otherwise it will be very fast for the squares.
    accel = (_mousePos - pos) * _accelCoe;
    
    //So here is the trick. In certain position the acceleration will increase, specially when the position of the mouse to the square is very far from eachothers.
    velocity += accel;
    
    //Velocity is now a value that is affected by the speed, which in turn will affect the position of the squares at different rates.
    pos += velocity;
    
    //This 0.95f removes a 0.05f to the original speed for purposes of dragging when we accelerate.
    velocity *= 0.95f;

}


void Rectangle::draw() {
    
    ofSetColor(255 * (pos.y / ofGetHeight() ), 0, 0 );
    
    ofRect( pos, 20,20 );
}