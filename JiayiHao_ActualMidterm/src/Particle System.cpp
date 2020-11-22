#include "Particle System.hpp"

ParticleSystem::ParticleSystem()
{
    pos = glm::vec2(0,0);       // default value
}

ParticleSystem::ParticleSystem(glm::vec2 _pos)
{
    pos = _pos;                 // assigned value
}

void ParticleSystem::applyForce(glm::vec2 force)
{
    // add the force to all particles
    
    for (int i=0; i<particles.size(); i++)
    {
        particles[i].applyForce(force);
    }
}

void ParticleSystem::update(int numNewParticles, int maxParticles)
{
    
    for (int i=0; i<numNewParticles; i++)
    {
        glm::vec2 vel   = glm::vec2(ofRandom(-6,6), ofRandom(1,3));
        float mass      = ofRandom(.01, 5);
        Particle particle = Particle(pos,vel,mass);
        particles.push_back(particle);
    }
    
    // update particles:
    
    for (int i=0; i<particles.size(); i++)
    {
        particles[i].update();
    }
    
    // erase old particles:
    
    while (particles.size() > maxParticles)
    {
        particles.erase(particles.begin());
        
//        particles.pop_back();
        
        
//        vector<Particle>::iterator first = particles.begin();
//        auto other = particles.begin();
//
//        auto second = particles.begin() + 3;
//        auto end    = particles.end();
    }
}

void ParticleSystem::update1(int numNewParticles, int maxParticles)
{
    
    for (int i=0; i<numNewParticles; i++)
    {
        glm::vec2 vel   = glm::vec2(ofRandom(-1,-1), ofRandom(-1,2));   // move down
        float mass      = ofRandom(.01, 5);
        Particle particle = Particle(pos,vel,mass);     
        particles1.push_back(particle);
    }
    
    // update particles:
    
    for (int i=0; i<particles1.size(); i++)
    {
        particles1[i].update();
    }
    
    // erase old particles:
    
    while (particles1.size() > 100)
    {
        particles1.erase(particles1
                         .begin());     // erase the oldest particle
        
//        particles.pop_back();
        
        
//        vector<Particle>::iterator first = particles.begin();
//        auto other = particles.begin();
//
//        auto second = particles.begin() + 3;
//        auto end    = particles.end();
    }
}

void ParticleSystem::draw()
{
    for (int i=0; i<particles.size(); i++)
    {
        particles[i].draw();
    }
}

void ParticleSystem::drawWater()
{
    for (int i=0; i<particles.size(); i++)
    {
        particles[i].drawWater();
    }
}

