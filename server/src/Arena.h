//
//  Arena.h
//  server
//
//  Created by bdorse on 10/26/13.
//
//

#ifndef server_Arena_h
#define server_Arena_h

#include "ofMain.h"
#include "Character.h"
#include "Location.h"
#include "ofxTimer.h"
#include "Coin.h"

class Arena{
  
    public:
    
        Arena();
        void update();
        void draw();
    
        void previewLocation(const Location& location);
        void addCharacter(const Character& character);
        
        bool hasExpiredCharacters();
    
        int getWidth();
        int getHeight();
        int getStartX();
    
        bool scoreChanged();
    
        vector<Character> getExpiredCharacters();
        vector<Character> getCharacters();
    
    private:
    
        int numCoins;
        int height;
        int width;
    
        float coinReginRate;
    
        bool scoreChange;
    
        vector<Character> expiredCharacters;
        vector<Character> characters;
        vector<Location> locations;
        vector<Coin> coins;
    
        ofRectangle bounds;

        void updateLocations();
        void updateCharacters();
        void updateCoins();
        void drawLocations();
        void drawCharacters();
        void drawCoins();
        void addCoins(int numCoins);
    
        bool characterInArena(const Character& character);
        
};

#endif
