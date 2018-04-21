#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetWindowShape(400, 500);
	ofSetWindowPosition(0, 0);
	ofSetBackgroundColor(0, 0, 0);

	// http://braitsch.github.io/ofxDatGui/components.html#text-inputs
	ofxDatGui* panel = new ofxDatGui(ofxDatGuiAnchor::TOP_LEFT);

	// METRONOME
	tempo_input = panel->addTextInput("TEMPO (BPM)", "");
	tempo_input->onTextInputEvent(this, &ofApp::onTextInputEvent);
	tempo_input->setWidth(ofGetWidth(), .2);
	//tempoInput->setPosition(ofGetWidth() / 2 - tempoInput->getWidth() / 2, 240);
	tempo_input->setInputType(ofxDatGuiInputType::NUMERIC);
	font.load("ofxbraitsch/fonts/Verdana.ttf", 24);

	tempo_tap = panel->addButton("TAP");
	tempo_tap->onButtonEvent(this, &ofApp::onButtonEvent);
	tempo_output = panel->addLabel("");
	
	Metronome myMetronome ();



}

//--------------------------------------------------------------
void ofApp::update(){
	tempo_input->update();
	if (my_metronome.is_playing) {
		my_metronome.tick();
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
	my_metronome.is_playing = true;
}

//--------------------------------------------------------------
void ofApp::onButtonEvent(ofxDatGuiButtonEvent e)
{
	cout << e.target->getLabel() << " was clicked!" << endl;
	int tempo = my_metronome.tap();
	if (tempo == 0) {
		tempo_output->setLabel(tempo_output->getLabel() + "-");
	}
	else {
		tempo_output->setLabel("" + tempo);
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
