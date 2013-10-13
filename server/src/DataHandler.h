//
//  DataHandler.h
//  emptyExample
//
//  Created by bdorse on 10/13/13.
//
//

#ifndef emptyExample_DataHandler_h
#define emptyExample_DataHandler_h

#include "Player.h"

class DataHandler{
    
    ofxOscMessage currentPacket;
    
public:
    
    bool newPlayerJoined();
    bool playerLeft();
    
    Player getNewPlayer(const ofxOscMessage & message);
    
    
    
private:
    
    void parseMessage();
    
};

#endif
