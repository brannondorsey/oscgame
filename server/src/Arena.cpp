//
//  Arena.cpp
//  server
//
//  Created by bdorse on 10/27/13.
//
//

#include "Arena.h"

//--------------------------------------------------------------
void Arena::update(){
    updateCharacters();
    updateLocations();
}

//--------------------------------------------------------------
void Arena::draw(){
    drawCharacters();
    drawLocations();
}

//--------------------------------------------------------------
void Arena::previewLocation(const Location& location){
    locations.push_back(location);
}

//--------------------------------------------------------------
void Arena::addCharacter(const Character& newCharacter){
    characters.push_back(newCharacter);
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
bool Arena::hasExpiredCharacters(){
    return expiredCharacters.size() > 0;
}

//--------------------------------------------------------------
vector<Character> Arena::getExpiredCharacters(){
    vector<Character> characters = expiredCharacters;
    expiredCharacters.clear();
    return characters;
}



