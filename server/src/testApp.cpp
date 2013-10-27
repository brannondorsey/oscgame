#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255, 232, 120);
    maxPlayers = 4;
    dataHand.setup();
    dataHand.setMaxPlayers(maxPlayers);
}

//--------------------------------------------------------------
void testApp::update(){
    dataHand.update();
    while(dataHand.gotLocation()){
        //arena.previewLocation(dataHand.getLocation());
        dataHand.getLocation(); //must get the location or else inifite loop
        cout<<"I added a location"<<endl;
    }
    while(dataHand.characterAdded()){
        //arena.addCharacter(dataHand.getCharacter());
        dataHand.getCharacter(); //must get the character or else infinite loop
        cout<<"I added a character"<<endl;
    }
    arena.update();
}

//--------------------------------------------------------------
void testApp::draw(){

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
