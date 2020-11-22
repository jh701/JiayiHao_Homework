#pragma once
#include "ofMain.h"

class Particle {
    
public:
    
    Particle();
    Particle(glm::vec2 _pos, glm::vec2 _vel, float _mass);
    
    void applyForce(glm::vec2 force);
    void update();
    void draw();
    void drawWater();
    
    glm::vec2 pos, vel, acc;
    float mass;
    ofImage a;
    ofImage b;
    ofImage c;
    ofImage d;
    float bornTime;
    
};
