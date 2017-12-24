// Chase Demo by Chemdoc77

// this sketch contains chase animation both for symmetrical and unsymmetrical chase animations

// Look at the READ_ME.h tab for further explanation of this sketch.

#include <FastLED.h>

#define LED_PIN 6  // change to D6 for WEMOS D1 Mini Pro
#define CHIPSET NEOPIXEL 
#define NUM_LEDS 110

#define BRIGHTNESS 60
CRGB leds[NUM_LEDS];
#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

//Time Performance code

uint32_t gTimeCodeBase = 0;
uint32_t gTimeCode = 0;
uint32_t gLastTimeCodeDoneAt = 0;
uint32_t gLastTimeCodeDoneFrom = 0;
//===========================================

#include "Chase.h"
#include "Time_performance.h"
  
void setup() {

delay(1000); // sanity delay
FastLED.addLeds<CHIPSET, LED_PIN>(leds, NUM_LEDS);
FastLED.setBrightness( BRIGHTNESS );
FastLED.setMaxPowerInVoltsAndMilliamps(5,1500);
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
  Performance();

}

