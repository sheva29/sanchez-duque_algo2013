#include "Cookie Monster.h"

cookieMonster::cookieMonster(){
    
    _cookieMonster.loadImage("cookie_monster.png");
    
    cookieCoe = ofPoint(215/2, 207/2);
    
}

void cookieMonster::zenoToCookie(ofVec2f _mousePos, float _accelCoe){
    
    //We substract both vectors so that it does not quite get to the position. The farther they are the fastast the monster gets to the cookie but as close it gets the slower it gets.
    acce = (_mousePos - (pos + cookieCoe)) * _accelCoe;
    
    vel += acce;
    
    pos += vel;
    
    //The closer it starts getting the slower it becomes
    vel *= 0.95f;
    
}

void cookieMonster::draw(){
    
     _cookieMonster.resize(215, 207);
    _cookieMonster.draw(pos);
   
}







