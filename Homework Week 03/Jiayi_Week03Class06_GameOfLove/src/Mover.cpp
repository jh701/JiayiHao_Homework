

#include "Mover.hpp"

Mover::Mover()
{
    pos = glm::vec2(0,0);
    vel = glm::vec2(0,0);
    acc = glm::vec2(0,0);
}

Mover::Mover(glm::vec2 _pos, glm::vec2 _vel, float _mass)
{
    pos = _pos;
    vel = _vel;
}

void Mover::addForce(glm::vec2 force)
{
    acc += force;
}

void Mover::addAttraction(Mover mover)
{
    glm::vec2 mousePos1 = glm::vec2(ofGetWidth()/2, ofGetHeight()/2);
    glm::vec2 attraction;
    glm::vec2 dir = mousePos1 - mover.pos;
    float distance = glm::length(dir);
            
            if (distance > 0 ) {
                glm::vec2 normalizedDir = dir / distance;
                if (distance < 1000) {
                    attraction = normalizedDir;}}
                        mover.acc += 10*attraction;
}

void Mover::addRepulsion(Mover mover)
{
    glm::vec2 mousePos1 = glm::vec2(ofGetWidth()/2, ofGetHeight()/2);
    glm::vec2 repulsion;
    glm::vec2 dir = mousePos1 - mover.pos;
    float distance = glm::length(dir);
            
            if (distance > 0 ) {
                glm::vec2 normalizedDir = dir / distance;
                if (distance < 100) {           // repulsion
                    repulsion = -normalizedDir;
                    mover.acc += 10*repulsion;}
                }
}

void Mover::addDampingForce(float strength)
{
    float length = glm::length(vel);
    if (length != 0){                       // prevent illegally dividing by zero if vel is 0
        acc -= vel / length * strength;     // drag
    }
}

void Mover::update()
{
    vel += acc;
    pos += vel;
    acc *= 0;
}

void Mover::draw()
{
    ofPushStyle();
    //float hue = ofMap(mass, 0, 10, 0, 255);
    ofSetColor(ofColor::fromHsb(255,255,255));
    ofDrawCircle(pos, 20);
    ofPopStyle();
}

void Mover::drawHeart()
{
    
    h.load("images/h.png");
    h.draw(pos, 50, 50);
}

void Mover::drawStone()
{
    s.load("images/s.png");
    s.draw(pos, 50, 50);
}

