#pragma once

#include "Ball.hpp"
#include "ofMain.h"

class SquareBall : public Ball {  // SquareBall class **inherits** from Ball class

public:

    SquareBall();

    virtual void draw(); // this will **override** the draw function inherited from Ball

};
