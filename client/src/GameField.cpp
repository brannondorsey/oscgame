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
    }
}

//--------------------------------------------------------------
void GameField::addPoint(float x, float y){
    if(points.size() < maxPoints){
        points.push_back(ofPoint(x, y));
        Location loc;
        loc.set(x, y, pointRadius);
        locations.push_back(loc);
//        locations[locations.size()].set(x, y, pointRadius);
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
float GameField::getAspectRatio(){
    return field.getAspectRatio();
}


//--------------------------------------------------------------
vector<string> GameField::getMovementData(){
    vector<string> vectorToReturn;
    for(int i = 0; i < points.size(); i++){
        cout<<"I am in here"<<endl;
        vectorToReturn[i] = ofToString(points[i].x) + "," + ofToString(points[i].y);
    }
    return vectorToReturn;
}
