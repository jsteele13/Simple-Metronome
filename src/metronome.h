#pragma once
#include <chrono>
#include "ofSoundPlayer.h"

#define A440_FILENAME "A440.mp3"
#define CLICK_SOUND_FILENAME "short_metronome_click.wav" // https://freesound.org/people/Druminfected/sounds/250551/
#define SECOND_IN_MINUTE 60.0
#define NUM_TAPS 3
#define MIN_TEMPO 40
#define MAX_TEMPO 220

using namespace std::chrono;

class Metronome {
	public: 
		Metronome(); 

	// PLAY TEMPO 
		void tick();
		bool toggle();
		void set_tempo(int tempo);
		bool get_is_playing();
		steady_clock::time_point get_tick_time();

	// TAP TEMPO
		int tap();
		int get_num_taps();

	// TUNING
		void toggle_tuning();
		bool is_tuning();

	private:
	// PLAY TEMPO 
		ofSoundPlayer my_sound;
		bool is_playing;
		double wait_time;
		steady_clock::time_point tick_time;

	// TAP TEMPO
		std::vector<int> last_tempos;
		steady_clock::time_point prev_click_time = steady_clock::now();
		int calc_average_tempo();

	// TUNING
		ofSoundPlayer my_pitch;
};