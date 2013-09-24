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

