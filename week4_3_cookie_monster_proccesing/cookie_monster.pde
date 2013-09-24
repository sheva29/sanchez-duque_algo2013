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

