#pragma once
#include <chrono>
#include "ofSoundPlayer.h"

#define CLICK_SOUND_FILENAME "short_metronome_click.wav"
#define LONG_SOUND_FILENAME "metronome_click.wav"
#define CLICK_LENGTH_NS 132000000

class Metronome {
	public: 
		Metronome(int tempo); // tempo in bpm

	private:
		ofSoundPlayer myMetronome;
};