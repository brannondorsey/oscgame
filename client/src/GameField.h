//
//  GameField.h
//  client
//
//  Created by bdorse on 10/24/13.
//
//

#ifndef client_GameField_h
#define client_GameField_h
#include "ofMain.h"
#include "Location.h"

class GameField{
    
    public:
    
        GameField();
    
        void update();
        void draw();
        void reset();
        void enable();
        void disable();
    
        bool addLocation(float x, float y);
        bool hasEnoughLocations();
        bool inside(float x, float y);
        bool removeLocation(int x, int y);
        bool locationsFull();
        bool isDisabled();
    
        int getWidth();
        int getHeight();
        float getStartX();
        float getAspectRatio();
    
        vector<string> getLocations();

    protected:

        int maxPoints;
        int width;
        int height;
        int pointRadius;
        int mx;
        int my;
    
        bool disabled;
    
        vector<Location> locations;
    
        ofColor disabledColor;
        ofRectangle field;
    
        void drawThumbnails();
    
};

#endif
