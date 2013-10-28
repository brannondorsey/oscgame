//
//  ScoreBoard.h
//  server
//
//  Created by bdorse on 10/27/13.
//
//

#ifndef server_Scoreboard_h
#define server_Scoreboard_h

#include "ofMain.h"
#include "Character.h"

class Scoreboard{
  
    public:
    
        Scoreboard();
        void setup(int endX);
        void updatePlayerIcons(vector<Character> characters);
        void updateScores(vector<Character> characters);
        void draw();
    
    private:
    
        vector<string> knownClients;
        vector<Character> players;
    
        ofColor bgColor;
        ofColor fontColor;
    
        ofRectangle bounds;
    
        ofTrueTypeFont font;
    
        //returns index int if character is found in players and -1 if not
        int findPlayer(const Character& character);
};


#endif
