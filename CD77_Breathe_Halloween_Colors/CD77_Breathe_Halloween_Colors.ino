// This sketch by Chemdoc77 is based on Stuart Taylor's sketch, Breath.ino, at:
// https://gist.github.com/hsiboy/4eae11073e9d5b21eae3

#include <FastLED.h>
 // change these to match your hardware setup
 
#define LED_PIN 6   
#define NUM_LEDS 50
#define COLOR_ORDER RGB
#define LED_TYPE WS2811 //NEOPIXEL 
#define BRIGHTNESS 120                   // watch the power!
 
struct CRGB leds[NUM_LEDS];
CRGB Halloween_color2 = CRGB::Black;
void setup()
{
    LEDS.addLeds<LED_TYPE, LED_PIN>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
    FastLED.setBrightness(BRIGHTNESS);
    FastLED.clear();
   
}

void loop () {
  
CD77_Halloween_Colors_2 (4000);
CD77_breath();
 
FastLED.show();
  
}

//========================


void CD77_Halloween_Colors_2 (uint16_t wait_cc){

/* Based on code in This sketch is based on the following sketch from Adafruit:
 *  
https://learn.adafruit.com/random-spooky-led-eyes/assembly?view=all 

Random Eyes sketch for WS2801 pixels
W. Earl 10/16/11
For Adafruit Industries
*/

 int m_red2;  // RGB components of the color
  int m_green2;
  int m_blue2;




EVERY_N_MILLIS(wait_cc){
 // Pick a random color - skew toward red/orange/yellow part of the spectrum for extra creepyness
    m_red2 = random8(150, 255);
    m_blue2 = 0;
    m_green2 = random8(100);

    int r2 =  map(m_red2, 0, 255, 0, BRIGHTNESS);
    int g2 =  map(m_green2, 0, 255, 0, BRIGHTNESS);
    int b2 =  map(m_blue2, 0, 255, 0, BRIGHTNESS);
    
    Halloween_color2 = CRGB( r2, g2, b2);
    
 }
}
//===============================

// CD77_Halloween_Colors function is located in Halloween_Chase.h

void CD77_breath(){
  fill_solid(leds, NUM_LEDS, Halloween_color2 );
float breath =   (exp(sin(millis()/2400.0*PI)) - 0.36787944)*108.0;//(exp(sin(millis()/2000.0*PI)) - 0.36787944)*108.0;       //(exp(sin(millis()/4000.0*PI)) - 0.36787944)*108.0;//(exp(sin(millis()/2000.0*PI)) - 0.36787944)*108.0;

 float breath2 = map(breath, 0,255,0, BRIGHTNESS);
 FastLED.setBrightness(breath2);

}


