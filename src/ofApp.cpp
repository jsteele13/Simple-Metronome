#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(1920, 1080);
	ofSetWindowPosition(ofGetScreenWidth() / 2 - ofGetWidth() / 2, 0);
	ofSetBackgroundColor(0, 0, 0);

	// http://braitsch.github.io/ofxDatGui/components.html#text-inputs

	tempoInput = new ofxDatGuiTextInput("TEMPO (BPM)", "");
	tempoInput->onTextInputEvent(this, &ofApp::onTextInputEvent);
	tempoInput->setWidth(800, .2);
	tempoInput->setPosition(ofGetWidth() / 2 - tempoInput->getWidth() / 2, 240);

	/*ofxDatGuiInputType numbers;*/
	//ofxDatGuiInputType numbers (NUMERIC);
	//tempoInput->setInputType(NUMERIC);
	font.load("ofxbraitsch/fonts/Verdana.ttf", 24);

	Metronome myMetronome ();
}

//--------------------------------------------------------------
void ofApp::update(){
	tempoInput->update();
	if (myMetronome.isPlaying) {
		myMetronome.tick();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	tempoInput->draw();
}
//--------------------------------------------------------------
void ofApp::onTextInputEvent(ofxDatGuiTextInputEvent e) {
	std::cout << e.text << std::endl;
	myMetronome.setTempo(std::stoi(e.text));
	myMetronome.isPlaying = true;
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
