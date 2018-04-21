#include "metronome.h"

// http://openframeworks.cc/learning/04_sound/play_a_sound/
// http://www.cplusplus.com/reference/chrono/steady_clock/

	Metronome::Metronome() {
		mySound.load(CLICK_SOUND_FILENAME);
	}
	void Metronome::set_tempo(int tempo) {
		wait_time = SECOND_IN_MINUTE / tempo; //time duration in milliseconds

	}

	void Metronome::tick() {
		using namespace std::chrono;
		if (is_playing) {
			steady_clock::time_point t2 = steady_clock::now();
			if (duration_cast<duration<double>>(t2 - last_tick_time).count() >= wait_time) {
				last_tick_time = steady_clock::now();
				mySound.play();
			}
		}
	}

