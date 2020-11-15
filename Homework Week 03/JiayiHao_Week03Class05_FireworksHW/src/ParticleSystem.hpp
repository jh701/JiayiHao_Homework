#pragma once
#include "ofMain.h"
#include "Particle.hpp"

class ParticleSystem {
public:
    
    ParticleSystem();
    ParticleSystem( ofPoint location);
    
    void update(int maxParticles = 1000);
    void draw();
    
    ofPoint pos;
    
    vector<Particle> p;
    float history;        //determines how long particles stay on screen
    float time0;          //Time value for computing dt

    float rate;       //rate of particles generated per second
    float count;      //number of particles generated
};
