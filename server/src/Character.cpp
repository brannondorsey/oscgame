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
}

//--------------------------------------------------------------
void Character::update(){
    ofVec2f dir(targetPos - currentPos);
    dir.normalize();
    currentPos = dir * speed;
    
    //if currentPos reached targetPos
    if(currentPos.distance(targetPos) < size){
        //pick new target pos...
    }
}

//--------------------------------------------------------------
void Character::draw(){
    ofSetColor(red, green, blue);
    ofCircle(currentPos.x, currentPos.y, size);
}
