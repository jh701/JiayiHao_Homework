#include "Star.hpp"

Star::Star(){
};

//void Star::setup(int _radius, ofImage image){
void Star::setup(int _radius){
    radius = _radius;
    speed = ofRandom(0, 0.8);
    xpos = 0;
    ypos = 0;
    //planet = image;
}

void Star::update(float a, float b){
    time = ofGetElapsedTimef();
    angle = ofMap (time, -1, 1, 0, speed*PI);
    xpos = a + (radius * cos(angle));
    ypos = b - (radius * sin(angle));
}

void Star::updateMoon(float a, float b){
    time = ofGetElapsedTimef();
    angle = ofMap (time, -1, 1, -2*PI, 2*PI);
    xpos = a + (radius * cos(angle));
    ypos = b - (radius * sin(angle));
}

void Star::draw(){
   // planet.draw(xpos, ypos);
    ofDrawCircle(xpos, ypos, 20);
}

void Star::drawMoon(){
    moon.load("images/moon.png");
    moon.draw(xpos-13, ypos-13, 26, 26);
}


