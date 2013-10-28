//
//  DataHandler.cpp
//  server
//
//  Created by bdorse on 10/26/13.
//
//

#include "DataHandler.h"

//--------------------------------------------------------------
void DataHandler::setup(ofColor& _bgColor){
    
    int maxPlayers = 4;
    
    bgColor = _bgColor;
    sendPort = 12345;
    receivePort = sendPort + 1;
    receiver.setup(receivePort);
}

//--------------------------------------------------------------
void DataHandler::setMaxPlayers(int _maxPlayers){
    maxPlayers = _maxPlayers;
}

//--------------------------------------------------------------
void DataHandler::update(){
    newLocations.clear();
    newCharacters.clear();
    receiveMessages();
}

//--------------------------------------------------------------
void DataHandler::receiveMessages(){
    
    // check for waiting messages
    while(receiver.hasWaitingMessages()){
        //cout<<"I received a message"<<endl;
        // get the next message
        ofxOscMessage m;
        receiver.getNextMessage(&m);
        
        //Identify host of incoming msg
        string incomingHost = m.getRemoteIp();
        
        //See if incoming host is a new one:
        if(std::find(knownClients.begin(), knownClients.end(), incomingHost)
           == knownClients.end() && knownClients.size() < maxPlayers){
            knownClients.push_back(incomingHost); //add new host to list
        }
    
        // check the address of the incoming message
        if(m.getAddress() == "/new location"){
            
            //parse the location osc message into a location object and add it to the vector
            /*
             gameFieldWidth
             gameFieldHeight
             "x,y"
             red
             green
             blue
             */
            
            int gameFieldWidth = m.getArgAsInt32(0);
            int gameFieldHeight = m.getArgAsInt32(1);
            vector<string> split = ofSplitString(m.getArgAsString(2), ",");
            int x = ofToInt(split[0]);
            int y = ofToInt(split[1]);
            int red = m.getArgAsInt32(3);
            int green = m.getArgAsInt32(4);
            int blue = m.getArgAsInt32(5);
            ofPoint translated = Translator::getArenaPoint(x, y, gameFieldWidth, gameFieldHeight);
            newLocations.push_back(Location(translated.x, translated.y, red, green, blue, bgColor));
            
        }else if(m.getAddress() == "/character added"){
            
            //parse the character into a character object and add it to the vector
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
            
            string clientIP = m.getRemoteIp();
            int gameFieldWidth = m.getArgAsInt32(0);
            int gameFieldHeight = m.getArgAsInt32(1);
            string playerName = m.getArgAsString(2);
            int red = m.getArgAsInt32(3);
            int green = m.getArgAsInt32(4);
            int blue = m.getArgAsInt32(5);
            float size = m.getArgAsFloat(6);
            float speed = m.getArgAsFloat(7);
            vector<ofPoint> points;
            
            size = Translator::getArenaSize(size);
            speed = Translator::getArenaSpeed(speed);
            
            for(int i = 8; i < m.getNumArgs(); i++){
                vector<string> split = ofSplitString(m.getArgAsString(i), ",");
                int x = ofToInt(split[0]);
                int y = ofToInt(split[1]);
                ofPoint point = Translator::getArenaPoint(x, y, gameFieldWidth, gameFieldHeight);
                points.push_back(ofPoint(point.x, point.y));
            }
            
            Character newCharacter = Character(clientIP, playerName, red, green, blue, size, speed, points);
            newCharacters.push_back(newCharacter);
            
        }
    }
}

//--------------------------------------------------------------
void DataHandler::sendCharacterBack(Character expiredCharacter){
    /*
     "true"
     */
    ofxOscMessage m;
    m.setAddress("/character received");
    m.addStringArg("true");
    cout<<"Expired character ip is "<<expiredCharacter.getClientIP()<<endl;
    cout<<"sendPort is "<<sendPort<<endl;
    sender.setup(expiredCharacter.getClientIP(), sendPort);
    m.setRemoteEndpoint(expiredCharacter.getClientIP(), sendPort);
    sender.sendMessage(m);
}

//--------------------------------------------------------------
bool DataHandler::gotLocation(){
    return newLocations.size() > 0;
}

//--------------------------------------------------------------
bool DataHandler::characterAdded(){
    return newCharacters.size() > 0;
}

//--------------------------------------------------------------
Location DataHandler::getLocation(){
    Location loc = newLocations[0];
    cout<<"The locations size is "<<newLocations.size()<<endl;
    newLocations.erase(newLocations.begin()); //remove loc from vector
    return loc;
}

//--------------------------------------------------------------
Character DataHandler::getCharacter(){
    Character character = newCharacters[0];
    newCharacters.erase(newCharacters.begin()); //remove character from vector
    return character;
}


