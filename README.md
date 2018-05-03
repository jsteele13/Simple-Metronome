# Metronome Application
This project is a simple openFrameworks **metronome** application. Similar to a traditional metronome, a user can enter a numeric tempo to hear the tempo as well as tap a tempo to read the numeric tempo. Additionally, the user can hear the pitch A (440 Hz) for tuning an instrument. 

## Getting Started
1) Download [openFrameworks](http://openframeworks.cc/)
2) Clone the openFrameworks addon [ofxDatGui](https://braitsch.github.io/ofxDatGui/) into the addons folder in openFrameworks: 
3) Run the openFrameworks [project generator](http://openframeworks.cc/learning/01_basics/create_a_new_project/) to generate the project with the ofxDatGui addon: 
4) Make the following changes to the source code from ofxDatGui:
    + Depending on your sceen size, the component height might need adjustment.  
        + *ofxDatGuiTheme.h - Line 178:* `float height = 45.0f;`  
    + Changes button events to activate on press instead of realease. 
        + *ofxDatGuiButton.h - Line 76:* `void onMousePress(ofPoint m)`  
        + *ofxDatGuiButton.h - Line 79:* `ofxDatGuiComponent::onMousePress(m);`
5) Copy the *data* folder in the project directory into the *bin* folder. This creates the correct filepaths for the program.
6) Ta-da! You're ready to go :)
      
## Running Tests

## Author
**Jennifer Steele** is a freshman student in Computer Science at the University of Illinois at Urbana-Champaign

## Acknowledgements
*Stephen Braitsch* - writing and maintaining the well-documented ofxDatGui library  
*MetroTimer iPhone App* - Stylistic and functional inspiration
