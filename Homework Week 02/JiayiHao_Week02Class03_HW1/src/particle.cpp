//
//  particle.cpp
//  JiayiHao_Week02Class03_HW1
//
//  Created by Sunny Hao on 11/4/20.
//

#include "particle.hpp"
#include "ofMain.h"
//------------------------------------------------------------
particle::particle(){
    setInitialCondition(0,0,0,0);
    damping = 0.09f;
}

//------------------------------------------------------------
void particle::resetForce(){
    // we reset the forces every frame
    frc.set(0,0);
}

//------------------------------------------------------------
void particle::addForce(float px, float py, float x, float y){
    // add in a force in X and Y for this frame.
    ofVec2f posOfForce;
    posOfForce.set(px, py);
    ofVec2f diff = pos - posOfForce;
    
    if (diff.length() < 300){
        frc.x = frc.x + 0.01;
        frc.y = frc.y + 0.01;
    }
    if (diff.length() < 250){
        frc.x = frc.x + 0.02;
        frc.y = frc.y + 0.02;
    }
    if (diff.length() < 200){
        frc.x = frc.x + 0.03;
        frc.y = frc.y + 0.03;
    }
    if (diff.length() < 150){
        frc.x = frc.x + 0.05;
        frc.y = frc.y + 0.05;}
    
    if (diff.length() < 80){
        frc.x = frc.x + x;
        frc.y = frc.y + y;}
    }
    
//---------------------------------------------------------------------------------------
void particle::addWeirdForce(float px, float py, float x, float y){
    // add in a force in X and Y for this frame.
    ofVec2f posOfForce;
    posOfForce.set(px, py);
    int u = ofRandom(1,4);
    ofVec2f diff = pos - posOfForce;
    
    if (u == 2) {
    if (diff.length() < 300){
        frc.x = frc.x + 0.01;
        frc.y = frc.y + 0.01;
    }
    if (diff.length() < 250){
        frc.x = frc.x + 0.02;
        frc.y = frc.y + 0.02;
    }
    if (diff.length() < 200){
        frc.x = frc.x + 0.03;
        frc.y = frc.y + 0.03;
    }
    if (diff.length() < 150){
        frc.x = frc.x + 0.05;
        frc.y = frc.y + 0.05;}
    
    if (diff.length() < 80){
        frc.x = frc.x + x;
        frc.y = frc.y + y;}
    }
    else {
        if (diff.length() < 300){
            frc.x = frc.x - 0.01;
            frc.y = frc.y - 0.01;
        }
        if (diff.length() < 250){
            frc.x = frc.x - 0.02;
            frc.y = frc.y - 0.02;
        }
        if (diff.length() < 200){
            frc.x = frc.x - 0.03;
            frc.y = frc.y - 0.03;
        }
        if (diff.length() < 150){
            frc.x = frc.x - 0.05;
            frc.y = frc.y - 0.05;}
        
        if (diff.length() < 80){
            frc.x = frc.x - x;
            frc.y = frc.y - y;}
    }
}

//------------------------------------------------------------
void particle::addDampingForce(){
    
    // the usual way to write this is  vel *= 0.99
    // basically, subtract some part of the velocity
    // damping is a force operating in the oposite direction of the
    // velocity vector
    
    frc.x = frc.x - vel.x * damping;
    frc.y = frc.y - vel.y * damping;
}

//------------------------------------------------------------
void particle::addClockwiseForce( float px, float py, float radius, float strength){
    
    
    ofVec2f posOfForce;
    posOfForce.set(px, py);
    
    ofVec2f diff = pos - posOfForce;
    
    if (diff.length() < radius){
        float pct = 1 - (diff.length() / radius);
        diff.normalize();
        frc.x -= diff.y * pct * strength;
        frc.y += diff.x * pct * strength;
    }
    
}

//------------------------------------------------------------
void particle::setInitialCondition(float px, float py, float vx, float vy){
    pos.set(px,py);
    vel.set(vx,vy);
}

//------------------------------------------------------------
void particle::update(){
    vel = vel + frc;
    pos = pos + vel;
}

//------------------------------------------------------------
void particle::draw(){
    ofCircle(pos.x, pos.y, 5);
}

