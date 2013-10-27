#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
 	ofEnableSmoothing();
    ofSetCircleResolution(60);
    ofEnableAlphaBlending();

    int guiWidth = (int) ofGetWidth() - gameField.getWidth();
    //cout<<"The gui width is: "<<ofToString(guiWidth)<<endl;
    gui.setup(guiWidth);
    dataHand.setup();
    cout<<"The aspect ratio is: "<<ofToString(gameField.getAspectRatio())<<endl;
}

//--------------------------------------------------------------
void testApp::update()
{
    gui.update();
    gameField.update();
    dataHand.update();
    
    if(int(ofGetFrameNum()) % int(ofGetFrameRate()) == 0){
        dataHand.sendPing();
    }
    
    //if the the player's gameField is enabled...
    if(!gameField.isDisabled()){
        if(gui.submitted()){
            //cout<<"This always gets submitted twice in a row"<<endl;
            if(gameField.hasEnoughLocations()){
                
                //send the message
                dataHand.sendCharacter(gui.getPlayerName(),
                                       gui.getRed(),
                                       gui.getGreen(),
                                       gui.getBlue(),
                                       gui.getSize(),
                                       gui.getSpeed(),
                                       gameField.getLocations(),
                                       gameField.getWidth(),
                                       gameField.getHeight());
                
                //disable the gamefield while the character is away
                gameField.disable();
            }
        }
    }else{ //if the player's gamefield is disabled...
        //cout<<"The gamefield is disabled"<<endl;
        if(dataHand.characterReturned()){
            gameField.reset();
            gameField.enable();
        }
    }
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
    if(!gameField.isDisabled()){
        //this bool also removes a location if the mouse is over that circle
        if((gameField.inside(x, y)) && (!gameField.removeLocation(x, y))){
            if(gameField.addLocation(x, y)){
                dataHand.sendLocation(x - gameField.getStartX(),
                                      y,
                                      gui.getRed(),
                                      gui.getGreen(),
                                      gui.getBlue(),
                                      gameField.getWidth(),
                                      gameField.getWidth());
            };
        }
    }
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