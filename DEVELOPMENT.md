# Project Development

### Part 1 - Traditional Metronome 

**Ticking:** 
1. The first step to making traditional metronome functionality was to create a ticking sound at a constant speed. I downloaded a wood-block metronome click mp3 and shortened it from .601 seconds to .132 seconds so that the metronome could tick at faster speeds.
2. I first just tryed to play the sound in a loop, which would theoretically create an even beat. However, the sound played unevenly, so I wasn't sure that it would ever be able to play at an even beat, even with a timer. 
3. I decided to try it anyway before coming up with a different idea. I wrote some code using the Open Frameworks ofTimer documentation. However, the ofTimer required use of threading, which I couldn't get to work, even with very similar code to the example. Instead, I used the C++ chrono time library, since I only needed relatively simple timing capability. 

**User Input:**

**Flashing:**

### Part 2: Tempo Recognition
**User Input:**

**Measuring Speed:**

**Displaying Speed:**

### Part 3: Pitch Recognition
