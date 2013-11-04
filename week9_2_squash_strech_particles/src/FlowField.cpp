#include "FlowField.h"

FlowField::FlowField() {
    
}

void FlowField::setup( int width, int height, int res ){
    
    fieldWidth = width;
    fieldHeight = height;
    resolution = res;
    
    int cols = fieldWidth  / resolution;
    int rows = fieldHeight  / resolution;
    
    for( int y=0; y<rows; y++){
        VectorList myList;
        flowList.push_back( myList );
        
        for( int x=0; x<cols; x++){
            //This determines the length of the vector
//            ofVec2f dir(10,0);
//            flowList[y].push_back( dir );
            
            //We set our vector to amplitude modulation
            ofVec2f dir;
            dir.set(2 * cos( 2 * cos(x)), 2 * cos( 2 * sin(x)));
            flowList[y].push_back(dir * 10);
        }
    }
}

void FlowField::setRandom( const float &strength ) {
    for( int y=0; y<flowList.size(); y++){
        for( int x=0; x<flowList[y].size(); x++){
            flowList[y][x].set( ofRandom(-1,1) * strength, ofRandom(-1,1) * strength );
        }
    }
}

void FlowField::setPerlin() {
    for( int y=0; y<flowList.size(); y++){
        for( int x=0; x<flowList[y].size(); x++){
            float noise = ofMap( ofNoise(x*0.05, y*0.05), 0, 1, 0, TWO_PI);
            flowList[y][x].set( ofVec2f( cos(noise), sin(noise) ) * 20);
        }
    }
}

void FlowField::setAM(){
    for( int y = 0; y < flowList.size(); y++){
        for( int x = 0; x < flowList[y].size(); x++){
            
            ofVec2f dir;
            
            dir.set(2 * cos( 2 * cos(x)), 2 * cos( 2 * sin(x)));
            flowList[y][x].set( dir * 20);
            
        }
    }
    
}

void FlowField::update() {
    for( int y=0; y<flowList.size(); y++){
        for( int x=0; x<flowList[y].size(); x++){
            //This sets the damping in our Vector Field
//            flowList[y][x] *= 0.99;
            
            if( flowList[y][x].length() < 1.0){
                flowList[y][x].normalize();
            }
            
        }
    }
}

void FlowField::setInWardForce() {
    
    ofVec2f center( (ofGetWindowWidth() / 2) - resolution, (ofGetWindowHeight() / 2) - resolution);
    float strength = 1200;
    for( int y = 0; y < flowList.size(); y++){
        for(int x = 0; x < flowList[y].size(); x++){
            
            ofVec2f np ( x * resolution,  y * resolution);
            
           ofVec2f dir = ( center - np);
            dir.normalize();
            flowList[y][x].set(dir * strength);

        
        }
    }
}

void FlowField::setOutWardForce(){
    
    ofVec2f center( (ofGetWindowWidth() / 2) - resolution, (ofGetWindowHeight() / 2) - resolution);
    float strength = 1200;
    for( int y = 0; y < flowList.size(); y++){
        for(int x = 0; x < flowList[y].size(); x++){
            
            ofVec2f np ( x * resolution,  y * resolution);
            
            ofVec2f dir = ( np - center);
            dir.normalize();
            flowList[y][x].set(dir * strength);
            
            
        }
    }
    
    
}

ofVec2f FlowField::getForcePostion(ofVec2f pos){
    
    float pctX = pos.x / fieldWidth;
    float pctY = pos.y / fieldHeight;
    
    int cols = fieldWidth / resolution;
    int rows = fieldHeight/resolution;
    
//    int cols = flowList[0].size();
    
    int xVal = ofClamp( pctX * cols, 0, cols -1);
    int yVal = ofClamp( pctY * rows, 0 , rows -1);
    
    ofVec2f newPos;
    newPos.set( flowList[yVal][xVal] );
    
    return newPos;
    
    
    //    //Terniary operator
    //    int result = ( 4 < 5) ? 4: 5;
    
    
}

void FlowField::addRepelForce(float x, float y, float radius, float strength) {
    
    
    ofVec2f mousePos(x, y);
    
    for( int y=0; y<flowList.size(); y++){
        for( int x=0; x<flowList[y].size(); x++){
            ofVec2f np( x*resolution, y*resolution );
            
            if( np.distance(mousePos) < radius ){
                float pct = 1 - (np.distance(mousePos) / radius);
                
                // add strength in the direction it's already moving in
                //flowList[y][x] += flowList[y][x].normalized() * strength;
                
                // add strength away from the mouse
                ofVec2f dir = (np - mousePos);
                flowList[y][x] += dir.normalized() * strength;
            }
        }
    }
}

void FlowField::addAttractForce(float x, float y, float radius, float strength) {
    
    
    ofVec2f mousePos(x, y);
    
    for( int y=0; y<flowList.size(); y++){
        for( int x=0; x<flowList[y].size(); x++){
            ofVec2f np( x*resolution, y*resolution );
            
            if( np.distance(mousePos) < radius ){
                float pct = 1 - (np.distance(mousePos) / radius);
                
                // add strength against the direction it's already moving in
                //                flowList[y][x] -= flowList[y][x].normalized() * strength;
                
                // add strength towards the mouse
                ofVec2f dir = (np - mousePos);
                flowList[y][x] -= dir.normalized() * strength;
            }
        }
    }
}

