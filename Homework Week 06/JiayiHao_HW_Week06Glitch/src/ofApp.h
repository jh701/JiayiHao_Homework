#pragma once
#include "ofMain.h"
//This is an app that changes the color of a loaded video's pixels

class ofApp : public ofBaseApp{
    public:
        void setup();
        void update();
        void draw();
        void keyPressed(int key);
    
        ofVideoPlayer fluid;
        ofImage fimage;
        int array[15];
        int screenW;
        int screenH;
        bool s;
    
        private:
};
