//
//  Header.h
//  emptyExample
//
//  Created by bdorse on 10/13/13.
//
//

#ifndef _OF_PLAYER
#define _OF_PLAYER

#include "ofMain.h"
#include "Character.h"

class Player{
    
public:
    
    int id;
    string name;
    vector<ofPoint> points;
    Character character;
    
    void addCharacterToArena(const Character &character);
};

#endif
