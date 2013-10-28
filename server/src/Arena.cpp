//
//  Arena.cpp
//  server
//
//  Created by bdorse on 10/27/13.
//
//

#include "Arena.h"

Arena::Arena(){
    
    numCoins = 25;
    coinReginRate = .4; // 0 - 1
    coins.resize(numCoins);
    
    height = ofGetHeight();
    width = height*1.33;

    bounds = ofRectangle(ofGetWidth() - getWidth(), ofGetHeight() - getHeight(), getWidth() , getHeight());
    
    ofSeedRandom();
    addCoins(numCoins);
}

//--------------------------------------------------------------
void Arena::update(){
    updateCharacters();
    updateLocations();
    
    //every half second...
    if(ofGetFrameNum() % 30 == 0){
        //cout<<ofToString(ofGetFrameNum())<<endl;
        if(ofRandom(1) < coinReginRate) addCoins(1);
    }
    updateCoins();
        
    scoreChange = false;
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
        cout<<"I am updating a location"<<endl;
        if(locations[i].finishedDisplaying()){
            cout<<"I removed the location because the animation was over"<<endl;
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
void Arena::updateCoins(){
    //loop through all coins and see if characters have hit them
    for(int i = 0; i < coins.size(); i++){
        Coin coin = coins[i];
        
        for(int j = 0; j < characters.size(); j++){
            if(coin.intersects(characters[j])){
                
                //add the score to the character
                characters[j].addCoin();
                
                //remove that coin from the vector
                coins.erase(coins.begin() + i);
                
                scoreChange = true;
            }
        }
    }
}

//--------------------------------------------------------------
void Arena::drawLocations(){
    for(int i = 0; i < locations.size(); i++){
        cout<<"I should have drawn"<<endl;
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
void Arena::addCoins(int numCoins){
    int prevSize = coins.size();
    coins.resize(prevSize+numCoins);
    for(int i = prevSize; i < prevSize+numCoins; i++){
        int x = (int) ofRandom(bounds.x, getWidth() + bounds.x + 1);
        int y = (int) ofRandom(getHeight());
        coins[i] = Coin(x, y);
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
bool Arena::scoreChanged(){
    return scoreChange;
}

//--------------------------------------------------------------
int Arena::getWidth(){
    return width;
}

//--------------------------------------------------------------
int Arena::getHeight(){
    return height;
}

//--------------------------------------------------------------
int Arena::getStartX(){
    return bounds.x;
}

//--------------------------------------------------------------
vector<Character> Arena::getCharacters(){
    return characters;
}

//--------------------------------------------------------------
vector<Character> Arena::getExpiredCharacters(){
    vector<Character> characters = expiredCharacters;
    expiredCharacters.clear();
    return characters;
}



