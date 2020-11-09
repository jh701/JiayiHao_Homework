//
//  particle.hpp
//  JiayiHao_Week02Class03_HW1
//
//  Created by Sunny Hao on 11/4/20.
//

#ifndef particle_hpp
#define particle_hpp
#include "ofMain.h"
#include <stdio.h>

class particle
{
    public:
        ofVec2f pos;
        ofVec2f vel;
        ofVec2f frc;   
            
        particle();
        virtual ~particle(){};

        void resetForce();
        void addForce(float px, float py, float x, float y); //adds a wind force to the particles
        void addDampingForce(); // adds damping force to particles
        void addClockwiseForce( float px, float py, float radius, float strength);
        void addWeirdForce (float px, float py, float radius, float strength); //adds a "strange" wind force that makes the particles go both towards the upper left and bottom right corners of the window
        void setInitialCondition(float px, float py, float vx, float vy); //initializes the particles
        void update();
        void draw();
    
    
        float damping;

    protected:
    private:
};

#endif /* particle_hpp */
