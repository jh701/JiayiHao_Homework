//
//  Fracture.hpp
//  JiayiHao_Midterm
//
//  Created by Sunny Hao on 11/22/20.
//

#ifndef Fracture_hpp
#define Fracture_hpp

#include "ofMain.h"
class Fracture {

    public:

    void setup(float _x, float _y);
    void update();
    void draw();

    ofImage f;
    float x;        // position
    float y;
    int dim;        // size
    ofColor color;  // color using ofColor type

    Fracture();  
    private:
};

#endif /* Fracture_hpp */
