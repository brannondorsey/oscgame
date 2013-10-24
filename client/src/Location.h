//
//  Point.h
//  client
//
//  Created by bdorse on 10/24/13.
//
//

#ifndef client_Location_h
#define client_Location_h

#include "ofMain.h"

class Location{
    
    public:

        Location(){bIsSet = false; };
    
        void set(int x, int y, int _radius);
        void update();
        void draw();
    
        void setPoint(int x, int y);
        void setRadius(int _radius);
    
        bool inside(int x, int y);
        bool isSet();
    
        float getRadius();
        
        ofPoint getPoint();
    
    protected:
    
        int radius;
        bool bIsSet;
        ofPoint point;
    
};

#endif
