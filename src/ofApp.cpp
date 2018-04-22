#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetWindowShape(400, 500);
	ofSetWindowPosition(0, 0);
	ofSetBackgroundColor(0, 0, 0);

	// http://braitsch.github.io/ofxDatGui/components.html#text-inputs
	ofxDatGui* panel = new ofxDatGui(ofxDatGuiAnchor::TOP_LEFT);
	font.load("ofxbraitsch/fonts/Verdana.ttf", 24);

// PLAY TEMPO COMPONENTS
	tempo_input = panel->addTextInput("TEMPO (BPM)", "");
	tempo_input->onTextInputEvent(this, &ofApp::onTextInputEvent);
	tempo_input->setWidth(ofGetWidth(), .2);
	tempo_input->setInputType(ofxDatGuiInputType::NUMERIC);

	power_button = panel->addButton("PLAY");
	panel->onButtonEvent(this, &ofApp::onButtonEvent);

// CALCULATE TEMPO COMPONENTS
	tempo_tap = panel->addButton("TAP");
	tempo_tap->onButtonEvent(this, &ofApp::onButtonEvent);
	//tempo_tap->setWidth(ofGetWidth()/5);
		
	tempo_output = panel->addLabel("");
	
	Metronome myMetronome ();
}

//--------------------------------------------------------------
void ofApp::update(){
	tempo_input->update();
	if (my_metronome.is_playing) {
		tempo_input->setBackgroundColor(flash);
		my_metronome.tick();
		tempo_input->setBackgroundColor(original);
	}
	tempo_output->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	tempo_input->draw();
	tempo_output->draw();
}

//--------------------------------------------------------------
void ofApp::onTextInputEvent(ofxDatGuiTextInputEvent e) {
	std::cout << e.text << std::endl;
	my_metronome.set_tempo(std::stoi(e.text));
	if (!my_metronome.is_playing) {
		power_button->setLabel(my_metronome.toggle());
	}
}

//--------------------------------------------------------------
void ofApp::onButtonEvent(ofxDatGuiButtonEvent e)
{
	cout << e.target->getLabel() << " was clicked!" << endl;
	if (e.target == tempo_tap) {
		int tempo = my_metronome.tap();
		std::cout << tempo << std::endl;
		if (tempo == 0) {
			std::string click_marks = "";
			for (int i = 0; i < my_metronome.get_num_taps() + 1; i++) {
				click_marks += "-";
			}
			tempo_output->setLabel(click_marks);
		}
		else {
			tempo_output->setLabel(std::to_string(tempo));
		}
	}
	else {
		e.target->setLabel(my_metronome.toggle());
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
