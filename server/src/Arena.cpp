//
//  Arena.cpp
//  server
//
//  Created by bdorse on 10/27/13.
//
//

#include "Arena.h"

Arena::Arena(){
    
    numCoins = 20;
    coins.resize(numCoins);
    
    ofSeedRandom();
    for(int i = 0; i < numCoins; i++){
        int x = (int) ofRandomWidth();
        int y = (int) ofRandomHeight();
        coins[i] = Coin(x, y);
    }
}

//--------------------------------------------------------------
void Arena::update(){
    updateCharacters();
    updateLocations();
    
    //loop through all coins and see if characters have hit them
    for(int i = 0; i < coins.size(); i++){
        Coin coin = coins[i];
        
        for(int j = 0; j < characters.size(); j++){
            if(coin.intersects(characters[j])){
                
                //remove that coin from the vector
                coins.erase(coins.begin() + i);
            }
        }
    }
}

//--------------------------------------------------------------
void Arena::draw(){
    drawCoins();
    drawCharacters();
    drawLocations();
}

//--------------------------------------------------------------
void Arena::previewLocation(const Location& location){
    locations.push_back(location);
}

//--------------------------------------------------------------
void Arena::addCharacter(const Character& newCharacter){
    if(!characterInArena(newCharacter)){
        characters.push_back(newCharacter);
    }
}

//--------------------------------------------------------------
void Arena::updateLocations(){
    for(int i = 0; i < locations.size(); i++){
        locations[i].update();
        if(locations[i].finishedDisplaying()){
            locations.erase(locations.begin() + i);
        }
    }
}

//--------------------------------------------------------------
void Arena::updateCharacters(){
    for(int i = 0; i < characters.size(); i++){
        characters[i].update();
        if(characters[i].isFinished()){
            Character oldCharacter = characters[i]; //make a copy
            expiredCharacters.push_back(oldCharacter);
            characters.erase(characters.begin() + i);
        }
    }
}

//--------------------------------------------------------------
void Arena::drawLocations(){
    for(int i = 0; i < locations.size(); i++){
        locations[i].draw();
    }
}

//--------------------------------------------------------------
void Arena::drawCharacters(){
    for(int i = 0; i < characters.size(); i++){
        characters[i].draw();
    }
}

//--------------------------------------------------------------
void Arena::drawCoins(){
    for(int i = 0; i < coins.size(); i++){
        coins[i].draw();
    }
}

//--------------------------------------------------------------
bool Arena::hasExpiredCharacters(){
    return expiredCharacters.size() > 0;
}

//--------------------------------------------------------------
bool Arena::characterInArena(const Character& character){
    string characterIP = character.getClientIP();
    for(int i = 0; i < characters.size(); i++){
        string existingCharacterIP = characters[i].getClientIP();
        if(existingCharacterIP == characterIP) return true;
    }
    return false;
}

//--------------------------------------------------------------
vector<Character> Arena::getExpiredCharacters(){
    vector<Character> characters = expiredCharacters;
    expiredCharacters.clear();
    return characters;
}



