#include "metronome.h"

// http://openframeworks.cc/learning/04_sound/play_a_sound/
// http://openframeworks.cc/documentation/utils/ofTimer/

Metronome::Metronome(int tempo) {
	myMetronome.load(CLICK_SOUND_FILENAME);

	int timeNano = (6 * pow(10, 10)) / tempo; //time in nanoseconds
	t.setPeriodicEvent(timeNano); 
	startThread();
}

void Metronome::startTicking() {
	while (isThreadRunning()) {
		myMetronome.play();
		t.waitNext();
	}
}

void Metronome::stopTicking() {
	stopThread();
}