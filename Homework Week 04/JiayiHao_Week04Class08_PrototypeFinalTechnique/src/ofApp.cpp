
#include "ofApp.h"

    float Rad = ofRandom(15, 25);      //Raduis of ea
    float circleStep = 1;        //Step size for circle motion
    int circleN = 25;             //Number of points on the circle

    glm::vec3 pos;                //Circle center
    glm::vec3 circleX, circleY, circleZ;    //Circle's coordinate system

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableDepthTest();
    
    pos = glm::vec3( 0, 0, 0 );
    circleX = glm::vec3( 1, 0, 0 );    //Set initial coordinate system or individual circle
    circleY = glm::vec3( 0, 1, 0 );
    circleZ = glm::vec3( 0, 0, 1 );

    light.enable();
    ofSetFrameRate( 60 );
}

//--------------------------------------------------------------
void ofApp::update(){

        drawVineStraight( mesh );
        if(change){
            drawVineCircular( mesh );
            }
        if(!change){
            drawVineStraight( mesh );
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    ofSetColor( 255, 255, 255);

    ofDrawBitmapString("Press ‘2’ for bent growth", 10 , 30);
    ofDrawBitmapString("Press ‘1’ to start program /shift to linear growth", 10 , 20);
    
    ofPopMatrix();
    
    if(hit){
    //Set a gradient background from light brown to brown!
    ofBackgroundGradient( ofColor( 157, 127, 97 ), ofColor( 66, 40, 14 ) );
    light.setPosition(glm::vec3(0, 0, 800));

    ofPushMatrix();
 
    ofTranslate( ofGetWidth()/2, ofGetHeight()/2, 0 );
    float time = ofGetElapsedTimef();
    float angle = time * 20;
    
    ofRotate( angle, 0, 1, 0 );
    ofTranslate( -mesh.getCentroid() );
    mesh.draw();
    
    ofPopMatrix();
            }
}

//--------------------------------------------------------------
void ofApp::drawVineStraight( ofMesh &mesh ){
    float time = ofGetElapsedTimef();    //Time

    //Parameters – twisting and rotating angles and color
    float twistAngle = 0.1 * ofSignedNoise( time * 0.3 + 332.4 );

    float rotateAngle = 0.02;
    float t = ofGetElapsedTimef();
    float value = sin( t);
    float v = ofMap( value, -1, 1, 75, 31 );
    float b = ofMap( value, -1, 1, 83, 61 );
    float n = ofMap( value, -1, 1, 32, 12 );

    
    ofFloatColor color (v, b, n);
    color.setSaturation( 1.0 );

    //Rotate the coordinate system of the circle
    
    glm::mat4 rotationMat(1);
    rotationMat = glm::rotate(rotationMat, twistAngle, circleZ);
    
    glm::mat4 rotationMat1(1);
    rotationMat1 = glm::rotate(rotationMat, twistAngle, circleY);
    
    circleX = glm::vec3(rotationMat * glm::vec4(circleX, 0));
    circleY = glm::vec3(rotationMat * glm::vec4(circleY, 0));
    circleX = glm::vec3(rotationMat1 * glm::vec4(circleX, 0));
    circleZ = glm::vec3(rotationMat1 * glm::vec4(circleZ, 0));
    
    glm::vec3 move = circleZ * circleStep;
    pos += move;

    //Add vertices
    for (int i=0; i<circleN; i++) {
        float angle = float(i) / circleN * TWO_PI;
        float x = Rad * cos( angle );
        float y = Rad * sin( angle );
        //We would like to distort this point
        //to make the knot's surface embossed
        float distort = ofNoise( x * 0.2, y * 0.2, time * 0.2 + 30 );
        distort = ofMap( distort, 0.2, 0.8, 0.8, 1.2 );
        x *= distort;
        y *= distort;

        glm::vec3 p = circleX * x + circleY * y + pos;
        mesh.addVertex( p );
        mesh.addColor( color );
    }

    //Add the triangles
    int base = mesh.getNumVertices() - 2 * circleN;
    if ( base >= 0 ) {    //Check if it is not the first step
        //and we really need to add the triangles
        for (int i=0; i<circleN; i++) {
            int a = base + i;
            int b = base + (i + 1) % circleN;
            int c = circleN  + a;
            int d = circleN  + b;
            mesh.addTriangle( a, b, d );    //Clock-wise
            mesh.addTriangle( a, d, c );
        }
        setNormals(mesh);
    }
}

//--------------------------------------------------------------
void setNormals( ofMesh &mesh ){

    //The number of the vertices
    int nV = mesh.getNumVertices();

    //The number of the triangles
    int nT = mesh.getNumIndices() / 3;

    vector<glm::vec3> norm( nV ); //Array for the normals

    for (int t=0; t<nT; t++) {

        //Get indices of the triangle t
        int i1 = mesh.getIndex( 3 * t );
        int i2 = mesh.getIndex( 3 * t + 1 );
        int i3 = mesh.getIndex( 3 * t + 2 );

        //Get vertices of the triangle
            const glm::vec3 &v1 = mesh.getVertex( i1 );
            const glm::vec3 &v2 = mesh.getVertex( i2 );
            const glm::vec3 &v3 = mesh.getVertex( i3 );

        //Compute the triangle's normal
        glm::vec3 dir = glm::normalize(glm::cross( v2 - v1,  v3 - v1 ));
           
        norm[ i1 ] += dir;
        norm[ i2 ] += dir;
        norm[ i3 ] += dir;
    }

    //Normalize the normal's length
    for (int i=0; i<nV; i++) {
        norm[i] = glm::normalize(norm[i]);
    }

    //Set the normals to mesh
    mesh.clearNormals();
    mesh.addNormals( norm );
}


//--------------------------------------------------------------
void ofApp::drawVineCircular( ofMesh &mesh ){
    float time = ofGetElapsedTimef();    //Time

    //Parameters – twisting and rotating angles and color
    float twistAngle = 0.1 * ofSignedNoise( time * 0.3 + 332.4 );

    float rotateAngle = 0.02;
    float t = ofGetElapsedTimef();
    float value = sin( t);
    float v = ofMap( value, -1, 1, 75, 31 );
    float b = ofMap( value, -1, 1, 83, 61 );
    float n = ofMap( value, -1, 1, 32, 12 );

    
    ofFloatColor color (v, b, n);
   // ofFloatColor color (0, ofRandom(180,255), ofRandom(0,100));
    color.setSaturation( 1.0 );

    //Rotate the coordinate system of the circle
    
    circleX = glm::rotate( circleX, twistAngle, circleZ );
    circleY = glm::rotate( circleY, twistAngle, circleZ );
    circleX = glm::rotate( circleX, rotateAngle, circleY );
    circleZ = glm::rotate( circleZ, rotateAngle, circleY );
    
    glm::vec3 move = circleZ * circleStep;
    pos += move;

    //Add vertices
    for (int i=0; i<circleN; i++) {
        float angle = float(i) / circleN * TWO_PI;
        float x = Rad * cos( angle );
        float y = Rad * sin( angle );

        float distort = ofNoise( x * 0.2, y * 0.2, time * 0.2 + 30 );
        distort = ofMap( distort, 0.2, 0.8, 0.8, 1.2 );
        x *= distort;
        y *= distort;

        glm::vec3 p = circleX * x + circleY * y + pos;
        mesh.addVertex( p );
        mesh.addColor( color );
    }

    //Add the triangles
    int base = mesh.getNumVertices() - 2 * circleN;
    if ( base >= 0 ) {
        for (int i=0; i<circleN; i++) {
            int a = base + i;
            int b = base + (i + 1) % circleN;
            int c = circleN  + a;
            int d = circleN  + b;
            mesh.addTriangle( a, b, d );    //Clock-wise
            mesh.addTriangle( a, d, c );
        }
        setNormals(mesh);
    }
}
//-----------------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == '3'){
        hit = false;
    }
    
    if (key == '1'){
        hit = true;
    }
    if(key == '2'){
        change = true;
    }
    if(key == '1'){
        change = false;
    }
}
//------------------------------------------------------------------------------
void ofApp::drawRibbonColor1( ofMesh &mesh ){
    float time = ofGetElapsedTimef();    //Time

    //Parameters
    float twistAngle = 0.1 * ofSignedNoise( time * 0.3 + 300 );
    float rotateAngle = 0.02;
    float t = ofGetElapsedTimef();
    float value = sin( t);
    float v = ofMap( value, -1, 1, 252, 253 );
    float b = ofMap( value, -1, 1, 205, 171 );
    float n = ofMap( value, -1, 1, 211, 159 );

    
    ofFloatColor color (v, b, n);
    color.setSaturation( 1.0 );

    //Rotate the coordinate system of the circle
    circleX = glm::rotate( circleX, twistAngle, circleZ );
    circleY = glm::rotate( circleY, twistAngle, circleZ );
    circleX = glm::rotate( circleX, rotateAngle, circleY );
    circleZ = glm::rotate( circleZ, rotateAngle, circleY );
    
    glm::vec3 move = circleZ * circleStep;
    pos += move;

    //Add vertices
    for (int i=0; i<circleN; i++) {
        float angle = float(i) / circleN * TWO_PI;
        float x = Rad * cos( angle );
        float y = Rad * sin( angle );
        float distort = ofNoise( x * 0.2, y * 0.2, time * 0.2 + 30 );
        distort = ofMap( distort, 0.2, 0.8, 0.8, 1.2 );
        x *= distort;
        y *= distort;

        glm::vec3 p = circleX * x + circleY * y + pos;
        mesh.addVertex( p );
        mesh.addColor( color );
    }

    //Add the Triangle primitives to construct the surface
    int base = mesh.getNumVertices() - 2 * circleN;
    if ( base >= 0 ) {
        for (int i=0; i<circleN; i++) {
            int a = base + i;
            int b = base + (i + 1) % circleN;
            int c = circleN  + a;
            int d = circleN  + b;
            mesh.addTriangle( a, b, d );    //Clock-wise
            mesh.addTriangle( a, d, c );
        }
    }
    
}

