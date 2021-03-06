//
//  DataHandler.h
//  server
//
//  Created by bdorse on 10/26/13.
//
//

#ifndef server_DataHandler_h
#define server_DataHandler_h

#include "ofMain.h"
#include "ofxOscSender.h"
#include "ofxOscReceiver.h"
#include "Character.h"
#include "Location.h"
#include "Translator.h"

class DataHandler{
    
    public:
    
        void setup(ofColor& bgColor);
        void update();
        void setMaxPlayers(int _maxPlayers);
        void sendCharacterBack(Character expiredCharacter);
    
        bool gotLocation();
        bool characterAdded();
    
        Location getLocation(); //should be a Location object to show color
        Character getCharacter();
    
    private:
    
        int maxPlayers;
        int sendPort;
        int receivePort;
    
        vector<string>knownClients; //collected IP's of chat participants
        vector<Location> newLocations;
        vector<Character> newCharacters;
    
        ofColor bgColor;
    
        ofxOscReceiver receiver;
        ofxOscSender sender;
    
        void receiveMessages();
        void sendMessage(string clientIP, ofxOscMessage m);
        void broadcastMessage(ofxOscMessage m);
};

#endif
