#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    ofBackground(240,248,255);
}


//--------------------------------------------------------------
void ofApp::update(){
    
    }

//--------------------------------------------------------------
void ofApp::draw(){
    if (ofGetMousePressed(OF_MOUSE_BUTTON_LEFT)) {
        
        while (int a = ofRandom(3)){
            if( a == 0 )
            {ofSetColor(0,191,255);}
            if( a == 1 )
            {ofSetColor(100,149,237);}
            if (a == 2 )
            {ofSetColor(0, 0, 255);}
            else
            {ofSetColor(135,206,250);}
        }
        
        ofDrawCircle(ofGetMouseX(), ofGetMouseY(), ofRandom(100));  // Draw a 50 x 50 rect centered over the mouse
        ofNoFill();
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

