#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
 	ofEnableSmoothing();
    ofSetCircleResolution(60);
    GUI();
    myGui = true;

}

//--------------------------------------------------------------
void testApp::update()
{
    mspeed = ofMap(speed, 0 , 100 , 0 , 15);
    if (yLoc > 650){
        dir -= mspeed;
    }if(yLoc < 390){
        dir = mspeed;
    }
    yLoc += dir;
    
}

//--------------------------------------------------------------
void testApp::draw()
{
    int i = 0;
	ofBackground(0, 150, 225, 255);
    ofSetColor(red,green,blue);
    ofCircle(centerUI, yLoc,size);

    if(enterButton == 1 &&  myGui == true){//if we press the enter button:
        cout << inputName << "," << red << "," << green << "," << blue << "," << size << "," << speed << endl;
        myGui = false;
    } if(myGui == false){
        gui->toggleVisible();
        //select path to move:
    }
}
//--------------------------------------------------------------
void testApp::guiEvent(ofxUIEventArgs &e)
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
        ofxUIToggle *Enter = (ofxUIToggle *) e.widget;
        enterButton = Enter->getValue();
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

        cout << "value: " << slider->getScaledValue() << endl;
	}
    else if(name == "SPEED")
	{
		ofxUIBiLabelSlider *slider = (ofxUIBiLabelSlider *) e.widget;
		speed = slider->getScaledValue();
        cout << "value: " << slider->getScaledValue() << endl;
	}


    else if(name == "Screen Name")
    {
        ofxUITextInput *textinput = (ofxUITextInput *) e.widget;
        if(textinput->getTriggerType() == OFX_UI_TEXTINPUT_ON_ENTER)
        {
            string output = textinput->getTextString();
            inputName = output;
            cout << output << endl;
        }
        else if(textinput->getTriggerType() == OFX_UI_TEXTINPUT_ON_FOCUS)
        {
            cout << "ON FOCUS: ";
        }
        else if(textinput->getTriggerType() == OFX_UI_TEXTINPUT_ON_UNFOCUS)
        {
            cout << "ON BLUR: ";
        }

    }
}
//--------------------------------------------------------------
void testApp::exit()
{
    delete gui;
}
//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
  
}

void testApp::GUI(){
    
    red = 100; blue = 100; green = 100;
	float dim = 24;
	float xInit = OFX_UI_GLOBAL_WIDGET_SPACING;
    float length = 320-xInit;
    yLoc = ofGetHeight()/2;
    speed = 10; //initial speed
    size = 50;// initial size of shape
    drawPadding = false;

    gui = new ofxUICanvas(0, 0, length+xInit, ofGetHeight()); // creates the gui canvas elements
    centerUI = (length+xInit)/2;
    buffer = new float[256];
    for(int i = 0; i < 256; i++) { buffer[i] = ofNoise(i/100.0); }
    inputName = "Your name";//text input
	gui->addWidgetDown(new ofxUILabel("Screen Name", OFX_UI_FONT_MEDIUM));
    gui->addSpacer(length-xInit, 1);
	gui->setWidgetFontSize(OFX_UI_FONT_LARGE);
	gui->addTextInput("Screen Name", inputName , length-xInit)->setAutoClear(false);
    gui->addWidgetDown(new ofxUILabel("Select Your Attributes", OFX_UI_FONT_MEDIUM));
    gui->addSpacer(length-xInit, 1);
    gui->addSlider("RED", 0.0, 255.0, red, length-xInit, dim);
    gui->addSlider("GREEN", 0.0, 255.0, green, length-xInit, dim);
    gui->addSlider("BLUE", 0.0, 255.0, blue, length-xInit, dim);
    gui->addSlider("SIZE", 0.0, 100.0, size, length-xInit, dim);
    gui->addSlider("SPEED", 0.0, 50.0, speed, length-xInit, dim);
    gui->addSpacer(length-xInit, 1);
    gui->addLabelButton("Enter", false);
    gui->addSpacer(length-xInit, 1);
    gui->setColorBack(ofColor(255,100));
	ofBackground(red, green, blue);
	ofAddListener(gui->newGUIEvent,this,&testApp::guiEvent);
}
//-------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y )
{

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button)
{
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h)
{
    
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 
    
}