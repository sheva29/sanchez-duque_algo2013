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

