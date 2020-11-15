//
//  Particle.cpp
//  JiayiHao_Week03Class05_FireworksHW

#include "Particle.hpp"

ofPoint randomDirection( float value ){
    ofPoint rDir;
    float rad = ofRandom( 0, value );
    float angle = ofRandom( 0, 2*PI );
    rDir.x = cos( angle ) * rad;
    rDir.y = sin( angle ) * rad;
    return rDir;
}
//-------------------------------------------------------------
Particle::Particle() {
    exist = false;
    pos = ofPoint(ofGetMouseX(),ofGetMouseY()) + randomDirection(20);
    vel = randomDirection( 500 );
    time = 0;
    lifeTime = 0.5;
    exist = true;
}

Particle::Particle(ofPoint location, float size) {
    pos = location + randomDirection(20);
    vel = randomDirection( size );
    time = 0;
    lifeTime = 0.5;
    exist = true;
}

//--------------------------------------------------------------
void Particle::update( float dt ){
    if ( exist ) {

        pos += vel * dt; //Update pos

     //updates time and determines if particle should still exist
        time += dt;
        if ( time >= lifeTime ) {
            exist = false;
        }
    }
}

//--------------------------------------------------------------
void Particle::draw(){
    if ( exist ) {
        float size = ofMap(fabs(time - lifeTime/2), 0, lifeTime/2, 3, 1 );


        ofColor color = ofColor::blue;
        float hue = ofMap( time, 0, lifeTime, 150, 255 );
        color.setHue( hue );
        ofSetColor( color );

        ofCircle( pos, size );  //Draw particle
    }
}
