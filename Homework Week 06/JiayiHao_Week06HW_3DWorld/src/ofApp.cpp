#include "ofApp.h"

vector<ofPoint> centers;
vector<ofPoint> centers1;
vector<ofPoint> centers2;
int CircleNum1;        //The number of spheres
int CircleNum2;
int CylinderNum;

//--------------------------------------------------------------
void ofApp::setup() {
    s = false;
    
    CircleNum1 = 40;
    CircleNum2 = 30;
    CylinderNum = 15;
    
    ofDisableArbTex();
    ofLoadImage(mTex,"candy.jpg");
    ofLoadImage(mTex2, "corn.png");
    ofLoadImage(mTex1, "candy1.jpg");
    ofLoadImage(mTex3, "choco.jpg");
    
    
    sunlight.setDirectional();
    sunlight.setPosition(100,100,-400);
    sunlight.lookAt(glm::vec3(0));
    sunlight.setDiffuseColor( ofColor::wheat);
    

    float Rad = 250;
    float rad = 25;


    centers.resize( 40 );
    for (int i=0; i<CircleNum1; i++) {
        ofPoint center( ofRandom( -1, 1 ),ofRandom( -1, 1 ),ofRandom( -1, 1 ) );
        center.normalize();
        center *= Rad;
        centers[i] = center + ofPoint( ofRandom (-rad, rad));
    }
    
    centers1.resize( 30 );
    for (int i=0; i<CircleNum2; i++) {
        ofPoint center( ofRandom( -1, 1 ),ofRandom( -1, 1 ),ofRandom( -1, 1 ) );
        center.normalize();
        center *= 400;
        centers1[i] = center + ofPoint( ofRandom (-50, 50));
    }
    
    centers2.resize( 20 );
    for (int i=0; i<20; i++) {
        ofPoint center( ofRandom( -1, 1 ),ofRandom( -1, 1 ),ofRandom( -1, 1 ) );
        center.normalize();
        center *= 500;
        centers2[i] = center + ofPoint( ofRandom (-200, 50));
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    float time = ofGetElapsedTimef();
    if(s){
        for (int i=0; i<CircleNum1; i++) {
        centers[i] += ofPoint(5, 5);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackgroundGradient(ofColor::fireBrick, ofColor(255,204,204));
    ofDrawBitmapString("Welcome to Candy World!", 10 , 30);
    ofDrawBitmapString("Press '2' for good taste and happy candy corns", 10 , 20);
    
    
    ofPushMatrix();
    cam.begin();
    ofEnableDepthTest();


    float time = ofGetElapsedTimef();
    float angle = time * 10;
    ofRotate( angle, 0, 1, 0 );

    
    for (int i=0; i<CircleNum1; i++) {
        mTex.bind();
        ofSpherePrimitive sphere;
        sphere.setPosition(centers[i]);
        sphere.setRadius(16);
        sphere.draw();
        mTex.unbind();
        
        mTex1.bind();
        ofSpherePrimitive sphere1;
        int a = ofRandom(-1, 1);
        int b = 50;
        
        if (a>0){
            b = -50;
        }
        
        sphere1.setPosition(centers[i] + ofPoint (20, b, b));
        sphere1.setRadius(30);
        sphere1.draw();
        mTex1.unbind();
    }
    
    ofRotate( angle, 1, 0, 0 );
    
    for (int i=0; i<CircleNum2; i++) {
        mTex2.bind();
        ofConePrimitive cone;
        cone.set( 20, 60, 20, 30 );
        cone.setPosition(centers1[i]);
        float time = ofGetElapsedTimef();
        float value = (time, 0, 360, 0, 360);
        if(s){
            cone.rotate(ofRandom(0, 360), 1.0, 0.0, 0.0);}
        cone.draw();
        mTex2.unbind();
    }
    
    for (int i=0; i<20; i++) {
        mTex3.bind();
        ofBoxPrimitive box;
        box.set( 50, 100, 40, 20, 20, 20 );
        box.setPosition(centers2[i]);
        box.rotate(1.0, 0, 0.0, 0.0);
        box.rotate(0, 1.0, 0.0, 0.0);
        box.draw();
        mTex3.unbind();
    }
    sunlight.draw();
    
    
    cam.draw();
    ofPopMatrix();    //Restore the coordinate system
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == '2') {
        s = true;}
    
    if (key == '1') {
            s = false;
        }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
