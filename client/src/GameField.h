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
        void addPoint(float x, float y);
    
        bool hasPoints();
        bool inside(float x, float y);
    
        int getWidth();
        int getHeight();
        float getStartX();
        float getAspectRatio();
    
        vector<string> getMovementData();

    protected:

        int maxPoints;
        int width;
        int height;
        int pointRadius;
    
        vector<ofPoint> points;
        vector<Location> locations;
    
        ofRectangle field;
    
};

#endif
