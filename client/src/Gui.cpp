//
//  Gui.cpp
//  client
//
//  Created by bdorse on 10/23/13.
//
//

#include "Gui.h"
#include "testApp.h"

//--------------------------------------------------------------
Gui::Gui(){
    
}

//--------------------------------------------------------------
void Gui::setup(int width){
    
    ofSeedRandom();
    submit = false;
    
    float dim = 24;
	float xInit = OFX_UI_GLOBAL_WIDGET_SPACING;
    float length = width - xInit;
    
    placeHolder = "Your Name";
    
    minSize = 20;
    maxSize = 65;
    
    minSpeed = 1;
    maxSpeed = 8;
    
    //0 - 100
    int test = (int) ofRandom(100);
    speed = (int) ofRandom(100);
    cout<<"The test is: "<<ofToString(test)<<endl;
    cout<<"The speed is: "<<ofToString(speed)<<endl;
    size = (int) 100 - speed;
    
    red = (int) ofRandom(2, 256);
    blue = (int) ofRandom(2, 256);
    green = (int) ofRandom(2, 256);
	
    yLoc = ofGetHeight()/2+size/2;
    dir = 1;
    
    int padding = 60;
    bounceAreaMin = 330 + padding;
    bounceAreaMax = ofGetHeight() - padding;
    
    drawPadding = false;
    
    gui = new ofxUICanvas(0, 0, length+xInit, ofGetHeight()); // creates the gui canvas elements
    centerUI = (length+xInit)/2;
    buffer = new float[256];
    for(int i = 0; i < 256; i++) { buffer[i] = ofNoise(i/100.0); }
    playerName = placeHolder;//text input
	gui->addWidgetDown(new ofxUILabel("Screen Name", OFX_UI_FONT_MEDIUM));
    gui->addSpacer(length-xInit, 1);
	gui->setWidgetFontSize(OFX_UI_FONT_LARGE);
	gui->addTextInput("Screen Name", playerName , length-xInit)->setAutoClear(false);
    gui->addWidgetDown(new ofxUILabel("Select Your Attributes", OFX_UI_FONT_MEDIUM));
    gui->addSpacer(length-xInit, 1);
    gui->addSlider("RED", 0.0, 255.0, red, length-xInit, dim);
    gui->addSlider("GREEN", 0.0, 255.0, green, length-xInit, dim);
    gui->addSlider("BLUE", 0.0, 255.0, blue, length-xInit, dim);
    gui->addSlider("SIZE", 0.0, 100.0, &size, length-xInit, dim);
    gui->addSlider("SPEED", 0.0, 100.0, &speed, length-xInit, dim);
    //gui->addSpacer(length-xInit, 1);
    gui->addLabelButton("Enter", false);
    //gui->addSpacer(length-xInit, 1);
    gui->setColorBack(ofColor(255,100));
	ofBackground(red, green, blue);
	ofAddListener(gui->newGUIEvent,this,&Gui::guiEvent);
    myGui = true;
    
}

//--------------------------------------------------------------
void Gui::update(){
    mSpeed = ofMap(speed, 0 , 100 , minSpeed , maxSpeed);
    mSize = ofMap(size, 0, 100, minSize, maxSize);
    
    if (yLoc + size/2 > bounceAreaMax){
        yLoc = bounceAreaMax - size/2;
        dir = -dir;
    }
    if(yLoc - size/2 < bounceAreaMin){
        yLoc = bounceAreaMin + size/2;
        dir = -dir;
    }
    yLoc += mSpeed * dir;
}

//--------------------------------------------------------------
void Gui::draw(){
    
    int i = 0;
	ofBackground(0, 150, 225, 255);
    ofSetColor(red,green,blue);
    ofCircle(centerUI, yLoc, mSize);
    
}

//--------------------------------------------------------------
float Gui::getRed(){
    return red;
}

//--------------------------------------------------------------
float Gui::getGreen(){
    return green;
}

//--------------------------------------------------------------
float Gui::getBlue(){
    return blue;
}

//--------------------------------------------------------------
float Gui::getSize(){
    return size;
}

