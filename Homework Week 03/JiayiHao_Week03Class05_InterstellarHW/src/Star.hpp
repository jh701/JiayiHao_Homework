

#ifndef Star_hpp
#define Star_hpp

#pragma once
#include "ofMain.h"
#endif /* Star_hpp */


class Star {
    
public:
    
    Star();
    //void setup(int _radius, ofImage image);
    void setup(int _radius);
    void update(float a, float b);
    void updateMoon(float a, float b);
    void draw();
    void drawMoon();
    
    glm::vec2 pos;
    int radius;
    float speed;
    int size;
    ofImage planet;
    ofImage moon;
    float angle;
    float time;
    float xpos;
    float ypos;
};
