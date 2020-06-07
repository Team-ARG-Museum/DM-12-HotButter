#ifndef DEMO_H
#define DEMO_H

#include <Arduino.h>
#include "globals.h"

const unsigned char PROGMEM demoText[] = "Hello again from TEAM a.r.g. to all Arduboy fans out there               Thanks to Scotty for the image.               Also many thanks to Jo for helping with the ATM editor.               A big HI to STG, the brains behind the chiptune library !               Still enjoying Hot Butter are you ?               We'll be back soon with some cool new games, so stay tuned :)";
int scrolling = 128;
int timeDemo;

void drawScrollingText()
{
  if (arduboy.everyXFrames(1)) scrolling--;
  for (int textX = 0; textX < sizeof(demoText) - 1; textX++)
  {
    if ((scrolling + 14 * textX < 128) && (scrolling + 14 * textX > -32))
    {
      sprites.drawPlusMask(scrolling + 14 * textX, 2, font_plus_mask, pgm_read_byte(&demoText[textX]) - 32);
    }
  }
}

void demoIntro()
{
  globalCounter++;
  sprites.drawSelfMasked(34, 4, T_arg, 0);
  if (globalCounter > 180) demoState = STATE_DEMO;
};

void demoPlay()
{
  sprites.drawSelfMasked(0, 0, ATMlib, 0);
  drawScrollingText();
}





#endif
