#include "ofApp.h"

void ofApp::setup(){
    ofSetFrameRate( 90 );

    int w = ofGetWidth();
    int h = ofGetHeight();
    fbo.allocate( w, h, GL_RGB32F_ARB );

    fbo.begin();
    ofBackground(255, 255, 255);
    fbo.end();

    history = 0.8;
    rate = 400;
    count = 0;
    time0 = ofGetElapsedTimef();
    
}
//--------------------------------------------------------------
void ofApp::update(){
    //Compute dt
    float time = ofGetElapsedTimef();
    float dt = ofClamp( time - time0, 0, 0.1 );
    time0 = time;

    //make inactive particles decay
    int i=0;
    while (i < p.size()) {
        if ( !p[i].exist ) {
            p.erase( p.begin() + i );
        }
        else {
            i++;
        }
    }

    //Generate new particles
    count += dt * rate;
    if ( count >= 1 ) {
        int bornN = int( count );//How many generated
        count -= bornN;
        for (int i=0; i<bornN; i++) {
            Particle newP;
            newP = Particle();
            p.push_back( newP );
        }
    }

    for (int i=0; i<p.size(); i++) {
        p[i].update( dt );
    }
    
    for (int i=0; i<particleSystems.size(); i++){
        particleSystems[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    fbo.begin();
    ofEnableAlphaBlending();

    float alpha = (1-history) * 255;
    ofSetColor( 255, 255, 255, alpha );
    ofFill();
    ofRect( 0, 0, ofGetWidth(), ofGetHeight() );

    ofDisableAlphaBlending();        //Disable transparency

    //Draw the particles
    ofFill();
    for (int i=0; i<p.size(); i++) {
        p[i].draw();
    }

    fbo.end();

    
    ofSetColor(255, 255, 255);
    fbo.draw( 0, 0 );
    

    for (int i=0; i<particleSystems.size(); i++){
        particleSystems[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    particleSystems.push_back( ParticleSystem(ofPoint(x,y)));
}
