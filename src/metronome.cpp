#include "metronome.h"

// http://openframeworks.cc/learning/04_sound/play_a_sound/
// http://www.cplusplus.com/reference/chrono/steady_clock/

Metronome::Metronome(int tempo) {
	using namespace std::chrono;
	myMetronome.load(CLICK_SOUND_FILENAME);
	double waitTime = SECOND_IN_MINUTE / tempo; //time duration in milliseconds

	while (true) {
		steady_clock::time_point t1 = steady_clock::now();
		myMetronome.play();
		bool flag = false;
		while (!flag) {
			steady_clock::time_point t2 = steady_clock::now();
			if (duration_cast<duration<double>>(t2 - t1).count() >= waitTime) {
				flag = true;
			}
		}
	}
}


