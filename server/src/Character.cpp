//
//  Character.cpp
//  server
//
//  Created by bdorse on 10/26/13.
//
//

#include "Character.h"

//--------------------------------------------------------------
Character::Character(string clientIP, string playerName, int red, int green, int blue, float size, float speed, vector<ofPoint> points){
    init(clientIP, playerName, red, green, blue, size, speed, points);
    currentPos = ofVec2f(points[0].x, points[0].y);
    coins = 0;
}

//--------------------------------------------------------------
void Character::init(string& _clientIP,
          string& _playerName,
          int& _red,
          int& _green,
          int& _blue,
          float& _size,
          float& _speed,
          vector<ofPoint>& _points)
{
    clientIP = _clientIP;
    playerName = _playerName;
    red = _red;
    green = _green;
    blue = _blue;
    size = _size;
    speed = _speed;
    points = _points;
    
    for(int i = 0; i < points.size(); i++){
        cout<<"Point number "<<ofToString(i)<<" contains "<<points[i].x<<", "<<points[i].y<<endl;
    }
    
    finished = false;
    targetIndex = 1;
    currentPos = ofVec2f(points[0].x, points[0].y);
    targetPos = ofVec2f(points[targetIndex].x, points[targetIndex].y);
}

//--------------------------------------------------------------
void Character::update(){
    
    if(!finished){
        ofVec2f dir(targetPos - currentPos);
        dir = dir.normalize();
        currentPos += dir * speed;
        
        //if currentPos reached targetPos
        if(currentPos.distance(targetPos) < size){
            
            //If the last targt is reached
            if(targetIndex == points.size() - 1){
                finished = true;
            }else{ //pick new target pos...
                targetIndex++;
                targetPos = points[targetIndex];
            }
        }
    }
    //cout<<"Current position: "<<ofToString(currentPos.x)<<", "<<ofToString(currentPos.y)<<endl;
}

//--------------------------------------------------------------
void Character::draw(){
    ofSetColor(red, green, blue);
    ofCircle(currentPos.x, currentPos.y, size);
}

//--------------------------------------------------------------
void Character::addCoin(){
    coins++;
}

//--------------------------------------------------------------
bool Character::isFinished(){
    return finished;
}

//--------------------------------------------------------------
int Character::getCoins(){
    return coins;
}

//--------------------------------------------------------------
string Character::getClientIP() const{
    return clientIP;
}
