#ifndef GLOBALS_H
#define GLOBALS_H

#include <Arduino.h>
#include <Arduboy2.h>
#include <ATMlib.h>
#include "bitmaps.h"
#include "font.h"

//define menu states (on main menu)
#define STATE_INTRO               0
#define STATE_DEMO                1

Arduboy2Base arduboy;
Sprites sprites;
ATMsynth ATM;

byte demoState = STATE_INTRO;   // start the game with the TEAM a.r.g. logo
byte globalCounter = 0;

#endif
