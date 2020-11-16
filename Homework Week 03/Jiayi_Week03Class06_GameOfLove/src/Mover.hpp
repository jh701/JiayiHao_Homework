#pragma once
#include "ofMain.h"


class Mover {
    
public:
    
    Mover();
    Mover(glm::vec2 _pos, glm::vec2 _vel, float _mass);
    
    void addForce(glm::vec2 force);
    void addRepulsion(Mover mover);
    void addAttraction(Mover mover);
    void addDampingForce(float strength);
    void update();
    void draw();
    void drawHeart();
    void drawStone();
    
    glm::vec2 pos, vel, acc;
    
    ofImage h;
    ofImage s;
};
