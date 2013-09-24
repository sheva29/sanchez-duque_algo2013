Monster cookieMonster;
Cookie newCookie;

Eye leftEye;
PVector leftEyePos;

Eye rightEye;
PVector rightEyePos;

float accelCoe;
PVector mousePos;

void setup() {
  //We set some properties for our sketch
  size(1024, 768);
  background(0);
  smooth();
  imageMode(CENTER);
  //Let's set some variables for the cookie monster

  mousePos= new PVector(0, 0);
  accelCoe = 0.008;
  cookieMonster = new Monster(width/2, height/2, random(3), random(3));

  //We draw our cookie
  newCookie = new Cookie();
  
  //We draw our eyes
  
  leftEye = new Eye();
  leftEyePos = new PVector(0,0);
  
  rightEye = new Eye();
  rightEyePos = new PVector(0,0);
  

  
}

void update() {

  mousePos.x = mouseX;
  mousePos.y = mouseY;

  cookieMonster.zenoToCookie( mousePos, accelCoe);
  
  leftEyePos.x = cookieMonster.pos.x - (215/2);
  leftEyePos.y = cookieMonster.pos.y - (207/2);
  
  rightEyePos.x = cookieMonster.pos.x - (215/2);
  rightEyePos.y = cookieMonster.pos.y - (207/2);
  

}



void draw() {
  background(255);
  update();
  cookieMonster.display( mousePos );
  newCookie.display( mousePos);
  imageMode(CORNER);
  leftEye.display( leftEyePos.x + 85, leftEyePos.y + 36);
  rightEye.display( rightEyePos.x + 137, rightEyePos.y + 40);
}

class Cookie {


  PImage realCookie;

  Cookie () {

    realCookie = loadImage("cookie.png");
    realCookie.resize(25 * 2, 25 * 2);
  }

  void display( PVector pos) {
    
//    imageMode(CENTER);
    image(realCookie, pos.x, pos.y);
    
  }
}

class Eye {

 

  Eye ( ) {
    
   
  }



  void display( float posX, float posY) {
    
    
    pushMatrix();

    translate( posX, posY );
    
      float dx = mouseX - posX;
      float dy = mouseY - posY;
      float angle = 0;
      
      angle = atan2(dx, dy);
      
      rotate( angle  );
      
      color( 0 );
      fill(0);
      ellipse( 0 , 14 , 28 , 28);
      
     popMatrix();
     
  }
}

class Monster {

  PVector vel, acce, pos;
  PImage cookie;
  float cookieScale = 0.0;

  Monster(int _posX, int _posY, float _velX, float _velY ) {

    cookie =  loadImage("cookie_monster2.png");
    pos = new PVector( _posX, _posY);
    vel = new PVector( _velX, _velY);
    acce = new PVector( 0, 0);
    cookie.resize(215, 207);
  }

  void zenoToCookie(PVector _mousePos, float _accelCoe) {

    acce.x = (_mousePos.x - pos.x) * _accelCoe;
    acce.y = (_mousePos.y - pos.y) * _accelCoe;

    vel.x += acce.x;
    vel.y += acce.y;

    pos.x += vel.x;
    pos.y += vel.y;

    vel.x *= 0.95;
    vel.y *= 0.95;
    

  } 

  void display( PVector _mousePos ) {
    cookieScale = dist(_mousePos.x, _mousePos.y, pos.x, pos.y) / 100.0;
    cookieScale = constrain( cookieScale, 0.2, 2.0 );
    cookieScale = map( cookieScale, 0.2, 2.0, 1.5, 0.6);

    //    switch(frameCount%3) {
    //    case 0: 
    //      tint(255, 0, 0);
    //      break;
    //    case 1: 
    //      tint(0, 0, 255);
    //      break;
    //    case 2: 
    //      tint(255, 255, 0);
    //      break;
    //    }

    image(cookie, pos.x - (215/2), pos.y - (207/2) /*int(215.0 * cookieScale), int(207.0 * cookieScale) */);
  }
}


