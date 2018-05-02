#pragma once
#include <chrono>
#include "ofSoundPlayer.h"

#define LONG_SOUND_FILENAME "metronome_click.wav" // https://freesound.org/people/Druminfected/sounds/250551/
#define A440_FILENAME "A440.mp3"
#define CLICK_LENGTH_NS 132000000
#define CLICK_SOUND_FILENAME "short_metronome_click.wav" 
#define SECOND_IN_MINUTE 60.0


using namespace std::chrono;

class Metronome {
	public: 
		Metronome(); 

		void tick();
		void set_tempo(int tempo);
		bool is_playing;
		bool toggle();
		steady_clock::time_point get_tick_time();

		int tap();
		int get_num_taps();

		bool is_tuning();
		void toggle_tuning();

	private:
		ofSoundPlayer my_sound;
		ofSoundPlayer my_pitch;
		double wait_time;
		steady_clock::time_point tick_time;

		std::vector<int> last_3_tempos;
		steady_clock::time_point prev_click_time = steady_clock::now();
		int calc_average_tempo();
};