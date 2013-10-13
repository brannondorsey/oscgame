//
//  GameHandler.h
//  emptyExample
//
//  Created by bdorse on 10/13/13.
//
//

#ifndef emptyExample_GameHandler_h
#define emptyExample_GameHandler_h
#include "Player.h"

class GameHandler{
    
public:
    DataHandler dataHand;
    vector<Player> users;
    bool isPlaying;
    
    GameHandler();
    void update();
    void display();
    void addPlayer();
    void removePlayer();
    void startGameCountdown();
    void startNewGame();
    void endGame();
    
private:

    
};


#endif
