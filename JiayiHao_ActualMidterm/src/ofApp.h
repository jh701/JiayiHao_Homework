#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "Fracture.hpp"
#include "Particle System.hpp"
#include "Particle.hpp"

class ofApp : public ofBaseApp{

  public:
    void setup();
    void update();
    void draw();

    void keyPressed  (int key);
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
    
    //this is our model we'll draw
    ofxAssimpModelLoader model;
    ofxAssimpModelLoader model1;
    
    ofLight light;
    ofEasyCam Cam;
    ofImage image;
    ofImage f;
    ofImage image1;
    ofImage back;
    ofImage body2;
    ofPolyline Rwaist;
    ofPolyline Lwaist;
    bool changemode;
    bool changescreen;
    
    vector<Fracture> fractures;
    vector<ParticleSystem> particleSystems;
    vector<ParticleSystem> waterSystems;
    ParticleSystem hole;
    
    
    //we added these functions to make it easier to switch between the two methods of drawing
    void drawWithModel();
    void drawWithMesh();
    bool hit;
    glm::vec2 gravity;

};
