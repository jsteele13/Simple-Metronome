#include "metronome.h"

// http://openframeworks.cc/learning/04_sound/play_a_sound/
// http://www.cplusplus.com/reference/chrono/steady_clock/


	Metronome::Metronome() {
		my_sound.load(CLICK_SOUND_FILENAME);
		my_pitch.load(A440_FILENAME);
		wait_time = 0;
	}
	void Metronome::set_tempo(int tempo) {
		wait_time = SECOND_IN_MINUTE / tempo; //time duration in milliseconds

	}

	void Metronome::tick() {
		if (is_playing) {
			steady_clock::time_point t2 = steady_clock::now();
			if (duration_cast<duration<double>>(t2 - tick_time).count() >= wait_time) {
				tick_time = steady_clock::now();
				my_sound.play();
			}
		}
	}
	steady_clock::time_point Metronome::get_tick_time() {
		return tick_time;
	}

	bool Metronome::toggle() {
		if (wait_time != 0) {
			is_playing = !is_playing;
			return true;
		}
		return false;
	}

	int Metronome::tap() {
		std::cout << last_3_tempos.size() << std::endl;
		steady_clock::time_point click_time = steady_clock::now();
		if (!is_playing) {
			my_sound.play();
		}
		double elapsed = duration_cast<duration<double>>(click_time - prev_click_time).count();
		double tempo = SECOND_IN_MINUTE / elapsed;
		prev_click_time = click_time;

		if (tempo < 40) {
			last_3_tempos.erase(last_3_tempos.begin(), last_3_tempos.end());
			return 0;
		}

		last_3_tempos.push_back(tempo);

		if (last_3_tempos.size() < 3) {
			return 0;
		}

		if (last_3_tempos.size() == 4) {
			last_3_tempos.erase(last_3_tempos.begin());
		}

		return std::round(calc_average_tempo());
	}


	int Metronome::calc_average_tempo() {
		double sum = 0;
		for (int i = 0; i < last_3_tempos.size(); i++) {
			sum += last_3_tempos[i];
		}
		return sum / last_3_tempos.size();
	}

	int Metronome::get_num_taps() {
		return last_3_tempos.size();
	}
	

	bool Metronome::is_tuning() {
		return my_pitch.isPlaying();
	}

	void Metronome::toggle_tuning() {
		if (is_tuning()) {
			my_pitch.stop();
		}
		else {
			my_pitch.play();
		}
	}

