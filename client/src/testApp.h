#ifndef TESTAPP
#define TESTAPP

#include "ofMain.h"
#include "ofxUI.h"

class testApp : public ofBaseApp 
{
	public:
	void setup();
	void update();
	void draw();
	void exit(); 

	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	ofxUICanvas *gui;
    ofxUICanvas *gui2;
	void guiEvent(ofxUIEventArgs &e);
    bool drawPadding;
    int modifier;

    float dir;
	float red, green, blue, size, speed, mspeed;
    string inputName;
    float *buffer;
    float yLoc;
    float dim;
	float xInit;
    float length;
    ofImage middle;
    void GUI();
    float centerUI;
    bool enterButton;
    vector<string> data;
    bool myGui;
};

#endif