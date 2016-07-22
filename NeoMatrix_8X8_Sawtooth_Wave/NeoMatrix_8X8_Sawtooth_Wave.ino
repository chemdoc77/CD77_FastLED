// Sawtooth Wave Sketch for 8X8 NeoMatrix by Chemdoc77

// The inspiration for the triwave8 code functions and the starting point for triwave8 code functions are from posts by Sean Clohesy on FastLED G+ Community 

// A lot of the code to change colors and the time performance code are by Mark Kriegsman of FastLED



#include "FastLED.h"
#if FASTLED_VERSION < 3001000
#error "Requires FastLED 3.1 or later; check github for latest code."
#endif

#define DATA_PIN    6
#define LED_TYPE    NEOPIXEL 
int x=0;
#define matrixwidth  8
#define matrixheight 8
#define NUM_LEDS    matrixwidth*matrixheight
CRGB leds[NUM_LEDS];

CRGBPalette16 currentPalette;
TBlendType    currentBlending;

//pre-declaration of functions
void RestartPerformance();
void Performance();
void cd77_matrix_sawtooth(uint16_t z, uint16_t hue, uint16_t deltahue, uint8_t wait );
void cd77_matrix_sawtooth_beatsin(uint16_t z, uint8_t beat,  uint8_t c1, uint8_t c2, uint8_t wait );
void cd77_matrix_sawtooth_palette(uint16_t z, uint8_t colorIndex, uint8_t deltacolorIndex, uint8_t wait );
void cd77_matrix_sawtooth_r90(uint16_t z, uint8_t hue, uint8_t deltahue, uint8_t wait );
void cd77_matrix_sawtooth_beatsin_r90(uint16_t z, uint8_t beat,  uint8_t c1, uint8_t c2, uint8_t wait );
void cd77_matrix_sawtooth_palette_r90(uint16_t z, uint8_t colorIndex, uint8_t deltacolorIndex, uint8_t wait );


//=======================================
void setup() {
  delay(2000); // 2 second delay for recovery
  
  // tell FastLED about the LED strip configuration
  FastLED.addLeds<LED_TYPE, DATA_PIN>(leds, NUM_LEDS);  
  
  // set master brightness control
  FastLED.setBrightness(30);
  
  RestartPerformance();
  
}

//=====================palettes=================

const TProgmemPalette16 test_PaletteRWB3_p PROGMEM =
{
  CRGB::Red,
  CRGB::Red,  
  CRGB::Red,
  CRGB::Red,
  
  CRGB::Grey,  
  CRGB::Grey,
  CRGB::Grey,
  CRGB::Grey,
  
  CRGB::Blue,
  CRGB::Blue, 
  CRGB::Blue,
  CRGB::Blue, 
  
  CRGB::Red,
  CRGB::Red,  
  CRGB::Blue,
  CRGB::Blue 
};  




//=================time performance code=======================
 // By Mark Kriegsman of FastLED
  
  
uint32_t gTimeCodeBase = 0;
uint32_t gTimeCode = 0;
uint32_t gLastTimeCodeDoneAt = 0;
uint32_t gLastTimeCodeDoneFrom = 0;

#define TC(HOURS,MINUTES,SECONDS) \
  ((uint32_t)(((uint32_t)((HOURS)*(uint32_t)(3600000))) + \
  ((uint32_t)((MINUTES)*(uint32_t)(60000))) + \
  ((uint32_t)((SECONDS)*(uint32_t)(1000)))))


#define AT(HOURS,MINUTES,SECONDS) if( atTC(TC(HOURS,MINUTES,SECONDS)) )
#define FROM(HOURS,MINUTES,SECONDS) if( fromTC(TC(HOURS,MINUTES,SECONDS)) )

static bool atTC( uint32_t tc)
{
  bool maybe = false;
  if( gTimeCode >= tc) {
    if( gLastTimeCodeDoneAt < tc) {
      maybe = true;
      gLastTimeCodeDoneAt = tc;
    }
  }
  return maybe;
}

