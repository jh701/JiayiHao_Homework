#pragma once
#include "ofMain.h"
#include "Particle.hpp"

class ParticleSystem {
public:
    
    // we are now using C++ constructors --
    
    // constructors are functions like setup(), but they run automatically
    // when the object is created in our app
    
    // -- note: constructors do not have a return type
    
    ParticleSystem();                   // default
    ParticleSystem(glm::vec2 _pos);     // "overload" / alternative
    
    void applyForce(glm::vec2 force);   // applies force to particles
    
    void update(int numNewParticles = 10, int maxParticles = 1000);
    
    void update1(int numNewParticles = 10, int maxParticles = 100);
    
    void draw();
    void drawWater();
    
    glm::vec2 pos;                      // origin of the particle system
    
    vector<Particle> particles;
    vector<Particle> particles1;
};
