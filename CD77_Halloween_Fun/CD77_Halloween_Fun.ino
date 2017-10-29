/*
CD77_Halloween_Fun by Chemdoc77

Based by code from different sources.
See each tab for the sources.
*/

#include <FastLED.h>

#define LED_PIN 6
#define CHIPSET WS2811 //NEOPIXEL
#define NUM_LEDS 50

#define BRIGHTNESS 160
#define BRIGHTNESS_breath 100

//Time Performance code

uint32_t gTimeCodeBase = 0;
uint32_t gTimeCode = 0;
uint32_t gLastTimeCodeDoneAt = 0;
uint32_t gLastTimeCodeDoneFrom = 0;
//=================

CRGB leds[NUM_LEDS];

#include "Halloween_chase.h"
#include "Halloween_breath.h"
#include "Spooky_eyes.h"
#include "Time_performance.h"

void setup() {

delay(1000); // sanity delay
FastLED.addLeds<CHIPSET, LED_PIN>(leds, NUM_LEDS);
FastLED.setBrightness( BRIGHTNESS );
FastLED.setMaxPowerInVoltsAndMilliamps(5,500);
 set_max_power_indicator_LED(13);
 fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.show();
//Time Performance code
   RestartPerformance();
 //====================== 

//Spooky Eyes code

countdown = 0;

//==================

 
}

//============================================
void loop() {
 //Time Performance code
  gTimeCode = millis() - gTimeCodeBase;  
  Performance();
}


