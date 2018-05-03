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
		void tick(); // plays tick sound if appropriate time
		bool toggle(); // toggles metronome ticking
		void set_tempo(int tempo); // sets speed of metronome ticking - takes tempo param in bpm
		bool get_is_playing(); // accessor for bool is_playing 
		steady_clock::time_point get_tick_time();  // accessor for time of previous tick

	// TAP TEMPO
		int tap(); // called after a tap, records data
		int get_num_taps(); // accessor for number of taps recorded in last_tempos

	// TUNING
		void toggle_tuning(); // toggle tuning A
		bool is_tuning(); // returns true if A is being played, false otherwise

	private:
	// PLAY TEMPO 
		ofSoundPlayer my_click; // soundplayer for metronome click
		bool is_playing; // true if metronome on, false if not
		double wait_time; // time to wait between clicks in seconds 
		steady_clock::time_point tick_time; // start time of previous tick 

	// TAP TEMPO
		std::vector<int> last_tempos; // stores the tempos in beats per minute of the last n (NUM_TAPS) taps
		steady_clock::time_point prev_click_time; // start time of previous tap
		int calc_average_tempo(); // calculates average of tempos in last_tempos

	// TUNING
		ofSoundPlayer my_pitch; // soundplayer for tuning A
};