void FlowField::addCircularForce(float x, float y, float radius, float strength) {
    
    
    ofVec2f mousePos(x, y);
    
    for( int y=0; y<flowList.size(); y++){
        for( int x=0; x<flowList[y].size(); x++){
            ofVec2f np( x*resolution, y*resolution );
            
            if( np.distance(mousePos) < radius ){
                float pct = 1 - (np.distance(mousePos) / radius);
                
                // add strength towards the mouse
                ofVec2f dir = (np - mousePos);
                flowList[y][x].x -= dir.normalized().y * strength;
                flowList[y][x].y += dir.normalized().x * strength;
            }
        }
    }
}

void FlowField::addSineForce(float x, float y, float radius, float strength){ 
    
    
    ofVec2f mousePos (x, y);
    
    for( int y = 0; y < flowList.size(); y++){
        for( int x = 0; x < flowList[y].size(); x++){
            
            ofVec2f np ( x * resolution, y * resolution);
            
            if( np.distance(mousePos) < radius){
                
                ofVec2f dir;
                dir.set( sin(x), sin(y));
                flowList[y][x] += dir;
                
                
            }
            
        }
    
    }
    
}

void FlowField::addModularAmplitudeForce(float x, float y, float radius, float strength){
    
    ofVec2f mousePos( x,y);
    
    for( int y = 0; y < flowList.size(); y++){
        for( int x = 0; x < flowList[y].size(); x++){
            
            ofVec2f np ( x * resolution, y * resolution);
            
            if( np.distance(mousePos) < radius){
                
                ofVec2f dir;
                dir.set(2 * cos( 2 * cos(x)), 2 * cos( 2 * sin(x)));
                flowList[y][x] += dir;
            
            
            }
            
        }
    
    }
    
}

void FlowField::draw() {
    
    ofSetColor(255);
    for( int y=0; y<flowList.size(); y++){
        for( int x=0; x<flowList[y].size(); x++){
            ofVec2f np( x*resolution, y*resolution );
            drawVectorAt( flowList[y][x], np, flowList[y][x].length() );
        }
    }
}

void FlowField::drawVectorAt( const ofVec2f &vec, const ofVec2f &pos, const float &strength ) {
    ofVec2f np = pos;
    drawVector( np, np + vec.normalized() * strength, 5, 3 );
}

void FlowField::drawVector( const ofVec3f &start, const ofVec3f &end, float headLength, float headRadius ) {
	const int NUM_SEGMENTS = 32;
	float lineVerts[3*2];
	ofVec3f coneVerts[NUM_SEGMENTS+2];
	glEnableClientState( GL_VERTEX_ARRAY );
	glVertexPointer( 3, GL_FLOAT, 0, lineVerts );
	lineVerts[0] = start.x;
    lineVerts[1] = start.y;
    lineVerts[2] = start.z;
	lineVerts[3] = end.x;
    lineVerts[4] = end.y;
    lineVerts[5] = end.z;
	glDrawArrays( GL_LINES, 0, 2 );
	
	// Draw the cone
	ofVec3f axis = ( end - start ).normalized();
    ofVec3f temp = ( axis.dot( ofVec3f(0,1,0) ) > 0.999f ) ? axis.crossed( ofVec3f(1,0,0) ) : axis.crossed( ofVec3f(0,1,0) );
	ofVec3f left = ofVec3f(axis.crossed( temp )).normalized();
	ofVec3f up = axis.crossed( left ).normalized();
    
	glVertexPointer( 3, GL_FLOAT, 0, &coneVerts[0].x );
	coneVerts[0] = ofVec3f( end + axis * headLength );
	for( int s = 0; s <= NUM_SEGMENTS; ++s ) {
		float t = (float)s / (float)NUM_SEGMENTS;
		coneVerts[s+1] = ofVec3f( end + left * headRadius * cos( t * 2.0f * 3.14159f )
                                 + up * headRadius * sin( t * 2.0f * 3.14159f ) );
	}
	glDrawArrays( GL_TRIANGLE_FAN, 0, NUM_SEGMENTS+2 );
    
	// draw the cap
	glVertexPointer( 3, GL_FLOAT, 0, &coneVerts[0].x );
	coneVerts[0] = end;
	for( int s = 0; s <= NUM_SEGMENTS; ++s ) {
		float t = s / (float)NUM_SEGMENTS;
		coneVerts[s+1] = ofVec3f( end - left * headRadius * (float)cos( t * 2 * 3.14159f )
                                 + up * headRadius * (float)sin( t * 2 * 3.14159f ) );
	}
	glDrawArrays( GL_TRIANGLE_FAN, 0, NUM_SEGMENTS+2 );
    
	glDisableClientState( GL_VERTEX_ARRAY );
}

