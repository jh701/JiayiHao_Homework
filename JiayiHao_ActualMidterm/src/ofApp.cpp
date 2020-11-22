#include "ofApp.h"

vector<ofPoint> vertices;
vector<ofColor> colors;
int nTri;
int nVert;

//--------------------------------------------------------------
void ofApp::setup(){
    
    model1.loadModel("body/dog.3ds");
    model1.setPosition(ofGetWidth()*.5, ofGetHeight() * 0.75, 0);
    
    
    changescreen = false;
    
    nTri = 1500;
    nVert= nTri * 3;

    float Rad = 250;
    float rad = 25;

    vertices.resize( nVert );
    for (int i=0; i<nTri; i++) {
   
        ofPoint center( ofRandom( -1, 1 ),
            ofRandom( -1, 1 ),
            ofRandom( -1, 1 ) );
        center.normalize();
        center *= Rad;

        for (int j=0; j<3; j++) {
            vertices[ i*3 + j ] =
                center + ofPoint( ofRandom( -rad, rad ),
                ofRandom( -rad, rad ),
                ofRandom( -rad, rad ) );
        }
    }
    colors.resize( nTri );
    for (int i=0; i<nTri; i++) {
        //Picks random color from black to green
        colors[i] = ofColor( 0, 0, ofRandom(0, 255 ));
    }
    //----------------------------------------------------
    
    

    //Modechange = false set ups (2D graphics)
     image1.load("body/lol.png"); //load 2D body
     //f.load("body/hole.png");
  //  body2.load("body/back.png");
     
     // create 2 particle system on screen

     glm::vec2 pos1 = glm::vec2(100, -100);
     glm::vec2 pos2 = glm::vec2(800, -100);// center screen
    glm::vec2 pos3 = glm::vec2(ofGetWidth()/2, ofGetHeight()+100);
    ParticleSystem particleSystem = ParticleSystem(pos1);
    ParticleSystem particleSystem2 = ParticleSystem(pos2);
    
    hole = ParticleSystem(pos3);
    
     particleSystems.push_back(particleSystem);
     particleSystems.push_back(particleSystem2);
    
       glm::vec2 posa = glm::vec2( ofGetWidth()/2-80, 700);
       glm::vec2 posb = glm::vec2(ofGetWidth()/2+80, 700);
       glm::vec2 posc = glm::vec2(ofGetWidth()/2+80, 600);
       glm::vec2 posd = glm::vec2(ofGetWidth()/2+80, 600);
    
    ParticleSystem particleSystem3 = ParticleSystem(posa);
    ParticleSystem particleSystem4 = ParticleSystem(posb);
    ParticleSystem particleSystem5 = ParticleSystem(posc);
    ParticleSystem particleSystem6 = ParticleSystem(posd);
    
    
     gravity = glm::vec2(0, .15);
     
         int randomX = ofRandom( 0, ofGetWidth() );
         int randomY = ofRandom( 0, ofGetHeight() );
    
    Rwaist.clear();
    Rwaist.curveTo(ofGetWidth()/2-71, ofGetHeight()/2+135);
    Rwaist.curveTo(ofGetWidth()/2-71, ofGetHeight()/2+135);
    Rwaist.curveTo(ofGetWidth()/2-0.8*120, ofGetHeight()/2+230);
    Rwaist.curveTo(ofGetWidth()/2-0.8*120, ofGetHeight()/2+350);//changing x value
    Rwaist.curveTo(0.5*ofGetWidth()-100, ofGetHeight()+50);
    Rwaist.curveTo(0.5*ofGetWidth()-100, ofGetHeight()+50);
    
    Lwaist.clear();
    Lwaist.curveTo(ofGetWidth()/2+77, ofGetHeight()/2+135);
    Lwaist.curveTo(ofGetWidth()/2+77, ofGetHeight()/2+135);
    Lwaist.curveTo(ofGetWidth()/2+0.8*120, ofGetHeight()/2+230);
    Lwaist.curveTo(ofGetWidth()/2+0.8*120, ofGetHeight()/2+350);//changing x value
    Lwaist.curveTo(0.5*ofGetWidth()+100, ofGetHeight()+50);
    Lwaist.curveTo(0.5*ofGetWidth()+100, ofGetHeight()+50);
    
    //3D Graphics
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    //ofBackground(50, 50, 50, 0);
    Cam.setDistance(400); //setEasyCam
     
     
    ofDisableArbTex();
    ofEnableDepthTest();

     //load and set position for 3D Model of female body
    model.loadModel("body/female.obj");
    model.setPosition(ofGetWidth()*.5+20, ofGetHeight() * 0.75-25, 0);

     //set my light source
    light.enable();
    light.setPosition(model.getPosition() + glm::vec3(0, 0, 800));
 }
     //--------------------------------------------------------------
 void ofApp::update(){
     
     //particleSystems.push_back(particleSystem);
     
     for (int i=0; i<particleSystems.size(); i++){
         particleSystems[i].applyForce(gravity);
         particleSystems[i].update();}
     
     hole.update1();
     
 }
