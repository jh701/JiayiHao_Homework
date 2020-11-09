#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void ofApp::update(){
    center = ofPoint (ofGetWidth()/2, 300);
    ofSetCircleResolution(50);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    float time = ofGetElapsedTimef();
    float value = sin( time * M_TWO_PI );
    float v = ofMap( value, -1, 1, 50, 200 );
    ofBackground( v, 100, 200);
    
    ofSetColor(229,203,144); //draws face
    ofDrawEllipse(center, 400, 370);
    
    ofSetColor(255, 255, 255); //draws "eyes"
    ofSetLineWidth(8);
    ofDrawLine(ofGetWidth()/2 + 90, 285, ofGetWidth()/2 + 90, 310);
    ofDrawLine(ofGetWidth()/2 + -90, 285, ofGetWidth()/2 - 90, 310);
    
    ofDrawTriangle(ofGetWidth()/2, 400, ofGetWidth()/2-15, 380, ofGetWidth()/2+15, 380); //draws mouth
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
    ofColor colorOne(208, 240, 192);
    ofColor colorTwo(209, 237, 242);
    ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_LINEAR);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
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
