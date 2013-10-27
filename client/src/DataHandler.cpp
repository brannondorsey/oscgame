//
//  DataHandler.cpp
//  client
//
//  Created by bdorse on 10/24/13.
//
//

#include "DataHandler.h"

//--------------------------------------------------------------
//PUBLIC
void DataHandler::setup(){
    host = "localhost";
    receivePort = 12345;
    sendPort = receivePort + 1;
    sender.setup(host, sendPort);
}

//--------------------------------------------------------------
void DataHandler::sendPing(){
    ofxOscMessage m;
    m.setAddress("/ping");
    m.addIntArg(1);
    sendMessage(m);
}

//--------------------------------------------------------------
void DataHandler::sendCharacter(string playerName,
                                float red,
                                float green,
                                float blue,
                                float size,
                                float speed,
                                vector<string> locations,
                                int gameFieldWidth,
                                int gameFieldHeight){
    
    /*
     gameFieldWidth
     gameFieldHeight
     "player name"
     red
     green
     blue
     size
     speed
     ["x,y",
      "x,y",
      "x,y",
      etc...
     ]
     */
    
    ofxOscMessage m;
    
    m.setAddress("/character added");
    m.addIntArg(gameFieldWidth);
    m.addIntArg(gameFieldHeight);
    m.addStringArg(playerName); // screen name
    m.addFloatArg(red); // red
    m.addFloatArg(green); // green
    m.addFloatArg(blue); // blue
    m.addFloatArg(size); // size
    m.addFloatArg(speed); // speed
    
    for(int i = 0; i < locations.size(); i++){
        m.addStringArg(locations[i]); // location packet formatted as "x,y"
    }
    sendMessage(m);

}

//--------------------------------------------------------------
void DataHandler::sendLocation(int x, int y, float red, float green, float blue, int gameFieldWidth, int gameFieldHeight){
    
    /*
     gameFieldWidth
     gameFieldHeight
     "x,y"
     red
     green
     blue
     */
    
    ofxOscMessage m;
    m.setAddress("/new location");
    m.addIntArg(gameFieldWidth);
    m.addIntArg(gameFieldHeight);
    m.addStringArg(ofToString(x) + "," + ofToString(y)); 
    m.addFloatArg(red);
    m.addFloatArg(green);
    m.addFloatArg(blue);
    
    sendMessage(m);
}

//--------------------------------------------------------------
bool DataHandler::receivedMessage(){
    
}

//--------------------------------------------------------------
//PROTECTED

//--------------------------------------------------------------
void DataHandler::sendMessage(ofxOscMessage m){
    sender.sendMessage(m);
}
