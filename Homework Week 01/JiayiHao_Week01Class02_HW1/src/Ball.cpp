//
//  Ball.cpp
//  JiayiHao_Week01Class02_HW1
//
//  Created by Sunny Hao on 11/2/20.
//

#include "Ball.hpp"


Ball::Ball(){
};

void Ball::setup(float _x, float _y, int _dim){
    x = _x;
    y = _y;
    dim = _dim;

    speedX = ofRandom(5, 6);
    speedY = ofRandom(2,3 );
    j = ofRandom(0, 30);
  
        if(j > 15)
        {color.set(54, 17, 89);}
        if(j < 15)
        {color.set(255,165,0);}
        if(j == 15)
        {color.set(30, 0, 0);}
}



void Ball::update(){
    if(x < 0 ){
        x = 0;
        speedX *= -1;
    } else if(x > ofGetWidth()){
        x = ofGetWidth();
        speedX *= -1;
    }

    if(y < 0 ){
        y = 0;
        speedY *= -1;
    } else if(y > ofGetHeight()){
        y = ofGetHeight();
        speedY *= -1;
    }

    x+=speedX;
    y+=speedY;
}

void Ball::draw(){
    ofSetColor(color);
    ofDrawCircle(x, y, dim);
}
