//
//  GameHandler.cpp
//  emptyExample
//
//  Created by bdorse on 10/13/13.
//
//

#include "GameHandler.h"

GameHandler::GameHandler(){
    dataHand = new DataHandler();
}

void GameHandler::update(){
    if(dataHand.newPlayerJoined()){
        addPlayer(dataHand.getNewPlayer());
    }
    if(dataHand.playerLeft()){
        removePlayer(dataHand.getLeftPlayer());
    }
    if(isPlaying){
        
    }

}

void GameHandler::display(){
    
}

void GameHandler::addPlayer(){
    
}


void GameHandler::removePlayer(){
    
}

void GameHandler::startGameCountdown(){
    
}


void GameHandler::startNewGame(){
    
}

void GameHandler::endGame(){
    
}