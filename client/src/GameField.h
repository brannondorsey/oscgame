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
    
        vector<string> getMovementData();

    protected:

        int maxPoints;
        int width;
        int height;
    
        vector<ofVec2f> points;
    
        ofRectangle field;
    

};

#endif
