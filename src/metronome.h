#pragma once
#include "ofThread.h"
#include "ofTimer.h"
#include "ofSoundPlayer.h"

#define CLICK_SOUND_FILENAME "short_metronome_click.wav"
#define LONG_SOUND_FILENAME "metronome_click.wav"
#define CLICK_LENGTH_NS 132000000

class Metronome : public ofThread {
	public: 
		Metronome(int tempo); // tempo in bpm

	private:
		ofTimer t;
		ofSoundPlayer myMetronome;

		void startTicking();
		void stopTicking();
};