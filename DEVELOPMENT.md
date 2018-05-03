# Project Development

### Part 1 - Traditional Metronome 

**Ticking:** 
1. The first step to making traditional metronome functionality was to create a ticking sound at a constant speed. I downloaded a wood-block metronome click mp3 and shortened it from .601 seconds to .132 seconds so that the metronome could tick at faster speeds.
2. I first just tryed to play the sound in a loop, which would theoretically create an even beat. However, the sound played unevenly, so I wasn't sure that it would ever be able to play at an even beat, even with a timer. 
3. I decided to try it anyway before coming up with a different idea. I wrote some code using the Open Frameworks ofTimer documentation. However, the ofTimer required use of threading, which I couldn't get to work, even with very similar code to the example. Instead, I used the C++ chrono time library, since I only needed relatively simple timing capability. 
4. This worked better (it didn't crash), but the beat was still uneven. I realized that the problem was the in my conversion from beats per minut to seconds per beat, there was an error with integer division. I was dividing two integers and expecting a double. After fixing this, the metronome beats evenly at any tempo.

**User Input:**
1. To make production of my appliction smoother, as well as to improve the appearance, I used an OpenFrameworks addon called [ofxDatGui](https://braitsch.github.io/ofxDatGui/). This library makes simple user input and ouput easy through customizable button, label, and textbox components.
2. I made a simple text input box for the user to control the tempo of the metronome, as well as a button to toggle on and off. 
3. Originally, I had trouble with the sizing of the gui. I had to create a custom text size as well as changing the component heights in the source code for ofxDatGui. 
4. To make the metronome more realistic, I limited the input to numbers, and implemented a minimum tempo of 40 and a maximum tempo of 220. If a tempo lower or higher is entered, it changes to the minimum or maximum.
5. I also fixed a couple of bugs by checking for empty inputs and resetting variables when nothing is entered so that the previous tempo isn't remembered if play is pressed with nothing in the input box.

**Flashing:**
1. To make a visual representation of the tempo, I simulated a "flash" by changing the background color of the power button to orange for the duration of the click sound. 
2. In the update function of ofApp, I turned changed the color to orange if within the right timeframe and otherwise set it back to the black.  
3. To fix a bug that it would stay orange if paused during the flash, I also turned it back to black in if the metronome was not currently playing.

### Part 2: Tempo Recognition
**User Interface:**
1. I used a button component from the ofxDatGui library again for the user to input a tempo. The user taps the button at their prefered tempo. After a couple clicks, the calculated tempo displays in a textbox. I added a click sound every time the button was pressed so it's easier for the user to hear what they're inputting. 
2. Another choice that I made was to make the click register when pressed not released. This makes it much easier to input a tempo. However, ofxDatGui doesn't have options for that like the ofxGui library. I went into the source code for the library and changed it manually so the button action would register on the press not the release.
3. To give the user multiple options for tapping, I made the space bar do the same thing as clicking the "tap button".
4. For extra ease of use, I made the tapped tempo appear in the metronome input textbox so that the user can play the tempo they just tapped right afterwards to check. I had a bug with this that the textbox didn't recognize this as input. So, I made a listener for the enter key and changed it then instead of in the textbox listener. 

**Measuring Speed:**
1. In the backend of the program, I calculated the click speed by storing the previous 3 click tempos and averaging them. I did this by saving the time of the previous click. To deal with the first few clicks, I returned a tempo of 0 until there were 3 tempos in the vector. Also, if a click registered at a tempo slower than 40, that meant that a new tempo was being started, so I cleared the vector.

### Part 3: Tuner
1. Originally I planned to use the ofxAudioAnalyzer addon to read in sound, but after a closer look I realized it's not compatible with windows. Since details of polishing the first 2 parts of the project took longer than anticipated, to add tuning functionalit I decided to output an "A" for the user to match pitch to rather than detecting an inputted pitch. This extended the application to be a simple tuner with the same type of skills as the previous parts of the project.  
