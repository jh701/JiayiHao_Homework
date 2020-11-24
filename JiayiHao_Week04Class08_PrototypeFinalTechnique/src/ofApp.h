#pragma once
#include "ofMain.h"

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();

    ofMesh mesh;        //Mesh
    ofLight light;        //Light
    void addRandomCircle( ofMesh &mesh );
    void drawVineStraight( ofMesh &mesh );
    void drawVineCircular( ofMesh &mesh );
    
    void drawRibbonColor1( ofMesh &mesh );
    void drawRibbonColor2( ofMesh &mesh );

    void keyPressed(int key);
    bool hit;
    bool change;
};

//add normals to the mesh and draws more realistic light
    void setNormals( ofMesh &mesh );
