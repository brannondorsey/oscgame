#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
 	ofEnableSmoothing();
    ofSetCircleResolution(60);
    
    //gameField = GameField();
    int guiWidth = (int) ofGetWidth() - gameField.getWidth();
    //cout<<"The gui width is: "<<ofToString(guiWidth)<<endl;
    gui.setup(guiWidth);
    cout<<"The aspect ratio is: "<<ofToString(gameField.getAspectRatio())<<endl;
}

//--------------------------------------------------------------
void testApp::update()
{
    gui.update();
    gameField.update();
    
    if(gui.submitted()){
        if(gameField.hasPoints()){
            
            //combine the characer data and the movement data
            vector<string> characterData = gui.getCharacterData();
            vector<string> movementData = gameField.getMovementData();
            characterData.insert(characterData.begin(), movementData.begin(), movementData.end());
            vector<string> data = characterData;
            
            //send the message
            //dataHand.sendMessage("Character Added", data);
        }
        //dataHand.sendMessage("Character Added", gui.getCharacterData());
//        vector<string> data = gui.getCharacterData();
//        for(int i = 0; i < data.size(); i++){
//            cout<<data[i]<<endl;
//        }
    }
    cout<<"Mouse inside gameField: "<<ofToString(gameField.inside(mouseX, mouseY))<<endl;
    
}

//--------------------------------------------------------------
void testApp::draw()
{
    gui.draw();
    gameField.draw();
}

//--------------------------------------------------------------
void testApp::exit()
{
    gui.exit();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
  
}

//-------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y )
{

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button)
{
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{
    if(gameField.inside(x, y)){
        gameField.addPoint(x, y);
    }
    cout<<ofToString(x)<<", "<<ofToString(y)<<endl;
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h)
{
    
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 
    
}