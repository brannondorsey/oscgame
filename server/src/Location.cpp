//
//  Location.cpp
//  server
//
//  Created by bdorse on 10/26/13.
//
//

#include "Location.h"

Location::Location(int x, int y, float red, float green, float blue){
    
    animationTime = 2000;
    minRadius = .5;
    maxRadius = 20;
    
    radius = minRadius;
    //COME BACK AND FIGURE OUT THE radiusIncrement
    init(ofPoint(x, y), red, green, blue);
    started = false;
}

//--------------------------------------------------------------
void Location::init(ofPoint _center, float& _red, float& _green, float& _blue){
    center = _center;
    red = _red;
    green = _green;
    blue = _blue;
}

//--------------------------------------------------------------
void Location::update(){
    if(!started){
        timer.setup(animationTime, false);
        timer.startTimer();
        started = true;
    }
    
}

//--------------------------------------------------------------
void Location::draw(){
    ofSetColor(red, green, blue);
    ofCircle(center, 10);
}

//--------------------------------------------------------------
bool Location::finishedDisplaying(){
    return timer.isTimerFinished();
}
