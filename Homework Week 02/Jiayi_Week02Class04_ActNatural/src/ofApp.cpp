#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(20);
    pole.set( 2, 100 );
    angle = PI/6;
    ofSetCircleResolution(50);
    polebottom = ofPoint (ofGetWidth()/2, ofGetHeight()/2-150);
    d = 0;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    angle = angle + 0.01;
    if (d < 700 && ofGetElapsedTimef()>2){
        d = d + 0.93 * ofGetElapsedTimef();}
}

//--------------------------------------------------------------
void ofApp::draw(){
    //------------------------------------------------draws the changing sky
    float time = ofGetElapsedTimef();
    float value = sin(time);
    float v = sin(0.85 * time);
    float value1 = ofMap(v, -1, 1, 115, 255);
    float value2 = ofMap(v, -1, 1, 50, 150);
    float value3 = ofMap(value, -1, 1, 200, 255);
    float value4 = ofMap(value, -1, 1, 20, 200);
    ofColor colorOne(255, value1, value2);
    ofColor colorTwo(value3, value3, 255);
    ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_CIRCULAR);
    
    //---------------------------------draws a sun that goes through the sky
    ofSetColor(255,0,0);
    float xpos = ofGetWidth()/2 + 50 + (450 * cos(angle));
    float ypos = 600 - (450 * sin(angle));
        ofDrawCircle(xpos, ypos, 50);
    
    //--------------------------------------draws the changing ocean surface
    ofSetColor(value2, value2, 255);
    ofDrawRectangle(0-(ofGetWidth()/2), ofGetHeight()/2, ofGetWidth()*1.8, ofGetHeight()/2);
    
    ofSetColor(250, 218, 221);
    ofDrawRectangle(ofGetWidth()/2-5, ofGetHeight()/2-155, 20, 300);
    ofSetColor(177, 156, 217);
    ofDrawRectangle(ofGetWidth()/2-10, ofGetHeight()/2-150, 20, 300);
    
    //---------------------------------------------------draws stick's shadow
    ofSetColor(255, 140, 0);
    ofSetLineWidth(20);
    
            ofSetColor(101, 67, 33);
            shadow.clear();
            shadow.addVertex(ofGetWidth()/2 - 10, ofGetHeight()/2+150, 0);
            shadow.addVertex(ofGetWidth()/2 + 12, ofGetHeight()/2+150, 0);
            shadow.addVertex(ofGetWidth()/2 - 300 + d, ofGetHeight()/2+ 150 + 10*sqrt(d), 0);
       shadow.addVertex(ofGetWidth()/2 - 350 + d, ofGetHeight()/2+ 150 + 10*sqrt(d), 0);
            shadow.close();
            ofFill();
            shadow.draw();
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