void ofApp::drawRibbonColor2( ofMesh &mesh ){
    float time = ofGetElapsedTimef();

    //Parameters
    float twistAngle = 0.1 * ofSignedNoise( time * 0.3 + 300 );
    float rotateAngle = 0.02;
    float t = ofGetElapsedTimef();
    float value = sin( t);
    float v = ofMap( value, -1, 1, 204, 176 );
    float b = ofMap( value, -1, 1, 169, 203 );
    float n = ofMap( value, -1, 1, 221, 234 );

    
    ofFloatColor color (v, b, n);
    color.setSaturation( 1.0 );

    //Rotate the coordinate system of the circle
    circleX = glm::rotate( circleX, twistAngle, circleZ );
    circleY = glm::rotate( circleY, twistAngle, circleZ );
    circleX = glm::rotate( circleX, rotateAngle, circleY );
    circleZ = glm::rotate( circleZ, rotateAngle, circleY );
    
    glm::vec3 move = circleZ * circleStep;
    pos += move;

    //Add vertices
    for (int i=0; i<circleN; i++) {
        float angle = float(i) / circleN * TWO_PI;
        float x = Rad * cos( angle );
        float y = Rad * sin( angle );
        float distort = ofNoise( x * 0.2, y * 0.2, time * 0.2 + 30 );
        distort = ofMap( distort, 0.2, 0.8, 0.8, 1.2 );
        x *= distort;
        y *= distort;

        glm::vec3 p = circleX * x + circleY * y + pos;
        mesh.addVertex( p );
        mesh.addColor( color );
    }

    //Add the Triangle primitives to construct the surface
    int base = mesh.getNumVertices() - 2 * circleN;
    if ( base >= 0 ) {
        for (int i=0; i<circleN; i++) {
            int a = base + i;
            int b = base + (i + 1) % circleN;
            int c = circleN  + a;
            int d = circleN  + b;
            mesh.addTriangle( a, b, d );    //Clock-wise
            mesh.addTriangle( a, d, c );
        }
    }
}
