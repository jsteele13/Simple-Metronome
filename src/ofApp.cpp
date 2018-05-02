#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	//ofSetWindowShape(400, 500);
	ofSetWindowShape(275, 225);
	//ofSetWindowShape(1920, 1080);
	ofSetWindowPosition(0, 0);
	ofSetBackgroundColor(0, 0, 0);

// http://braitsch.github.io/ofxDatGui/components.html
	ofxDatGui* panel = new ofxDatGui(ofxDatGuiAnchor::TOP_LEFT);
	font.load("ofxbraitsch/fonts/Verdana.ttf", 24);
	//font.load("ofxbraitsch/fonts/Verdana.ttf", 120);
	panel->setTheme(new ofxDatGuiCustomFontSize());

// PLAY TEMPO COMPONENTS
	power_button = panel->addToggle("POWER");
	power_button->onToggleEvent(this, &ofApp::onToggleEvent);

	tempo_input = panel->addTextInput("TEMPO", "");
	tempo_input->onTextInputEvent(this, &ofApp::onTextInputEvent);
	tempo_input->setWidth(ofGetWidth(), .2);
	tempo_input->setInputType(ofxDatGuiInputType::NUMERIC);

// CALCULATE TEMPO COMPONENTS
	tempo_tap = panel->addButton("TAP");
	tempo_tap->onButtonEvent(this, &ofApp::onButtonEvent);

// TUNING COMPONENTS
	tuning_a = panel->addToggle("A 440");
	tuning_a->onToggleEvent(this, &ofApp::onToggleEvent);
	
	Metronome myMetronome ();
}

//--------------------------------------------------------------
void ofApp::update(){
	tempo_input->update();
	if (my_metronome.is_playing) {
		draw_flash(power_button);
		my_metronome.tick();
	}
	if (!my_metronome.is_playing) {
		power_button->setBackgroundColor(original);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	tempo_input->draw();
}

//--------------------------------------------------------------
void ofApp::draw_flash(ofxDatGuiComponent* comp) {
	steady_clock::time_point t2 = steady_clock::now();
	if (duration_cast<duration<double>>(t2 - my_metronome.get_tick_time()).count() <= FLASH_LENGTH) {
		comp->setBackgroundColor(flash);
	}
	else {
		comp->setBackgroundColor(original);
	}
}

//--------------------------------------------------------------
void ofApp::onTextInputEvent(ofxDatGuiTextInputEvent e) {
	std::cout << e.text << std::endl;
	play_tempo(e.text);
}

void ofApp::play_tempo(std::string tempo) {
	if (tempo != "") {
		int input = std::stoi(tempo);
		if (input < MIN_INPUT) {
			tempo_input->setText(std::to_string(MIN_INPUT));
			my_metronome.set_tempo(MIN_INPUT);
		}
		else if (input > MAX_INPUT) {
			tempo_input->setText(std::to_string(MAX_INPUT));
			my_metronome.set_tempo(MAX_INPUT);
		}
		else {
			my_metronome.set_tempo(input);
		}
	}
	else {
		my_metronome.set_tempo(0);
	}

	if (!my_metronome.is_playing) {
		my_metronome.toggle();
		power_button->setChecked(true);
	}
}
//--------------------------------------------------------------
void ofApp::onButtonEvent(ofxDatGuiButtonEvent e)
{
	cout << e.target->getLabel() << " was clicked!" << endl;
	tapped();
}

void ofApp::tapped() {
	if (my_metronome.is_playing) {
		my_metronome.toggle();
		power_button->setChecked(false);
	}
	int tempo = my_metronome.tap();
	std::cout << tempo << std::endl;
	if (tempo == 0) {
		std::string click_marks = "";
		for (int i = 0; i < my_metronome.get_num_taps() + 1; i++) {
			click_marks += "-";
		}
		tempo_input->setText(click_marks);
	}
	else {
		tempo_input->setText(std::to_string(tempo));
		my_metronome.set_tempo(tempo);
	}
}

//--------------------------------------------------------------

void ofApp::onToggleEvent(ofxDatGuiToggleEvent e)
{
	cout << e.target->getLabel() << " checked = " << e.checked << endl;
	if (e.target == power_button) {
		bool toggled = my_metronome.toggle();
		if (!toggled) {
			power_button->setChecked(false);
		}
	}
	else if (e.target == tuning_a) {
		my_metronome.toggle_tuning();
	}
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == ' ') {
		tapped();
	}
	else if (key == OF_KEY_RETURN) {
		play_tempo(tempo_input->getText());
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
