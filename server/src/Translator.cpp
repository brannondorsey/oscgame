//
//  Translator.cpp
//  server
//
//  Created by bdorse on 10/27/13.
//
//

#include "Translator.h"

//--------------------------------------------------------------

float Translator::aspectRatio = 1.33;
float Translator::minSize = 20;
float Translator::maxSize = 65;
float Translator::minSpeed = 1;
float Translator::maxSpeed = 8;

//--------------------------------------------------------------
ofPoint Translator::getArenaPoint(float gameFieldX, float gameFieldY, float gameFieldWidth, float gameFieldHeight){
    float x = ofMap(gameFieldX, 0, gameFieldWidth, 0, ofGetWidth());
    float y = ofMap(gameFieldY, 0, gameFieldHeight, 0, ofGetHeight());
    return ofPoint(x, y);
}

//--------------------------------------------------------------
ofVec2f Translator::getArenaVector(float gameFieldX, float gameFieldY, float gameFieldWidth, float gameFieldHeight){
    ofPoint arenaPoint = getArenaPoint(gameFieldX, gameFieldY, gameFieldWidth, gameFieldHeight);
    return ofVec2f(arenaPoint.x, arenaPoint.y);
}

//--------------------------------------------------------------
float Translator::getArenaSize(float gameFieldSizeAsPercent){
    return ofMap(gameFieldSizeAsPercent, 1, 100, minSize, maxSize);
}

//--------------------------------------------------------------
float Translator::getArenaSpeed(float gameFieldSpeedAsPercent){
    return ofMap(gameFieldSpeedAsPercent, 1, 100, minSpeed, maxSpeed);
}