//--------------------------------------------------------------
void ofApp::draw(){
    
    ofDrawBitmapString("Press ‘1’ for me in 3D", 10 , 20);
    ofDrawBitmapString("Press ‘2’ for me in 2D", 10 , 30);
    ofDrawBitmapString("Press ‘3’ to see my true self", 10 , 40);
    ofDrawBitmapString("Click left mouse for 2D interactions", 10 , 50);
    
    if (changemode != true){
        
        float time = ofGetElapsedTimef();
        float num = sin( time );
        float r = ofMap( num, -1, 1, 255, 200 );
        float b = ofMap( num, -1, 1, 0, 255 );
        float n = ofMap( num, -1, 1, 0, 255 );
        ofSetColor(r,b,n);
        ofSetLineWidth(8.0);
        back.draw(0, 0, ofGetWidth(), ofGetHeight());
        image1.draw(ofGetWidth()/2-150, ofGetHeight()/2-100);
        Rwaist.draw();
        Lwaist.draw();
        
        if (ofGetMousePressed(OF_MOUSE_BUTTON_LEFT)){
            float value = sin( time );
            float v = ofMap(value, -1, 1, 50, 200);
            Rwaist.clear();
            Rwaist.curveTo(ofGetWidth()/2-71, ofGetHeight()/2+135);
            Rwaist.curveTo(ofGetWidth()/2-71, ofGetHeight()/2+135);
            Rwaist.curveTo(ofGetWidth()/2-0.8*v, ofGetHeight()/2+230);
            Rwaist.curveTo(ofGetWidth()/2-0.8*v, ofGetHeight()/2+350);//changing x value
            Rwaist.curveTo(0.5*ofGetWidth()-100, ofGetHeight()+50);
            Rwaist.curveTo(0.5*ofGetWidth()-100, ofGetHeight()+50);
            
            Lwaist.clear();
            Lwaist.curveTo(ofGetWidth()/2+77, ofGetHeight()/2+135);
            Lwaist.curveTo(ofGetWidth()/2+77, ofGetHeight()/2+135);
            Lwaist.curveTo(ofGetWidth()/2+0.8*v, ofGetHeight()/2+230);
            Lwaist.curveTo(ofGetWidth()/2+0.8*v, ofGetHeight()/2+350);//changing x value
            Lwaist.curveTo(0.5*ofGetWidth()+100, ofGetHeight()+50);
            Lwaist.curveTo(0.5*ofGetWidth()+100, ofGetHeight()+50);
            
            for (int i=0; i<particleSystems.size(); i++){
                particleSystems[i].draw();}}}


        if(changemode == true){
        ofSetColor(255,255,255);
            drawWithModel();}

       if(changescreen==true){
           drawWithMesh();}}
    
      //  if (ofGetMouseReleased(OF_MOUSE_BUTTON_LEFT))
    
//------------------------------------------------------------
void ofApp::drawWithModel(){
    //get the position of the model
    glm::vec3 position = model.getPosition();


    ofPushMatrix();
    ofTranslate(position);
    //ofRotateDeg(-ofGetMouseX(), 0, 1, 0);
    ofRotateDeg(90,1,0,0);
    ofTranslate(-position);
    model.drawFaces();
    
    ofBackgroundGradient( ofColor( 255 ), ofColor( 128 ) );

    ofPushMatrix();

  
    ofTranslate( ofGetWidth()/2, ofGetHeight()/2, 0 );

   
    float time = ofGetElapsedTimef();
    float angle = time * 10;
    ofRotate( angle, 1, 1, 1 );

    //Draw the triangles
    for (int i=0; i<nTri; i++) {
        ofSetColor( colors[i] );
        ofTriangle( vertices[ i*3 ],
            vertices[ i*3 + 1 ],
            vertices[ i*3 + 2 ] );
    }

    ofPopMatrix();
    ofPopMatrix();
}
//--------------------------------------------------------------
void ofApp::drawWithMesh(){

    
    //get the model attributes we need
    glm::vec3 scale = model1.getScale();
    glm::vec3 position = model1.getPosition();
    float normalizedScale = model1.getNormalizedScale();
    ofVboMesh mesh = model1.getMesh(0);
    ofTexture texture;
    ofxAssimpMeshHelper& meshHelper = model1.getMeshHelper( 0 );
    bool bHasTexture = meshHelper.hasTexture();
    if( bHasTexture ) {
        texture = model1.getTextureForMesh(0);
    }

    ofMaterial material = model1.getMaterialForMesh(0);

    ofPushMatrix();

    ofTranslate(position);
    ofRotateDeg(90, 0, 1, 0);
    ofRotateDeg(-ofGetMouseX(),1,0,0);


    ofScale(normalizedScale, normalizedScale, normalizedScale);
    ofScale(scale.x,scale.y,scale.z);

    //modify mesh with some noise
    float liquidness = 10;
    float amplitude = 10;
    float speedDampen = 5;
    auto &verts = mesh.getVertices();

    for(unsigned int i = 0; i < verts.size(); i++){
        verts[i].x += ofSignedNoise(verts[i].x/liquidness, verts[i].y/liquidness,verts[i].z/liquidness, ofGetElapsedTimef()/speedDampen)*amplitude;
        verts[i].y += ofSignedNoise(verts[i].z/liquidness, verts[i].x/liquidness,verts[i].y/liquidness, ofGetElapsedTimef()/speedDampen)*amplitude;
        verts[i].z += ofSignedNoise(verts[i].y/liquidness, verts[i].z/liquidness,verts[i].x/liquidness, ofGetElapsedTimef()/speedDampen)*amplitude;
        //verts[i].x += ofSignedNoise(verts[i].x, verts[i].y,1, ofGetElapsedTimef()/speedDampen)*amplitude;
        //verts[i].y += ofSignedNoise(verts[i].x, verts[i].y,1, ofGetElapsedTimef()/speedDampen)*amplitude;
    }


    if(bHasTexture) texture.bind();
    material.begin();
    //mesh.drawWireframe();
    mesh.addColor(8);
    mesh.drawFaces();
    material.end();
    if(bHasTexture) texture.unbind();

    ofPopMatrix();


     }
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == '1'){
        changemode = true;
    }
    if(key =='2'){
        changemode = false;
    }
    if(key == '3'){
        changescreen = true;
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
