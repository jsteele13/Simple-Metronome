#pragma once
#include <chrono>
#include "ofSoundPlayer.h"

#define LONG_SOUND_FILENAME "metronome_click.wav" // https://freesound.org/people/Druminfected/sounds/250551/
#define CLICK_LENGTH_NS 132000000
#define CLICK_SOUND_FILENAME "short_metronome_click.wav" 
#define SECOND_IN_MINUTE 60.0

class Metronome {
	public: 
		Metronome(int tempo); // tempo in bpm
		void startTicking();

	private:
		ofSoundPlayer mySound;
		double waitTime;
};