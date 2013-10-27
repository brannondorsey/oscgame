//
//  DataHandler.h
//  client
//
//  Created by bdorse on 10/24/13.
//
//

#ifndef client_DataHandler_h
#define client_DataHandler_h

#include "ofMain.h"
#include "ofxOscSender.h"
#include "ofxOscReceiver.h"

class DataHandler{
   
    public:
    
        void setup();
    
        void sendPing();
        void sendLocation(int x, int y, float red, float green, float blue, int gameFieldWidth, int gameFieldHeight);
        void sendCharacter(string playerName,
                           float red,
                           float green,
                           float blue,
                           float size,
                           float speed,
                           vector<string> locations,
                           int gameFieldWidth,
                           int gameFieldHeight);
    
        bool receivedMessage();
    
    private:
    
        string host;
        int sendPort;
        int receivePort;
    
        ofxOscReceiver receiver;
        ofxOscSender sender;
    
        void sendMessage(ofxOscMessage m);
        
};

#endif
