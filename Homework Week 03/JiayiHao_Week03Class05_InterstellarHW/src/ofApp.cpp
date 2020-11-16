#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    image.load("images/galaxy.jpg" ); //load background image
    
    glm::vec2 centerScreen =
        glm::vec2(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

    spaceship.mass = 10;
    spaceship.pos  = centerScreen;
    
    for (int i = 0; i < 9; i++ ){
        Particle newParticle = Particle();
        as.push_back(newParticle);
    }
    
    for (int i = 0; i < 9; i++) {
        as[i].mass = 10;
        as[i].pos = centerScreen - glm::vec2(300,0) + glm::vec2(50*i , 0);
    }
    
    a.load("images/a.png");
    b.load("images/b.png");
    c.load("images/c.png");
    d.load("images/d.png");
    e.load("images/e.png");
    
    images.push_back(a);
    images.push_back(b);
    images.push_back(c);
    images.push_back(d);
    images.push_back(e);
    
    for (int i = 0; i < 5; i++){
        Star newStar = Star();
        stars.push_back(newStar);
    }
    
    for (int i = 0; i < 5; i++){
        stars[i].setup(120 + i * 80 - i * 3);
    }
   // star1.setup(200);
    
}

//--------------------------------------------------------------
void ofApp::update(){

    
    float one = stars[2].xpos;
    float two = stars[2].ypos;
    glm::vec2 mousePos = glm::vec2(one, two);
    glm::vec2 diff2 = mousePos - spaceship.pos;
    // attraction force (push in the direction of target)
    spaceship.addForce(diff2 * 0.01);
    spaceship.addDampingForce(0.005);
    spaceship.update();
    
    for (int i = 0; i < 9; i++){
        glm::vec2 mousePos1 = glm::vec2(stars[3].xpos, stars[3].ypos);
        glm::vec2 attraction;
        glm::vec2 dir = mousePos1 - as[i].pos;
        float distance = glm::length(dir);
                
                if (distance > 0 ) {         // avoid dividing by 0!
                    glm::vec2 normalizedDir = dir / distance;      // normalize to get length to 1
                    if (distance < 1000) {
                        attraction = normalizedDir;}}
                        
                        as[i].addForce(10*attraction);
        as[i].addDampingForce(0.05);
        as[i].update();
    }
    
    for (int i = 0; i < 5; i++){
        stars[i].update(ofGetWidth()/2, ofGetHeight()/2);
    }
    
    for( int i = 0; i < moons.size(); i++){
        moons[i].updateMoon(stars[3].xpos, stars[3].ypos);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    image.draw( 0, 0, ofGetWidth(), ofGetHeight());
    sun.load("images/sun.png");
    sun.draw(ofGetWidth()/2 - 70,ofGetHeight()/2 - 70, 140, 140);
    
    ofDrawBitmapString("Press Mouse for Moon and s Key for Danger!", ofGetWidth()/2 , ofGetHeight()/2+150);
    
    spaceship.drawSpacecraft();
    
    if (hit){
    for (int i = 0; i < 9; i++) {
        as[i].draw();
    }}
    
    for (int i = 0; i < 5; i++){
        stars[i].draw();
    }
   // star1.draw();
   // ofPoint location = ofPoint(star1.xpos, star1.ypos);
   // a.draw(location);
    
    a.draw(stars[1].xpos - 40, stars[1].ypos - 40 , 80, 80);
    b.draw(stars[2].xpos - 50, stars[2].ypos - 50 , 100, 100);
    c.draw(stars[3].xpos - 50, stars[3].ypos - 50 , 100, 100);
    d.draw(stars[4].xpos - 60, stars[4].ypos - 60 , 120, 120);
    e.draw(stars[0].xpos - 30, stars[0].ypos - 30 , 60, 60);

  
    for( int i = 0; i < moons.size(); i++){
        moons[i].drawMoon();
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 's') {
        hit = true;
}
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == 's') {
        hit = true;
}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    Star newMoon;
    newMoon.setup(40);
    moons.push_back(newMoon);
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
