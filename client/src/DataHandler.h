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
        void processMessage();
    
        void sendPing();
        void sendLocation(int x, int y, float red, float green, float blue);
        void sendCharacter(string playerName,
                           float red,
                           float green,
                           float blue,
                           float size,
                           float speed,
                           vector<string> locations);
    
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
