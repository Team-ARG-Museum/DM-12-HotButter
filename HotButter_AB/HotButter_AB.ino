/*
  DEMO: HotButter

  MADE by TEAM a.r.g. : http://www.team-arg.org/demos.html

  2017 - JO3RI

  License: MIT : https://opensource.org/licenses/MIT

*/

//determine the demo
#define DEMO_ID 12

#include "globals.h"
#include "demo.h"
#include "song.h"


typedef void (*FunctionPointer) ();

const FunctionPointer PROGMEM mainDemoLoop[] = {
  demoIntro,
  demoPlay,
};

void setup() {
  arduboy.begin();
  // set the framerate of the game at 60 fps
  arduboy.setFrameRate(60);
  // let's make sure the sound was not muted in a previous sketch
  arduboy.audio.on();
  // Initializes ATMSynth and samplerate
  // Begin playback of song.
  ATM.play(popcorn);
}

void loop() {

  if (!(arduboy.nextFrame())) return;
  arduboy.pollButtons();
  arduboy.clear();
  ((FunctionPointer) pgm_read_word (&mainDemoLoop[demoState]))();
  if (arduboy.justPressed(B_BUTTON)) ATM.playPause();
  if (arduboy.justPressed(A_BUTTON)) ATM.playPause();
  arduboy.display();
}
