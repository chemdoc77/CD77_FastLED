//Custom Fibonacci 128 Fun by Chemdoc77

// Based on code:
//in Funkboxing by Teldredge 
//at http://funkboxing.com/wordpress/wp-content/_postfiles/sk_qLEDFX_POST.ino

// in color bar chase code by Richard Bailey 
//at https://gist.github.com/brencerddwr/85cc31227d2fcb0fc3818ab6a488c836

//in the Time Performance code by Mark Kriegsman
//at https://gist.github.com/kriegsman/a916be18d32ec675fea8
 

#include "FastLED.h"

#define NUM_LEDS 128 // for F128
#define Data_Pin 12

#define chipset NEOPIXEL 
#define BRIGHTNESS  100

 CRGB leds[NUM_LEDS];   

//Palette Code 
CRGBPalette16 currentPalette;
TBlendType    currentBlending;
extern const TProgmemRGBGradientPalettePtr gGradientPalettes[];

//Time Performance code

uint32_t gTimeCodeBase = 0;
uint32_t gTimeCode = 0;
uint32_t gLastTimeCodeDoneAt = 0;
uint32_t gLastTimeCodeDoneFrom = 0;

#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

#include "cd77_func1.h"
#include "PoliceOne.h"
#include "Time_performance.h"


void setup() { 
 delay(2000); // power-up safety delay 
 FastLED.addLeds<chipset, Data_Pin>(leds, NUM_LEDS); 
 FastLED.setBrightness(BRIGHTNESS);
 FastLED.setDither( 0 );
 FastLED.setMaxPowerInVoltsAndMilliamps(5,2500);
 set_max_power_indicator_LED(13);

 //Time Performance code
 RestartPerformance();
 

}


void loop(){
   gTimeCode = millis() - gTimeCodeBase;
   Performance();
}  
