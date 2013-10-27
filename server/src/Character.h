//
//  Character.h
//  server
//
//  Created by bdorse on 10/26/13.
//
//

#ifndef server_Character_h
#define server_Character_h

#include "ofMain.h"

class Character{
    
    public:
    
        Character(){};
        Character(string clientIP,
                  string playerName,
                  int red,
                  int green,
                  int blue,
                  float size,
                  float speed,
                  vector<ofPoint> points);
    
        void update();
        void draw();
        void addCoin();
    
        int getCoins();
        string getClientIP();
    
        bool isFinished();
    
    private:
    
        string clientIP;
        string playerName;
        int red;
        int green;
        int blue;
        int coins;
        float size;
        float speed;
        vector<ofPoint> points;
    
        ofVec2f targetPos;
        ofVec2f currentPos;
    
        void init(string& clientIP,
                  string& playerName,
                  int& red,
                  int& green,
                  int& blue,
                  float& size,
                  float& speed,
                  vector<ofPoint>& points);
};

#endif
