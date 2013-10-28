//
//  ScoreBoard.cpp
//  server
//
//  Created by bdorse on 10/27/13.
//
//

#include "Scoreboard.h"

//--------------------------------------------------------------
Scoreboard::Scoreboard(){
    fontColor = ofColor(255);
    bgColor = ofColor(40);
    font.loadFont("NewMedia Fett.ttf", 14);
}

void Scoreboard::setup(int endX){
    bounds = ofRectangle(0, 0, endX, ofGetHeight());
}

//--------------------------------------------------------------
void Scoreboard::updatePlayerIcons(vector<Character> characters){
    for(int i = 0; i < characters.size(); i++){
        Character character = characters[i];
        //if character belongs to and old player update their icon and name
        int position = findPlayer(character);
        if(position != -1){
            players[position] = character;
        }else{ //otherwise add the player becuase they are knew
            players.push_back(character);
        }
    }
}

//--------------------------------------------------------------
void Scoreboard::updateScores(vector<Character> characters){
    for(int i = 0; i < players.size(); i++){
        players[i].setCoins(characters[i].getCoins());
    }
}

//--------------------------------------------------------------
void Scoreboard::draw(){
    
    int textStartHeight = 50;
    int thumbnailRadius = 15;
    int paddingLeft = 10;
    int paddingTop = 40;
    
    int thumbnailPadding = 10;
    
    int x = paddingLeft + thumbnailPadding*2 + thumbnailRadius*2;
    int y = textStartHeight;
    
    int circleX = paddingLeft + thumbnailRadius + thumbnailPadding;
    int circleY = y - font.getLineHeight()/2;
    
    ofSetColor(bgColor);
    ofRect(bounds);
    
    for(int i = 0; i < players.size(); i++){
        Character player = players[i];
        ofSetColor(player.getColor());
        ofCircle(circleX, circleY, thumbnailRadius);
        
        ofSetColor(fontColor);
        string name = player.getPlayerName();
        font.drawString(name+ ": " + ofToString(player.getCoins()), x, y);
        x += paddingTop;
    }
}

//--------------------------------------------------------------
int Scoreboard::findPlayer(const Character& character){
    for(int i = 0; i < players.size(); i++){
        Character player = players[i];
        if(player.getClientIP() == character.getClientIP()){
            return i;
        }
    }
    return -1;
}