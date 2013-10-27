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

class Arena{
  
    public:
    
        void update();
        void draw();
    
        void previewLocation(const Location& location);
        void addCharacter(const Character& character);
    
        bool hasExpiredCharacters();
    
        vector<Character> getExpiredCharacters();
    
    private:
    
        vector<Character> expiredCharacters;
        vector<Character> characters;
        vector<Location> locations;
    
        void updateLocations();
        void updateCharacters();

        void drawLocations();
        void drawCharacters();

};

#endif
