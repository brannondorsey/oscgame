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
        gameHand.addPlayer(dataHand.getNewPlayer());
    }
    if(dataHand.playerLeft()){
        gameHand.removePlayer(dataHand.getLeftPlayer());
    }
    if(gameHand.isPlaying){
        
    }

}

void GameHandler::display(){
    
}

void GameHandler::addPlayer(){
    
}


void GameHandler::removePlayer(){
    
}

void GameHandler::startGameCountdown{
    
}


void GameHandler::startNewGame(){
    
}

void GameHandler::endGame(){
    
}