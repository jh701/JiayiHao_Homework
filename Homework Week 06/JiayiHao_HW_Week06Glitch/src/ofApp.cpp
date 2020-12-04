#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(50);
    
    fluid.loadMovie( "fluid.mp4" ); //loads a video from bin
    fluid.play(); //play video
    
    screenW = ofGetWidth(); //initialize screen's width & height
    screenH = ofGetHeight();
    s = false; //initialize the boolean that controls mode switch
    

    //initialize an array that gives the pixels in video random colors
    for ( int i = 0; i < 15; i++ ) {
        array[i] = ofRandom( 0, 255 );
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    fluid.update();
    
    if ( fluid.isFrameNew() ) {
        ofPixels pixel = fluid.getPixelsRef();

        //Go through every pixel in frames, render them random rbg values from the array of ints, and store values in ofPixel object pixel
        for (int y = 0; y < pixel.getHeight(); y++) {
            for (int x=0; x < pixel.getWidth(); x++) {
                
                ofColor c = pixel.getColor( x, y );

                c.r = array[ (c.r / 15) ];
                c.g = array[ (c.g / 15) ];
                c.b = array[ (c.b / 15) ];

                pixel.setColor( x, y, c );
            }
        }

        //draw image using the pixel data stored
        fimage.setFromPixels( pixel );
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if (s == false){
        fluid.draw(0,0, screenW, screenH);}
    
    if (s == true){
        
    ofBackground( 255, 255, 255 );    //Set white background
    ofSetColor( 255, 255, 255 );
    fimage.draw(0,0, screenW, screenH );
    }
    
    ofDrawBitmapString("Press ‘1’ for original video and '2' for glitch mode", 10 , 20);
    ofDrawBitmapString("Every mode switch changes graphics' color", 10 , 30);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == '2') {
            s = true;
        
            for ( int i = 0; i < 15; i++ ) {
                array[i] = ofRandom( 0, 255 );
            }
        
        }
    if (key == '1') {
            s = false;
        }
}

//--------------------------------------------------------------
