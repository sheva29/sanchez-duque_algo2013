#include "Ball.h"


Ball::Ball() {
        
    velocity.x = 3;
    velocity.y = 3;
        
    //Let's drop the ball from a high position
    position.x = ofGetWindowWidth() / 5;
    position.y = ofGetWindowHeight() / 5;
    
    ofSetRectMode( OF_RECTMODE_CENTER );
    
    gravity.y = 0.1f;
}

void Ball::update() {
    
    velocity += gravity;
    
    position += velocity;
        
    
    if( position.x > ofGetWindowWidth() - 10){
        velocity.x = -velocity.x;
        position.x = (ofGetWindowWidth() - 10);
        
    }else if(position.x < 10){
        
        velocity.x = -velocity.x;
        position.x = 10;
        
    }
    
    if( position.y > ofGetWindowHeight() - 10){
        
        velocity.y = velocity.y * -0.8000f;
        velocity.x = velocity.x * .99f;//Friction or dragging on the X axis when touching the ground
        position.y =(ofGetWindowHeight() - 10);
    }else if( position.y < 10){
      
        velocity.y = velocity.y * -0.8f;
        position.y = 10;
        
        
    }
    

}

void Ball::draw(float posX, float posY){
    
    position.x = posX;
    position.y = posY;
    
    
    ofSetColor(255, 0, 255);
    ofCircle(position, 20);
}