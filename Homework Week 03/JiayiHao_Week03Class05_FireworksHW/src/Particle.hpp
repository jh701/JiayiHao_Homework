#ifndef Particle_hpp
#define Particle_hpp

#include <stdio.h>

#endif /* Particle_hpp */
#pragma once
#include "ofMain.h"

class Particle {
        public:
            Particle();//Constructor
    Particle(ofPoint location, float size);
        //Initialize particle
            void update( float dt );   //Calculate new speed with pos (t)  = vel (t) + dt
            void draw();               //Draw particle

            ofPoint pos;               //Position
            ofPoint vel;               //Velocity
            float time;                //Time of living
            float lifeTime;            //Allowed lifetime
            bool exist;                //whether the particle exists
};
