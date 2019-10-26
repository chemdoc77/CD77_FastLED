/*
 
CD77_Halloween_Fun_2019 by Chemdoc77

Based by code from different sources.
See each tab for the sources.

*/

#include <FastLED.h>

#define LED_PIN 6
#define CHIPSET NEOPIXEL
#define NUM_LEDS 90

#define BRIGHTNESS 200


//Time Performance code

uint32_t gTimeCodeBase = 0;
uint32_t gTimeCode = 0;
uint32_t gLastTimeCodeDoneAt = 0;
uint32_t gLastTimeCodeDoneFrom = 0;
//=================

CRGB leds[NUM_LEDS];


//Fire2012withPalette stuff
CRGBPalette16 gPal;
#define FRAMES_PER_SECOND 60

bool gReverseDirection = false;



//========================


#include "Halloween_chase.h"
#include "Fire2012withPalette.h"
#include "Flicker.h"
#include "Time_performance.h"

void setup() {

delay(1000); // sanity delay
FastLED.addLeds<CHIPSET, LED_PIN>(leds, NUM_LEDS);
FastLED.setBrightness( BRIGHTNESS );

//Fire2012withPalette stuff
 gPal = HeatColors_p;
  

FastLED.setMaxPowerInVoltsAndMilliamps(5,7500);
 set_max_power_indicator_LED(13);
 fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.show();
  
//Time Performance code
   RestartPerformance();
 
}

//============================================
void loop() {  

 //Time Performance code
  gTimeCode = millis() - gTimeCodeBase;  
  Performance5();
}
