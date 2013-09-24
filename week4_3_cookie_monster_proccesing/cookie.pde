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

