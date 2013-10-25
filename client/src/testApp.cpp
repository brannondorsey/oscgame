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
    dataHand.setup();
    cout<<"The aspect ratio is: "<<ofToString(gameField.getAspectRatio())<<endl;
}

//--------------------------------------------------------------
void testApp::update()
{
    gui.update();
    gameField.update();
    
    if(gui.submitted()){
        //cout<<"This always gets submitted twice in a row"<<endl;
        if(gameField.hasLocations()){
            
            //send the message
            dataHand.sendCharacter(gui.getPlayerName(),
                                   gui.getRed(),
                                   gui.getGreen(),
                                   gui.getBlue(),
                                   gui.getSize(),
                                   gui.getSpeed(),
                                   gameField.getLocations());
        }
    }
    
    cout<<"Red: "<<gui.getRed()<<endl;
    cout<<"Green: "<<gui.getGreen()<<endl;
    cout<<"Blue: "<<gui.getBlue()<<endl;
    cout<<"Size: "<<gui.getSize()<<endl;
    cout<<"Speed: "<<gui.getSpeed()<<endl;
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
    //this bool also removes a location if the mouse is over that circle
    if((gameField.inside(x, y)) && (!gameField.removeLocation(x, y))){
            gameField.addLocation(x, y);
            dataHand.sendLocation(x, y, gui.getRed(), gui.getGreen(), gui.getBlue());
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