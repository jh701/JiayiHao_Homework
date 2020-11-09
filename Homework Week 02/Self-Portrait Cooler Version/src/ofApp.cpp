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
    ofColor colorOne(208, 240, 192);
    ofColor colorTwo(209, 237, 242);
    ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_LINEAR);
    
    float time = ofGetElapsedTimef();
    float value = sin( time * M_TWO_PI );
    float q = ofMap(value, -1, 1, 115, 255);
    float w = ofMap(value, -1, 1, 193, 251);
    ofSetColor (q, 182, w);
    
    ofDrawRectangle(ofGetWidth()/2-100, ofGetHeight()/2, 200, ofGetHeight()/2);
    
    float v = ofMap( value, -1, 1, 220, 250 );
    float b = ofMap( value, -1, 1, 150, 220 );
    float n = ofMap( value, -1, 1, 115, 196 );
    ofSetColor(v,b,n); //draws face
    ofDrawEllipse(center, 400, 370);
    
    ofSetColor(255, 255, 255); //draws "eyes"
    ofSetLineWidth(8);
    ofDrawLine(ofGetWidth()/2 + 90, 285, ofGetWidth()/2 + 90, 310);
    ofDrawLine(ofGetWidth()/2 + -90, 285, ofGetWidth()/2 - 90, 310);
    
    ofSetColor(255, 182, 193);
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
