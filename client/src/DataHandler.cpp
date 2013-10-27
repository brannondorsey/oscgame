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
    host = getRemoteHost();
    receivePort = 12345;
    gotCharacter = false;
    sendPort = receivePort + 1;
    sender.setup(host, sendPort);
    receiver.setup(receivePort);
}

//--------------------------------------------------------------
void DataHandler::update(){
    gotCharacter = false;
    // check for waiting messages
    while(receiver.hasWaitingMessages()){
            
        // get the next message
        ofxOscMessage m;
        receiver.getNextMessage(&m);
        
        if(m.getAddress() == "/character received"){
            cout<<"I received the OSC message"<<endl;
            gotCharacter = true;
        }
    }
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
bool DataHandler::characterReturned(){
    return gotCharacter;
}

//--------------------------------------------------------------
//PRIVATE

//--------------------------------------------------------------
void DataHandler::sendMessage(ofxOscMessage m){
    sender.sendMessage(m);
}

//--------------------------------------------------------------
string DataHandler::getRemoteHost(){
    ofFile file;
    if(file.open(ofToDataPath("remotehost.txt"))){
        ofBuffer buff = file.readToBuffer();
        string ip = buff.getText();
        cout<<"The remote ip address is "<<ip<<endl;
        return ip;
    }else return "localhost";
}
