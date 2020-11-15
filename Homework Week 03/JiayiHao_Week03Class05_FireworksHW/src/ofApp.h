#pragma once

#include "ofMain.h"
#include "Particle.hpp"
#include "ParticleSystem.hpp"
class ofApp : public ofBaseApp{

	public:
        void setup();
        void update();
        void draw();
        void mouseReleased(int x, int y, int button);
        
        ofPoint x;
     
    
        vector<Particle> p;     //Particles
        vector<ParticleSystem> particleSystems;
        ofFbo fbo;              //buffer

        float history;        //determines how long the particles stay on screen
        float time0;          //Time value for computing change in velocity

        float rate;       //Particles born rate per second
        float count;      //Integrated number of particles to born
};
