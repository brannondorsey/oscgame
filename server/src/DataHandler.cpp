//
//  DataHandler.cpp
//  server
//
//  Created by bdorse on 10/26/13.
//
//

#include "DataHandler.h"

//--------------------------------------------------------------
void DataHandler::setup(){
    
    int maxPlayers = 4;
    
    int sendPort = 12345;
    int receivePort = sendPort + 1;
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
             "x,y"
             red
             green
             blue
             */
            vector<string> split = ofSplitString(m.getArgAsString(0), ",");
            int x = ofToInt(split[0]);
            int y = ofToInt(split[1]);
            int red = m.getArgAsInt32(1);
            int green = m.getArgAsInt32(2);
            int blue = m.getArgAsInt32(3);
            newLocations.push_back(Location(x, y, red, green, blue));
            
        }else if(m.getAddress() == "/character added"){
            
            //parse the character into a character object and add it to the vector
            /*
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
            string playerName = m.getArgAsString(0);
            int red = m.getArgAsInt32(1);
            int green = m.getArgAsInt32(2);
            int blue = m.getArgAsInt32(3);
            float size = m.getArgAsFloat(4);
            float speed = m.getArgAsFloat(5);
            vector<ofPoint> points;
            
            for(int i = 6; i < m.getNumArgs(); i++){
                vector<string> split = ofSplitString(m.getArgAsString(i), ",");
                int x = ofToInt(split[0]);
                int y = ofToInt(split[1]);
                points.push_back(ofPoint(x, y));
            }
            
            Character newCharacter = Character(clientIP, playerName, red, green, blue, size, speed, points);
            newCharacters.push_back(newCharacter);
            
        }
    }
}

//--------------------------------------------------------------
void DataHandler::sendCharacterBack(Character expiredCharacter){
    /*
     coins
     */
    ofxOscMessage m;
    m.setAddress("/character received");
    m.addIntArg(expiredCharacter.getCoins());
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


