//
//  Ball.hpp
//  JiayiHao_Week01Class02_HW1
//
//  Created by Sunny Hao on 11/2/20.
//

#ifndef Ball_hpp
#define Ball_hpp

#include <stdio.h>

#endif /* Ball_hpp */

#ifndef _BALL
#define _BALL
#include "ofMain.h" // we need to include this to have a reference to the openFrameworks framework
class Ball {

    public:

    void setup(float _x, float _y, int _dim);
    void update();
    void draw();


    float x;        // position
    float y;
    float speedY;   // speed and direction
    float speedX;
    int j;
    int dim;        // size
    ofColor color;  // color using ofColor type

    Ball();  // constructor - used to initialize an object, if no properties are passed the program sets them to the default value
    private: // place private functions or variables declarations here
}; // don't forget the semicolon!
#endif

