#include "SquareBall.hpp"

SquareBall::SquareBall() {

    // nothing needed here, because all variables are initialized in parent Ball class
}

void SquareBall::draw() {
    
    ofSetColor(color);    // the color carries over from the parent Ball class

    float sqX = x - dim; // rectangles draw from the top left corner unlike circles (which draw from the center), so we need to compensate
    float sqY = y - dim;
    ofDrawRectangle(sqX, sqY, dim * 0.8, dim * 0.5);  // width and height will both be double the radius
}

