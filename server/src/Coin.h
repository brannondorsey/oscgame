//
//  Coins.h
//  server
//
//  Created by bdorse on 10/27/13.
//
//

#ifndef server_Coins_h
#define server_Coins_h

#include "ofMain.h"
#include "Character.h"

class Coin{
    
    public:
        
        Coin(){};
        Coin(int x, int y);
        Coin(ofPoint point);
        void init(const ofPoint& point);
        void draw();
    
        bool intersects(const Character& character);
        const ofRectangle& getRectangle();
    
    private:
    
        float rounded;
        ofColor color;
        ofRectangle rect;
};

#endif
