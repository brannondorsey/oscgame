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
    
        bool addLocation(float x, float y);
        bool hasLocations();
        bool inside(float x, float y);
        bool removeLocation(int x, int y);
        bool locationsFull();
    
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
    
        vector<Location> locations;
    
        ofRectangle field;
    
        void drawThumbnails();
    
};

#endif
