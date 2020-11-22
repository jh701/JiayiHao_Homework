
#include "Particle.hpp"

Particle::Particle()
{
    
    // default constructor:
    // Particle particle = Particle();
    
    pos = glm::vec2(0,0);
    vel = glm::vec2(0,0);
    acc = glm::vec2(0,0);
    
    bornTime = ofGetElapsedTimef();
}

Particle::Particle(glm::vec2 _pos, glm::vec2 _vel, float _mass)
{
    
    // "overload" constructor, alternative:
    // Particle particle = Particle(pos,vel,acc);
    
    pos = _pos;
    vel = _vel;
    mass = _mass;
    
    bornTime = ofGetElapsedTimef();
}

void Particle::applyForce(glm::vec2 force)
{
    acc += force / mass;
}

void Particle::update()
{
    vel += acc;
    pos += vel;
    
}

void Particle::draw()
{
    int value = ofRandom(0, 20);
    
    if (value == 0){
        a.load("body/a.png");
        a.draw(pos);
    }
    
    if (value == 1){
        b.load("body/b.png");
        b.draw(pos);
    }
    if (value == 2){
        c.load("body/c.png");
        c.draw(pos);
    }
    
    if (value == 3){
        d.load("body/d.png");
        d.draw(pos);
    }
    else
    {
      ofPushStyle();
    ofSetColor(173,216,230);
    ofDrawTriangle(pos, pos + glm::vec2(5,5), pos + glm::vec2(-5,-5));
    ofPopStyle();
    }
}

void Particle::drawWater()
{
    ofPushStyle();
    ofSetColor(173,216,230);
    ofDrawCircle(pos, 3);
    ofPopStyle();
}
