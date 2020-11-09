#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
        ofSetFrameRate(50);
        
        
        for (int i = 0; i < 2000; i++){
            particle myParticle;
            myParticle.setInitialCondition(ofRandom(0,1000),ofRandom(0,1000),0,0);
            myParticle.damping = ofRandom(0.01, 0.05);
            particles.push_back(myParticle);
        }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < particles.size(); i++){
         particles[i].resetForce();}
   
        for (int i = 0; i < particles.size(); i++){
            particles[i].addForce(j, z, 0.1, 0.1);
            particles[i].addClockwiseForce(ofGetMouseX(), ofGetMouseY(), 60, 0.1);
        }
            
        for (int i = 0; i < particles.size(); i++){
            particles[i].update();}
     j = j +20;
     z = z + 20;
}

        
          
//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255 ,ofRandom(150,200),150);
        for (int i = 0; i < particles.size(); i++){
            particles[i].draw();
}
}

//--------------------------------------------------------------
    void ofApp::keyPressed(int key){
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    for (int i = 0; i < particles.size(); i++){
         particles[i].resetForce();}
    int q = ofGetMouseX();
    int w = ofGetMouseY();

        for (int i = 0; i < particles.size(); i++){
            particles[i].addWeirdForce(q, w, 0.1, 0.1);
        }
            
        for (int i = 0; i < particles.size(); i++){
            particles[i].update();}
     j = j +20;
     z = z + 20;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    particles.clear();
    for (int i = 0; i < 2000; i++){
        particle myParticle;
        myParticle.setInitialCondition(ofRandom(0,1000),ofRandom(0,1000),0,0);
        myParticle.damping = ofRandom(0.01, 0.05);
        particles.push_back(myParticle);
    }
    }

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    for (int i = 0; i < particles.size(); i++){
         particles[i].resetForce();}
    int q = ofGetMouseX();
    int w = ofGetMouseY();
    
        for (int i = 0; i < particles.size(); i++){
            particles[i].addForce(q, w, 0.1, 0.1);
        }
            
        for (int i = 0; i < particles.size(); i++){
            particles[i].update();}
}

//-------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
}

