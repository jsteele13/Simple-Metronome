#pragma once

#include "ofMain.h"
#include "metronome.h"
#include "ofxDatGui.h"
#include <string>
#include <chrono>

#define FLASH_LENGTH .132
#define FONT_SIZE 12

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

private:
	ofTrueTypeFont font;
	Metronome my_metronome;

	// PLAY TEMPO
	ofxDatGuiTextInput* tempo_input; // textbox for specification of numeric tempo
	ofxDatGuiToggle* power_button; // toggle button for user to turn metronome on and off
	void play_tempo(std::string tempo);  // plays metronome at tempo

// FLASHING
	void draw_flash(ofxDatGuiComponent* comp); // changes background color depending on time since last click
	ofColor flash = ofColor(255, 102, 0); // orange flash color
	ofColor original = ofColor(0, 0, 0); // original black background color

// TAP TEMPO
	ofxDatGuiButton* tempo_tap; // button component for user to tap tempo
	void tapped(); // called after a tap, calculates then displays dashes dashes or tempo

// TUNE
	ofxDatGuiToggle* tuning_a; // toggle button to turn on and off the tuning A

	void onTextInputEvent(ofxDatGuiTextInputEvent e);
	void onButtonEvent(ofxDatGuiButtonEvent e);
	void onToggleEvent(ofxDatGuiToggleEvent e);
};

// changes font size to custom setting
// https://github.com/braitsch/ofxDatGui/issues/75
class ofxDatGuiCustomFontSize : public ofxDatGuiTheme {
public:

	ofxDatGuiCustomFontSize()
	{
		font.size = FONT_SIZE;
		init();
	}
};
