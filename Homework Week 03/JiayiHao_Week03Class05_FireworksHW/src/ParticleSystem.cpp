//
//  ParticleSystem.cpp
//  JiayiHao_Week03Class05_FireworksHW
//
//  Created by Sunny Hao on 11/15/20.
//

#include "ParticleSystem.hpp"

ParticleSystem::ParticleSystem()
{
    pos = ofPoint(ofGetMouseX(), ofGetMouseY());       // default value
    history = 0.8;
    rate = 400;
    count = 0;
    time0 = ofGetElapsedTimef();
}


ParticleSystem::ParticleSystem( ofPoint pos )
{
    pos = ofPoint(ofGetMouseX(), ofGetMouseY());
    for (int i=0; i<p.size(); i++)
    {
        p[i] = Particle(pos, ofRandom(50,500));
    }// default value
    history = 0.8;
    rate = 400;

    count = 0;
    time0 = ofGetElapsedTimef();
}

void ParticleSystem::update(int maxParticles)
{
    float time = ofGetElapsedTimef();
    float time0 = 0;
    float dt = ofClamp( time - time0, 0, 0.1 );
    time0 = time;
    
    //Delete inactive particles
    int i=0;
    while (i < p.size()) {
        if ( !p[i].exist ) {
            p.erase( p.begin() + i );
        }
        else {
            i++;
        }
    }

    //Born new particles
    count += dt * rate;
    if ( count >= 1 ) {
        int bornN = int( count );
        count -= bornN;
        for (int i=0; i<bornN; i++) {
            Particle newP;
            newP = Particle();           
            p.push_back( newP );
        }
    }

    //Update the particles
    for (int i=0; i<p.size(); i++) {
        p[i].update( dt );
    }
    
}

void ParticleSystem::draw()
{
    for (int i=0; i<p.size(); i++)
    {
        p[i].draw();
    }
}

