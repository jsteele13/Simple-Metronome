#include "metronome.h"

// http://openframeworks.cc/learning/04_sound/play_a_sound/
// http://www.cplusplus.com/reference/chrono/steady_clock/

	Metronome::Metronome() {
		mySound.load(CLICK_SOUND_FILENAME);
	}
	void Metronome::setTempo(int tempo) {
		waitTime = SECOND_IN_MINUTE / tempo; //time duration in milliseconds

	}

	void Metronome::tick() {
		using namespace std::chrono;
		if (isPlaying) {
			steady_clock::time_point t1 = steady_clock::now();
			mySound.play();

			bool waitDone = false;
			while (!waitDone) {
				steady_clock::time_point t2 = steady_clock::now();
				if (duration_cast<duration<double>>(t2 - t1).count() >= waitTime) {
					waitDone = true;
				}
			}
		}
	}

