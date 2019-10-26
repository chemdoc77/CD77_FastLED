/*
 * CD77 Strobe by Chemdoc77
 * 
 * Includes code to automatically create 
 * CRGBSet Arrays code of 2,3,4 and 6 equal parts 
 * of a strip for any size strip.
 * 
 * 
 */
 
#include <FastLED.h>

#define LED_PIN 6
#define LED_TYPE    NEOPIXEL
#define NUM_LEDS 90      // Change to reflect the number of LEDs you have

int BRIGHTNESS = 100;

// ===Variables for CRGBSet Arrays  =====

uint16_t cs0_2 = 0;
uint16_t cs1_2 =(NUM_LEDS/2)-1;
uint16_t cs2_2 =NUM_LEDS-1;

uint16_t cs0_3 = 0;
uint16_t cs1_3 =(NUM_LEDS/3)-1;
uint16_t cs2_3 =(2*NUM_LEDS/3)-1;
uint16_t cs3_3 = NUM_LEDS-1;

uint16_t cs0_4 = 0;
uint16_t cs1_4 =(NUM_LEDS/4)-1;
uint16_t cs2_4 =(2*NUM_LEDS/4)-1;
uint16_t cs3_4 =(3*NUM_LEDS/4)-1;
uint16_t cs4_4 = NUM_LEDS-1;

uint16_t cs0_6 = 0;
uint16_t cs1_6 =(NUM_LEDS/6)-1;
uint16_t cs2_6 =(2*NUM_LEDS/6)-1;
uint16_t cs3_6 =(3*NUM_LEDS/6)-1;
uint16_t cs4_6 = (4*NUM_LEDS/6)-1;
uint16_t cs5_6 =(5*NUM_LEDS/6)-1;
uint16_t cs6_6 = NUM_LEDS-1;

//======= CRGBSet Arrays ==========================

//CRGB leds[NUM_LEDS];
CRGB rawleds[NUM_LEDS];
CRGBSet leds(rawleds, NUM_LEDS);



CRGBSet leds0_2(leds(cs0_2,cs1_2));
CRGBSet leds1_2(leds(cs1_2+1,cs2_2));


CRGBSet leds0_3(leds(cs0_3,cs1_3));
CRGBSet leds1_3(leds(cs1_3+1,cs2_3));
CRGBSet leds2_3(leds(cs2_3+1,cs3_3));


CRGBSet leds0_4(leds(cs0_4,cs1_4));
CRGBSet leds1_4(leds(cs1_4+1,cs2_4));
CRGBSet leds2_4(leds(cs2_4+1,cs3_4));
CRGBSet leds3_4(leds(cs3_4+1,cs4_4));


CRGBSet leds0_6(leds(cs0_6,cs1_6));
CRGBSet leds1_6(leds(cs1_6+1,cs2_6));
CRGBSet leds2_6(leds(cs2_6+1,cs3_6));
CRGBSet leds3_6(leds(cs3_6+1,cs4_6));
CRGBSet leds4_6(leds(cs4_6+1,cs5_6));
CRGBSet leds5_6(leds(cs5_6+1,cs6_6));


struct CRGB * ledarray_2[] ={leds0_2, leds1_2}; 
struct CRGB * ledarray_3[] ={leds0_3, leds1_3, leds2_3}; 
struct CRGB * ledarray_4[] ={leds0_4, leds1_4, leds2_4,leds3_4}; 
struct CRGB * ledarray_6[] ={leds0_6, leds1_6, leds2_6,leds3_6,leds4_6,leds5_6}; 
#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))


uint8_t Array_Size_2 = ARRAY_SIZE(ledarray_2);
uint8_t Array_Size_3 = ARRAY_SIZE(ledarray_3);
uint8_t Array_Size_4 = ARRAY_SIZE(ledarray_4);
uint8_t Array_Size_6 = ARRAY_SIZE(ledarray_6);


//=========== Time Performance code =====================

uint32_t gTimeCodeBase = 0;
uint32_t gTimeCode = 0;
uint32_t gLastTimeCodeDoneAt = 0;
uint32_t gLastTimeCodeDoneFrom = 0;
uint32_t gTimeCodeBase_sub = 0;
uint32_t gTimeCode_SECONDS=0;
uint32_t mysec =0;


//=========== #Include Tabs  =================

#include "Strobe.h"   
#include "Time_performance.h"   

//================================

void setup() {
  delay(1000);
  FastLED.addLeds<LED_TYPE, LED_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(  BRIGHTNESS );
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 1000);
  set_max_power_indicator_LED(13);
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.show();
  //Time Performance code
   RestartPerformance();
}


//=========================

void loop() {
  //Time Performance code
  gTimeCode = millis() - gTimeCodeBase;

  Performance();

}
