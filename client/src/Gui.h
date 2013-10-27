//
//  Gui.h
//  client
//
//  Created by bdorse on 10/23/13.
//
//

#ifndef client_Gui_h
#define client_Gui_h
#include "ofMain.h"
#include "ofxUI.h"

class Gui {
    
    public:
    
        Gui();
        //Gui(int widgetWidth);
        //~Gui();
    
        void setup(int width);
        void update();
        void draw();
        void exit();
    
        void guiEvent(ofxUIEventArgs &e);
        bool submitted();
    
        int getRed();
        int getGreen();
        int getBlue();
        int getGuiWidth();
        float getSize();
        float getSpeed();
    
        string getPlayerName();
    
        vector<string> getCharacterData();
    
    protected:
    
        bool drawPadding;
        bool enterButton;
        bool submit;
        bool myGui;
    
        int modifier;
        int bounceAreaMin;
        int bounceAreaMax;
    
        //character properties
        float yLoc;
        float dir;
        float red, green, blue;
        float size, mSize, minSize, maxSize;
        float speed, mSpeed, minSpeed, maxSpeed;
        
        float *buffer;
        float dim;
        float xInit;
        float length;
        float centerUI;
        
        string playerName;
        string placeHolder;
    
        vector<string> data;
        
        ofImage middle;
        
        ofxUICanvas *gui;
    
        void calcInversePorportion(float indiVal,
                                   float &deVal,
                                   float indiValMin,
                                   float indiValMax,
                                   float deValMin,
                                   float deValMax);
    
        string generateName(int length);
};

#endif
