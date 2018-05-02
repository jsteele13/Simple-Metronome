#pragma once

#include "ofMain.h"
#include "metronome.h"
#include "ofxDatGui.h"
#include <string>
#include <chrono>

#define FLASH_LENGTH .132
#define MIN_INPUT 40
#define MAX_INPUT 220


class ofApp : public ofBaseApp {

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
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

		ofxDatGuiTextInput* tempo_input;
		ofxDatGuiToggle* power_button;
		void play_tempo(std::string tempo);

		void draw_flash(ofxDatGuiComponent* comp);
		ofColor flash = ofColor(255, 102, 0);
		ofColor original = ofColor(0, 0, 0);

		ofxDatGuiButton* tempo_tap;
		void tapped();

		ofxDatGuiToggle* tuning_a;
		
		void onTextInputEvent(ofxDatGuiTextInputEvent e);
		void onButtonEvent(ofxDatGuiButtonEvent e);
		void onToggleEvent(ofxDatGuiToggleEvent e);
};

class ofxDatGuiCustomFontSize : public ofxDatGuiTheme {
public:

	ofxDatGuiCustomFontSize()
	{
		font.size = 12;
		init();
	}
};
