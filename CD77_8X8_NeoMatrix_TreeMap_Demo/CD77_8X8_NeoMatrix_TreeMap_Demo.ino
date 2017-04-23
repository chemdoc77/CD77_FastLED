/*  NeoMatrx 8X8 Tree Map Demo by Chemdoc77

    Based on the tree mapping method and code by Jason Coon
    found at:

    https://www.evilgeniuslabs.org/tree-v2.html

    and 

    https://github.com/evilgeniuslabs/tree-v2  
 
 */

#include <FastLED.h>

#define DATA_PIN      6
#define LED_TYPE     NEOPIXEL 
#define NUM_LEDS      64


int brightness = 20;  // Adjust from 0 to 255 to set matrix brightness.



CRGB leds[NUM_LEDS];
CRGB solidColor = CRGB::Blue;

uint8_t patternIndex = 0;



// COOLING: How much does the air cool as it rises?
// Less cooling = taller flames.  More cooling = shorter flames.
// Default 50, suggested range 20-100
uint8_t cooling = 49;

// SPARKING: What chance (out of 255) is there that a new spark will be lit?
// Higher chance = more roaring fire.  Lower chance = more flickery fire.
// Default 120, suggested range 50-200.
uint8_t sparking = 60;

uint8_t speed = 50;


const uint8_t brightnessCount = 5;
uint8_t brightnessMap[brightnessCount] = { 16, 32, 64, 128, 255 };
uint8_t brightnessIndex = 0;
extern const TProgmemRGBGradientPalettePtr gGradientPalettes[];

uint8_t gCurrentPaletteNumber = 0;

CRGBPalette16 gCurrentPalette( CRGB::White);
CRGBPalette16 gTargetPalette( gGradientPalettes[0] );

CRGBPalette16 IceColors_p = CRGBPalette16(CRGB::Red/*CRGB::Black*/, CRGB::Blue, CRGB::Aqua, CRGB::White);

uint8_t currentPatternIndex = 0; // Index number of which pattern is current
uint8_t autoplay = 0;
uint8_t gHue = 0; 

//Time Performance code

uint32_t gTimeCodeBase = 0;
uint32_t gTimeCode = 0;
uint32_t gLastTimeCodeDoneAt = 0;
uint32_t gLastTimeCodeDoneFrom = 0;
//=================


#include "GradientPalettes.h"
#include "Tree_Map_8X8.h"
#include "functions.h"
#include "Time_performance.h"

void setup() {
 
  delay(2000);
  FastLED.addLeds<LED_TYPE, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setDither(false);
  FastLED.setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(brightness);
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 1000);
  set_max_power_indicator_LED(13);
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.show();
//Time Performance code
   RestartPerformance();
 //====================== 
}

void loop()  {

  gTimeCode = millis() - gTimeCodeBase;
  
  Performance();
  
}
