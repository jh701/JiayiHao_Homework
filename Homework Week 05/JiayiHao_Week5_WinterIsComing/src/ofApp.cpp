#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    image.load("sno.jpg");
    image.resize(200, 200);

    mesh.setMode(OF_PRIMITIVE_LINES);
        mesh.enableIndices();

    //Only add pixels with brightness over 50 into the mesh
        int w = image.getWidth();
        int h = image.getHeight();
        for (int i = 0; i < image.getWidth(); i++) {
            for (int j = 0; j < image.getHeight() ; j++) {
                ofColor c = image.getColor(i, j);
                float intensity = c.getLightness();
                if (intensity >= 50) {
                    float saturation = c.getSaturation();
                    float z = ofMap(saturation, 0, 255, -100, 100);
                    ofVec3f pos(i*4, j*4, z);
                    mesh.addVertex(pos);
                    ofColor a = ofColor (173, 216, 230);
                    mesh.addColor(a);
                }
            }
        }
    
    //Connect dots in OF_PRIMITIVE_LINES mode if the dots are within 7 pixels to each other
    int VertNumber = mesh.getNumVertices();
    for (int x = 0; x < VertNumber; x++) {
        ofVec3f vertx = mesh.getVertex(x);
        for (int y = x + 1; y <VertNumber; y++) {
            ofVec3f verty = mesh.getVertex(y);
            float distance = vertx.distance(verty);
            if (distance <= 7) {
                mesh.addIndex(x);
                mesh.addIndex(y);
            }
        }
    }
    
    //find the center of the mesh, store in vector center
    center = mesh.getCentroid();
    for (int i=0; i<VertNumber; ++i) {
        ofVec3f vert = mesh.getVertex(i);
        float l = vert.distance(center);
        float angle = atan2(vert.y-center.y, vert.x-center.x);
        lengths.push_back(l);
        angles.push_back(angle);
    }
    
    storm = false;
    startStormTime = 0.0;
    meshCopy = mesh;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (storm) {
        int VertNumber = mesh.getNumVertices();
        for (int i=0; i<VertNumber; ++i) {
            ofVec3f vert = mesh.getVertex(i);
            float elapsedTime = ofGetElapsedTimef() - startStormTime;
            
            float l = lengths[i];
            float angle = angles[i];
            float speed = ofMap(l, 0, 200, 3, 1, true);
            float rotatedAngle = elapsedTime * speed + angle;

            vert.x = l * cos(rotatedAngle) + center.x;
            vert.y = l * sin(rotatedAngle) + center.y;

            mesh.setVertex(i, vert);
        }
    }
    }

//--------------------------------------------------------------
void ofApp::draw(){
        ofDrawBitmapString("Winter is Coming: Press ‘1’ for SNOW STORM", 10 , 20);
        
        ofBackgroundGradient(ofColor(80, 70, 70), ofColor(0, 0, 0), OF_GRADIENT_CIRCULAR);

        Cam.begin();
               ofPushMatrix();
                   ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
                   mesh.draw();
               ofPopMatrix();
        Cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == '1') {
            storm = !storm;
            startStormTime = ofGetElapsedTimef();
            mesh = meshCopy;
        }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