static bool fromTC( uint32_t tc)
{
  bool maybe = false;
  if( gTimeCode >= tc) {
    if( gLastTimeCodeDoneFrom <= tc) {
      maybe = true;
      gLastTimeCodeDoneFrom = tc;
    }
  }
  return maybe;
}

// There are two kinds of things you can put into this performance:
// "FROM" and "AT".
//
// * "FROM" means starting FROM this time AND CALLING IT REPEATEDLY 
//   until the next "FROM" time comes.
//
// * "AT" means do this ONE TIME ONLY "AT" the designated time.


void Performance()
{
  FROM(0,0,0.01)     { cd77_matrix_sawtooth(3, 0, 60, 7); }
  FROM(0,0,7.00)     { cd77_matrix_sawtooth_beatsin(3, 20,  0,  160, 7);  }
  FROM(0,0,14.000)   { cd77_matrix_sawtooth_palette(3, 0, 24, 7); currentPalette = RainbowColors_p; currentBlending = NOBLEND;}
  FROM(0,0,21.000)   { cd77_matrix_sawtooth_palette(3, 0, 24, 7); currentPalette = test_PaletteRWB3_p;  currentBlending = NOBLEND;}
  //rotate sawtooth wave 90 degrees
  FROM(0,0,28.000)   { cd77_matrix_sawtooth_r90(3, 0, 60, 7);}
  FROM(0,0,35.000)   { cd77_matrix_sawtooth_beatsin_r90(3, 20,  0,  160, 7);}
  FROM(0,0,42.000)   { cd77_matrix_sawtooth_palette_r90(3, 0, 24, 7); currentPalette = RainbowColors_p;  currentBlending = NOBLEND;}
  FROM(0,0,49.000)   { cd77_matrix_sawtooth_palette_r90(3, 0, 24, 7); currentPalette = test_PaletteRWB3_p/*RainbowColors_p*/; currentBlending = NOBLEND;}
  AT(0,0,56.000)     { RestartPerformance(); }
}

//=== array for rotating sawtooth ==================

uint8_t array1[]={0, 8, 16, 24, 32, 40, 48, 56,
                  1, 9, 17, 25, 33, 41, 49, 57,
                  2, 10, 18, 26, 34, 42, 50, 58,
                  3, 11, 19, 27, 35, 43, 51, 59,
                  4, 12, 20, 28, 36, 44, 52, 60,
                  5, 13, 21, 29, 37, 45, 53, 61,
                  6, 14, 22, 30, 38, 46, 54, 62,
                  7, 15, 23, 31, 39, 47, 55, 63};

//==================================
void loop()
{
  // Set the current timecode, based on when the performance started
  gTimeCode = millis() - gTimeCodeBase;

  Performance();
}

//==============================
//Functions

void RestartPerformance()
{
  gLastTimeCodeDoneAt = 0;
  gLastTimeCodeDoneFrom = 0;
  gTimeCodeBase = millis();
}

//===============================
//The following functions have the sawtooth wave going from bottom to top

void cd77_matrix_sawtooth(uint16_t z, uint16_t hue, uint16_t deltahue, uint8_t wait ){
                                          // first number - increase to make decrease sawtooth wavelength  
                                          // second number to set inital color, 
                                          // third number to adjust change in color
                                          // last number changes the speed   
  
  fadeToBlackBy( leds, NUM_LEDS, 150);
  for (uint16_t width =0; width< matrixwidth; width++){
  leds[(NUM_LEDS-1)-((triwave8(x+(width*10*z))/32)*matrixwidth+width)] = CHSV(hue,255,255);
  hue+=deltahue;
  
   }  
   FastLED.show();
    FastLED.delay(wait); //use along with next line to get desired speed
   x=x+2;//change 2 to higher number to make go faster
}

//===================================

