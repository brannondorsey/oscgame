#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    bgColor = ofColor(255, 232, 120);
    ofBackground(bgColor);
    maxPlayers = 4;
    dataHand.setup(bgColor);
    dataHand.setMaxPlayers(maxPlayers);
}

//--------------------------------------------------------------
void testApp::update(){
    dataHand.update();
    while(dataHand.gotLocation()){
        arena.previewLocation(dataHand.getLocation());
        cout<<"I added a location"<<endl;
    }
    while(dataHand.characterAdded()){
        arena.addCharacter(dataHand.getCharacter());
        cout<<"I added a character"<<endl;
    }
    arena.update();
    if(arena.hasExpiredCharacters()){
        vector<Character> expiredCharacters = arena.getExpiredCharacters();
        for(int i = 0; i < expiredCharacters.size(); i++){
            dataHand.sendCharacterBack(expiredCharacters[i]);
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    arena.draw();
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