//--------------------------------------------------------------
float Gui::getSpeed(){
    return speed;
}

//--------------------------------------------------------------
string Gui::getPlayerName(){
    return (playerName != placeHolder) ? playerName : generateName(8);
}

//--------------------------------------------------------------
void Gui::guiEvent(ofxUIEventArgs &e)
{
	string name = e.widget->getName();
	int kind = e.widget->getKind();
    int i = 0;
	if(name == "RED")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		red = slider->getScaledValue();
        cout << "value: " << slider->getScaledValue() << endl;
	}else if(name == "Enter")
    {
        //cout<<"I got a ping"<<endl;
        submit = true;
//        ofxUIToggle *Enter = (ofxUIToggle *) e.widget;
//        enterButton = Enter->getValue();
    }
	else if(name == "GREEN")
	{
		ofxUIMinimalSlider *slider = (ofxUIMinimalSlider *) e.widget;
		green = slider->getScaledValue();
        cout << "value: " << slider->getScaledValue() << endl;
	}
	else if(name == "BLUE")
	{
		ofxUIBiLabelSlider *slider = (ofxUIBiLabelSlider *) e.widget;
		blue = slider->getScaledValue();
        cout << "value: " << slider->getScaledValue() << endl;
	}
    else if(name == "SIZE")
	{
		ofxUIBiLabelSlider *slider = (ofxUIBiLabelSlider *) e.widget;
		size = slider->getScaledValue();
        calcInversePorportion(size, speed, 0, 100, 0, 100);
        cout << "value: " << slider->getScaledValue() << endl;
	}
    else if(name == "SPEED")
	{
		ofxUIBiLabelSlider *slider = (ofxUIBiLabelSlider *) e.widget;
		speed = slider->getScaledValue();
        calcInversePorportion(speed, size, 0, 100, 0, 100);
        cout << "speed is: " << speed << endl;
	}
    
    
    else if(name == "Screen Name")
    {
        ofxUITextInput *textinput = (ofxUITextInput *) e.widget;
        if(textinput->getTriggerType() == OFX_UI_TEXTINPUT_ON_ENTER)
        {
            string output = textinput->getTextString();
            playerName = output;
            cout << output << endl;
        }
        else if(textinput->getTriggerType() == OFX_UI_TEXTINPUT_ON_FOCUS)
        {
            cout << "ON FOCUS: ";
        }
        else if(textinput->getTriggerType() == OFX_UI_TEXTINPUT_ON_UNFOCUS)
        {
            cout << "ON BLUR: ";
            string output = textinput->getTextString();
            playerName = output;
        }
        
    }
}

//--------------------------------------------------------------

bool Gui::submitted(){
    if(submit){
        submit = false;
        return true;
    }else return false;
}

//--------------------------------------------------------------
vector<string> Gui::getCharacterData(){
    vector<string> vectorToReturn;
    vectorToReturn.resize(6);
    vectorToReturn[0] = (playerName != placeHolder) ? playerName : generateName(8);
    vectorToReturn[1] = ofToString(red);
    vectorToReturn[2] = ofToString(green);
    vectorToReturn[3] = ofToString(blue);
    vectorToReturn[4] = ofToString(size);
    vectorToReturn[5] = ofToString(speed);
    return vectorToReturn;
}

//--------------------------------------------------------------
void Gui::exit(){
    delete gui;
}

//--------------------------------------------------------------
void Gui::calcInversePorportion(float indiVal, float &deVal, float indiValMin, float indiValMax, float deValMin, float deValMax){
    
    //independent value mapped to dependent value
    float indiMappedToDe = ofMap(indiVal, indiValMin, indiValMax, deValMax, deValMin);
    deVal = indiMappedToDe; //indiMappedToDe - deValMax;
}

//--------------------------------------------------------------
string Gui::generateName(int length){
    string stringToReturn = "";
    for(int i = 0; i < length; i ++){
        int randomDigit = (int) ofRandom(10);
        stringToReturn += ofToString(randomDigit);
    }
    return stringToReturn;
}