void cd77_matrix_sawtooth_beatsin(uint16_t z, uint8_t beat,  uint8_t c1, uint8_t c2, uint8_t wait ){
                                         // first number - increase to make decrease sawtooth wavelength  
                                          // second number use to set rate of color change
                                          // third number use to set starting color 
                                          // fourth number use to set end of the color range 
                                          // last number changes the speed 
 
   fadeToBlackBy( leds, NUM_LEDS, 150);
  for (uint16_t width =0; width< matrixwidth; width++){
    uint8_t hue = beatsin16(beat,c1,c2);
  leds[(NUM_LEDS-1)-((triwave8(x+(width*10*z))/32)*matrixwidth+width)] = CHSV(hue,255,255);
  
  
   }  
   FastLED.show();
    FastLED.delay(wait); //use along with next line to get desired speed
   x=x+2;//change 2 to higher number to make go faster
}


//===================================

void cd77_matrix_sawtooth_palette(uint16_t z, uint8_t colorIndex, uint8_t deltacolorIndex, uint8_t wait ){
                                          // first number - increase to make decrease sine wavelength  
                                          // second number to set the colorIndex, 
                                          // third number to set rate of change in the colorIndex 
                                          // last number changes the speed  
  
  fadeToBlackBy( leds, NUM_LEDS, 150);
  for (uint16_t width =0; width< matrixheight; width++){
   
  leds[(NUM_LEDS-1)-((triwave8(x+(width*10*z))/32)*matrixwidth+width)] = ColorFromPalette( currentPalette, colorIndex+triwave8(x), 255, currentBlending);
  
   colorIndex += deltacolorIndex;
   }  
   FastLED.show();
    FastLED.delay(wait); //use along with next line to get desired speed
   x=x+2;//change 2 to higher number to make go faster
}

//===================================
//The following functions have the sawtooth wave going from left to right

void cd77_matrix_sawtooth_r90(uint16_t z, uint8_t hue, uint8_t deltahue, uint8_t wait ){
                                          // first number - increase to make decrease sawtooth wavelength  
                                          // second number to set inital color, 
                                          // third number to adjust change in color
                                          // last number changes the speed   
  
  fadeToBlackBy( leds, NUM_LEDS, 150);
  for (uint16_t width =0; width<matrixwidth; width++){
  leds[array1[(NUM_LEDS-1)-((triwave8(x+(width*10*z))/32)*matrixwidth+width)]] = CHSV(hue,255,255);
  hue+=deltahue;
  
   }  
   FastLED.show();
    FastLED.delay(wait); //use along with next line to get desired speed
   x=x+2;//change 2 to higher number to make go faster
}

//========================================

void cd77_matrix_sawtooth_beatsin_r90(uint16_t z, uint8_t beat,  uint8_t c1, uint8_t c2, uint8_t wait ){
                                          // first number - increase to make decrease sawtooth wavelength  
                                          // second number use set rate of color change
                                          // third number use to set starting color 
                                          // fourth number use to set end of the color range
                                          // last number changes the speed 
 
  fadeToBlackBy( leds, NUM_LEDS, 150);
  for (uint16_t width =0; width< matrixwidth; width++){
    uint8_t hue = beatsin16(beat,c1,c2);
  leds[array1[(NUM_LEDS-1)-((triwave8(x+(width*10*z))/32)*matrixwidth+width)]] = CHSV(hue,255,255);
  
  
   }  
   FastLED.show();
    FastLED.delay(wait); //use along with next line to get desired speed
   x=x+2;//change 2 to higher number to make go faster
}

//==========================================

void cd77_matrix_sawtooth_palette_r90(uint16_t z, uint8_t colorIndex, uint8_t deltacolorIndex, uint8_t wait ){
                                          // first number - increase to make decrease sawtooth wavelength  
                                          // second number to set the colorIndex, 
                                          // thirdt number to set rate of change in the colorIndex
                                          // last number changes the speed   
  
  fadeToBlackBy( leds, NUM_LEDS, 150);
  for (uint16_t width =0; width< matrixwidth; width++){
   
  leds[array1[(NUM_LEDS-1)-((triwave8(x+(width*10*z))/32)*matrixwidth+width)]] = ColorFromPalette( currentPalette, colorIndex+triwave8(x), 255, currentBlending);
  
   colorIndex += deltacolorIndex;
   }  
   FastLED.show();
    FastLED.delay(wait); //use along with next line to get desired speed
   x=x+2;//change 2 to higher number to make go faster
}








