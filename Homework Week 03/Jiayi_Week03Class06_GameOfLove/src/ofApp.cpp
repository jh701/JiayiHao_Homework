#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //mover1.pos = glm::vec2(300,400);
    cupidt.load("images/cupidt.png");
    cupidb.load("images/cupidb.png");
    heart.load("images/heart.png");
    center = glm::vec2(ofGetWidth()/2, ofGetHeight()/2);
    
    for (int i = 0; i < 9; i++ ){
        Mover newMover = Mover();
        movers.push_back(newMover);
    }
    
    for (int i = 0; i < 9; i++) {
        movers[i].pos = center - glm::vec2(20*i,0) - glm::vec2(0 , 10*i);
    }
    
    for (int i = 0; i < 9; i++ ){
        Mover newStone = Mover();
        stones.push_back(newStone);
    }
    
    for (int i = 0; i < 9; i++) {
        stones[i].pos = center - glm::vec2(20*i,0) - glm::vec2(0 , 10*i);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < 9; i++){
            glm::vec2 mousePos1 = glm::vec2(ofGetWidth()/2+100, ofGetHeight()/2+100);
            glm::vec2 attraction;
            glm::vec2 dir = mousePos1 - movers[i].pos;
            float distance = glm::length(dir);
        
            glm::vec2 posOfForce;
            glm::vec2 diff = movers[i].pos - mousePos1;
            float difference = glm::length(diff);
            
            if (distance > 0 ) {
            glm::vec2 normalizedDir = dir / distance;
            if (distance < 1000) {
                attraction = normalizedDir;}}
                    movers[i].addForce(2*attraction);
                    movers[i].addDampingForce(0.05);
                    movers[i].update();
        
            if (difference < 100){
                float pct = 1 - (difference/100);
                diff = diff/difference;
                
                movers[i].addForce(diff * pct *4);
                movers[i].update();
            }
    }
    
    for (int i = 0; i < 9; i++){
            glm::vec2 mousePos1 = glm::vec2(ofGetWidth()/2-100, ofGetHeight()/2-100);
            glm::vec2 attraction;
            glm::vec2 dir = mousePos1 - stones[i].pos;
            float distance = glm::length(dir);
        
            glm::vec2 posOfForce;
            glm::vec2 diff = stones[i].pos - mousePos1;
            float difference = glm::length(diff);
            
            if (distance > 0 ) {
            glm::vec2 normalizedDir = dir / distance;
            if (distance < 1000) {
                attraction = normalizedDir;}}
                    stones[i].addForce(attraction);
                    stones[i].addDampingForce(0.05);
                    stones[i].update();
        
            if (difference < 100){
                float pct = 1 - (difference/100);
                diff = diff/difference;
                
                stones[i].addForce(diff * pct *4);
                stones[i].update();
            }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
        ofColor colorOne(255, 255, 255);
        ofColor colorTwo(248, 24, 148);
        ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_CIRCULAR);
    
    cupidt.draw(0,0);
    cupidb.draw(690,455);
    heart.draw(ofGetWidth()/2-160, ofGetHeight()/2-128,320,256);
    
    if (hiit){
    for (int i = 0; i < 9; i++) {
        ofSetColor(255,255,255);
        movers[i].drawHeart();
    }}
    
    
    if (hit){
    for (int i = 0; i < 9; i++) {
        ofSetColor(255,255,255);
        stones[i].drawStone();
    }}
    
    ofSetColor(255,0,0);
    ofDrawBitmapString("Press s for dart and l for love!", ofGetWidth()/2 - 125 , ofGetHeight()/2-150);
    
    ofDrawBitmapString(" Love will repel stones", ofGetWidth()/2 - 100 , ofGetHeight()/2-130);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 's') {
        hit = true;}
    if(key == 'l') {
        hiit = true;
    }
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
