#pragma once

#include "ofMain.h"
#include "Particle.hpp"
#include "Star.hpp"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    Particle spaceship;
    Particle another;
    ofImage image;
    ofImage sun;
    ofImage spacecraft;
    vector<Star> stars;
    vector<Star> moons;
    ofImage a;
    ofImage b;
    ofImage c;
    ofImage d;
    ofImage e;
    vector<ofImage> images;
    vector<Particle> as;
    
    Star star1;
    bool hit;
    
    ofTrueTypeFont myfont;
};
