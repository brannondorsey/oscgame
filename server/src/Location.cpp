//
//  Location.cpp
//  server
//
//  Created by bdorse on 10/26/13.
//
//

#include "Location.h"

Location::Location(int x, int y, float red, float green, float blue, ofColor fillColor){
    
    animationTime = 1500;
    minRadius = .5;
    maxRadius = 20;
    
    strokeSize = 10;
    
    modifier = 1; 
    radius = minRadius;
    radiusIncrement = ((maxRadius - minRadius) / ((animationTime/1000) * ofGetFrameRate())) * 2;
    //COME BACK AND FIGURE OUT THE radiusIncrement
    init(ofPoint(x, y), red, green, blue, fillColor);
    started = false;
}

//--------------------------------------------------------------
void Location::init(ofPoint _center, float& _red, float& _green, float& _blue, ofColor& _fillColor){
    center = _center;
    red = _red;
    green = _green;
    blue = _blue;
    fillColor = _fillColor;
}

//--------------------------------------------------------------
void Location::update(){
    if(!started){
        timer.setup(animationTime, false);
        timer.startTimer();
        started = true;
    }
    // if max size reached
    if(radius >= maxRadius){
        modifier = -modifier;
    }
    radius += radiusIncrement * modifier;
}

//--------------------------------------------------------------
void Location::draw(){
    if(!finishedDisplaying()){
        ofSetColor(red, green, blue);
        ofCircle(center, radius);
        
        float tempStrokeSize;
        if(radius < strokeSize) tempStrokeSize = radius;
        else tempStrokeSize = strokeSize;
        ofSetColor(fillColor);
        ofCircle(center, radius - tempStrokeSize);
    }
}

//--------------------------------------------------------------
bool Location::finishedDisplaying(){
    return timer.isTimerFinished() || radius < 0;
}
