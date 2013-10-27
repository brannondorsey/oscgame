//
//  GameHandler.h
//  emptyExample
//
//  Created by bdorse on 10/13/13.
//
//

#ifndef _OF_GAMEHANDLER
#define _OF_GAMEHANDLER

#include "ofMain.h"

#include "DataHandler.h"
#include "Player.h"

class GameHandler {
    
public:    
    DataHandler dataHand;
    vector<Player> users;
    bool isPlaying;
    
    GameHandler();
    void update();
    void display();
    void addPlayer(Player &player);
    void removePlayer(Player &player);
    void startGameCountdown();
    void startNewGame();
    void endGame();
    
private:
        
};


#endif
