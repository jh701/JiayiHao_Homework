#include "ofApp.h"
#define NBALLS 10

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(ofColor::purple);
    
    for(int i=0; i<15; i++){

        int size = (i+1) * 10; // defining the size of each ball based on its place in the array
        int randomX = ofRandom( 0, ofGetWidth() ); //generate a random value bigger than 0 and smaller than our application screen width
        int randomY = ofRandom( 0, ofGetHeight() ); //generate a random value bigger than 0 and smaller than our application screen height

        groupOfBall[i].setup(randomX, randomY, size);
        groupOfSBalls[i].setup(randomX, randomY, size);
    }

}


//--------------------------------------------------------------
void ofApp::update(){
    for(int i=0; i<15; i++){
        groupOfBall[i].update();
        groupOfSBalls[i].update();
    }
    
    for (int i = 0; i<groupOfBalls.size(); i++) {
        groupOfBalls[i].update();
    }
    }

//--------------------------------------------------------------
void ofApp::draw(){
    
    for(int i=0; i<15; i++){
        groupOfBall[i].draw();
        groupOfSBalls[i].draw();
    }
    
    for (int i = 0 ; i<groupOfBalls.size(); i++) {
        groupOfBalls[i].draw();
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
        Ball tempBall;                            // create the ball object
       tempBall.setup(x,y,ofRandom(10,40));    // setup its initial state
       groupOfBalls.push_back(tempBall);                // add it to the vector
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    groupOfBalls.clear();
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
