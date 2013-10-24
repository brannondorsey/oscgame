//
//  Point.cpp
//  client
//
//  Created by bdorse on 10/24/13.
//
//

#include "Location.h"

//--------------------------------------------------------------
void Location::set(int x, int y, int _radius){
    setPoint(x, y);
    radius = _radius;
    bIsSet = true;
}

//--------------------------------------------------------------
void Location::update(){
    
}

//--------------------------------------------------------------
void Location::draw(){
    ofCircle(point, radius);
}

//--------------------------------------------------------------
void Location::setPoint(int x, int y){
    point = ofPoint(x, y);
}

//--------------------------------------------------------------
void Location::setRadius(int _radius){
    radius = _radius;
}

//--------------------------------------------------------------
bool Location::inside(int x, int y){
    return ofDist(point.x, point.y, x, y) < radius;
}

//--------------------------------------------------------------
bool Location::isSet(){
    return bIsSet;
}

//--------------------------------------------------------------
float Location::getRadius(){
    return radius;
}

//--------------------------------------------------------------
ofPoint Location::getPoint(){
    return point;
}