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
        void setCoins(int numCoins);
    
        int getCoins();
        float getSize() const;
        ofColor getColor();
        ofVec2f getCurrentPos() const;
        string getPlayerName();
        string getClientIP() const;
    
        bool isFinished();
    
    private:
    
        bool finished;
        int targetIndex;
        int red;
        int green;
        int blue;
        int coins;
        float size;
        float speed;
    
        string clientIP;
        string playerName;
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
