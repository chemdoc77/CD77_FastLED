#ifndef Flicker.h
#define Flicker.h
/*
 Flicker by Chemdoc77
 Based on code by u/locuester of Reddit
 https://www.reddit.com/r/FastLED/comments/diffut/flicker_effect/
*/

void CD77_flicker(CRGB color1, uint16_t Ran_min, uint16_t Ran_Max) {
  
  if (random8(2) == 1){
  for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = color1;
      }
   FastLED.show();
  }
    else {
      FastLED.clear();
      FastLED.show();
    }
    delay(random16(Ran_min,Ran_Max));
  }




#endif
