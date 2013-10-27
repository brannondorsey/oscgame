//
//  Coin.cpp
//  server
//
//  Created by bdorse on 10/27/13.
//
//

#include "Coin.h"

//--------------------------------------------------------------
Coin::Coin(int x, int y){
    ofPoint point(x, y);
    init(point);
}

//--------------------------------------------------------------
Coin::Coin(ofPoint point){
    init(point);
}

//--------------------------------------------------------------
void Coin::init(const ofPoint& point){
    int width = 13;
    int height = 18;
    rounded = 2;
    color = ofColor(255, 226, 36);
    rect = ofRectangle(point.x, point.y, width, height);
}

//--------------------------------------------------------------
void Coin::draw(){
    ofSetColor(color);
    ofRectRounded(rect, rounded);
}

//--------------------------------------------------------------
bool Coin::intersects(const Character& character){
    float radius = character.getSize();
    ofVec2f currentPos = character.getCurrentPos();
    ofPoint circleDistance(currentPos.distance(ofVec2f(rect.x, rect.y)));
    
    if (circleDistance.x > (rect.getWidth()/2 + radius)) { return false; }
    if (circleDistance.y > (rect.getHeight()/2 + radius)) { return false; }
    
    if (circleDistance.x <= (rect.getWidth()/2)) { return true; }
    if (circleDistance.y <= (rect.getHeight()/2)) { return true; }
    
    float cornerDistanceSq = pow((circleDistance.x - rect.getWidth()/2), 2) +
    pow((circleDistance.y - rect.height/2), 2);
    
    return (cornerDistanceSq <= (pow(radius, 2)));
}
            
//--------------------------------------------------------------
const ofRectangle& Coin::getRectangle(){
    
}
