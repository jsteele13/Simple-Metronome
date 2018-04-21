#pragma once
#include <chrono>
#include "ofSoundPlayer.h"

#define LONG_SOUND_FILENAME "metronome_click.wav" // https://freesound.org/people/Druminfected/sounds/250551/
#define CLICK_LENGTH_NS 132000000
#define CLICK_SOUND_FILENAME "short_metronome_click.wav" 
#define SECOND_IN_MINUTE 60.0

class Metronome {
	public: 
		Metronome(); // tempo in bpm
		void tick();
		void set_tempo(int tempo);
		bool is_playing;

	private:
		ofSoundPlayer mySound;
		double wait_time;
		std::chrono::steady_clock::time_point last_tick_time;
};