//
//  File.cpp
//  client
//
//  Created by bdorse on 10/24/13.
//
//

#include "GameField.h"

//--------------------------------------------------------------
GameField::GameField(){
    
    height = ofGetHeight();
    width = height*1.33;
    
    maxPoints = 5;
    pointRadius = 20;
    
    field = ofRectangle(ofGetWidth() - getWidth(), ofGetHeight() - getHeight(), getWidth() , getHeight());
    
}

//--------------------------------------------------------------
void GameField::update(){
    for(int i = 0; i < locations.size(); i++){
        locations[i].update();
    }
}

//--------------------------------------------------------------
void GameField::draw(){
    for(int i = 0; i < locations.size(); i++){
        locations[i].draw();
        if(i < locations.size() - 1){
            //COME BACK
            ofLine(locations[i].getX(), locations[i].getY(), locations[i+1].getX(), locations[i+1].getY());
        }
    }
    drawThumbnails();
}

//--------------------------------------------------------------
void GameField::drawThumbnails(){
    
    int radius = 10;
    int spacing = radius*2;
    int paddingLeft = radius;
    int paddingTop  = spacing;
    

    int startX = ofGetWidth() - paddingLeft - radius;
    int x = startX;
    int y = paddingTop;
    
    int numbThumbnails = maxPoints - locations.size();
    while(numbThumbnails > 0){
        ofCircle(x, y, radius);
        x -= spacing + radius;
        numbThumbnails--;
    }
   
}

//--------------------------------------------------------------
bool GameField::addLocation(float x, float y){
    if(locations.size() < maxPoints){
        Location loc;
        loc.set(x, y, pointRadius);
        locations.push_back(loc);
        return true;
    }else return false;
}

//--------------------------------------------------------------
bool GameField::removeLocation(int x, int y){
    for(int i = 0; i < locations.size(); i++){
       
        if(locations[i].inside(x, y)){
            vector<Location>::iterator it = locations.begin();
            advance(it, i);
            locations.erase(it);
            return true;
        }
    }
    return false;
}

//--------------------------------------------------------------
bool GameField::hasLocations(){
    return locations.size() > 0;
}

//--------------------------------------------------------------
bool GameField::inside(float x, float y){
    return field.inside(x, y);
}

//--------------------------------------------------------------
int GameField::getWidth(){
    return width;
}

//--------------------------------------------------------------
int GameField::getHeight(){
    return height;
}

//--------------------------------------------------------------
float GameField::getStartX(){
    return field.x;
}

//--------------------------------------------------------------
float GameField::getAspectRatio(){
    return field.getAspectRatio();
}

//--------------------------------------------------------------
vector<string> GameField::getLocations(){
    vector<string> vectorToReturn;
    for(int i = 0; i < locations.size(); i++){
        string x = ofToString(locations[i].getX() - getStartX());
        string y = ofToString(locations[i].getY());
        vectorToReturn.push_back(x+","+y);
    }
    return vectorToReturn;
}
