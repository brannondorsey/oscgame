//
//  Location.h
//  server
//
//  Created by bdorse on 10/26/13.
//
//

#ifndef server_Location_h
#define server_Location_h

#include "ofMain.h"
#include "ofxTimer.h"

class Location{
    
    public:
        
        Location(){};
        Location(int x, int y, float red, float green, float blue, ofColor fillColor);
    
        void update();
        void draw();
    
        bool finishedDisplaying();
    
    private:
        
        bool started;
    
        int maxRadius;
        int animationTime;
        int modifier;
        int strokeSize;
    
        float minRadius;
        float radius;
        float radiusIncrement;
        float red;
        float green;
        float blue;

        ofPoint center;
        ofColor fillColor;
        ofxTimer timer;
    
        void init(ofPoint _center, float& _red, float& _green, float& _blue, ofColor& _fillColor);
};


#endif
