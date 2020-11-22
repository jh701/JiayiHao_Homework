//
//  Fracture.cpp
//  JiayiHao_Midterm
//
//  Created by Sunny Hao on 11/22/20.
//

#include "Fracture.hpp"

Fracture::Fracture(){
};

void Fracture::setup(float _x, float _y){
    x = _x;
    y = _y;
}

void Fracture::update(){
    f.load("body/hole.png");
}

void Fracture::draw(){
    f.draw(x, y);
}
