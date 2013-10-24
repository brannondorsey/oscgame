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
    
    width = 1280;
    height = 720;
    
    maxPoints = 5;
    field = ofRectangle(ofGetWidth() - getWidth(), ofGetHeight() - getHeight(), getWidth() , getHeight());
    
}

//--------------------------------------------------------------
void GameField::update(){
    
}

//--------------------------------------------------------------
void GameField::draw(){
    
}

//--------------------------------------------------------------
void GameField::addPoint(float x, float y){
    if(points.size() - maxPoints){
        points.push_back(ofVec2f(x, y));
    }
}

//--------------------------------------------------------------
bool GameField::hasPoints(){
    return points.size() > 0;
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
vector<string> GameField::getMovementData(){
    vector<string> vectorToReturn;
    for(int i = 0; i < points.size(); i++){
        vectorToReturn[i] = ofToString(points[i].x) + "," + ofToString(points[i].y);
    }
    return vectorToReturn;
}
