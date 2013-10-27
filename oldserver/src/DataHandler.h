//
//  DataHandler.h
//  emptyExample
//
//  Created by bdorse on 10/13/13.
//
//

#ifndef _OF_DATAHANDLER
#define _OF_DATAHANDLER

#include "ofMain.h"
#include "Player.h"
#include "ofxOsc.h"

class DataHandler{
    
    ofxOscMessage currentPacket;
    
public:
    
    bool newPlayerJoined();
    bool playerLeft();
    
    Player& getNewPlayer();
    Player& getLeftPlayer();
    
    
    
private:
//    Player player;
    void parseMessage();
    
};

#endif
