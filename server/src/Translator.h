//
//  Translator.h
//  server
//
//  Created by bdorse on 10/27/13.
//
//

#ifndef server_Translator_h
#define server_Translator_h

#include "ofMain.h"

class Translator{
  
    public:
    
        static ofPoint getArenaPoint(float gameFieldX, float gameFieldY, float gameFieldWidth, float gameFieldHeight);
        static ofVec2f getArenaVector(float gameFieldX, float gameFieldY, float gameFieldWidth, float gameFieldHeight);
        static float getArenaSize(float gameFieldSizeAsPercent);
        static float getArenaSpeed(float gameFieldSpeedAsPercent);
        static float aspectRatio;
    
    private:

        static float minSize;
        static float maxSize;
        static float minSpeed;
        static float maxSpeed;
    
};

#endif
